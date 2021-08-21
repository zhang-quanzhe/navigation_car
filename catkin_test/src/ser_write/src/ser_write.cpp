#include <stdio.h>
#include <string.h>
#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/package.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>	//数据格式
#include <serial/serial.h>		//ros串口
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <fstream>
#include <iostream>

#include <geometry_msgs/Pose2D.h>

using namespace std;

typedef double float64;
// typedef unsigned char uint8_t;

serial::Serial ser;			//定义一个串口对象
ros::Subscriber serial_sub;		//订阅位姿节点
// ros::Publisher read_pub;

typedef union{				//定义一个联合体，用于double数据与16进制的转换
unsigned char cvalue[4];
float fvalue;
}float_union;

static uint8_t s_buffer[60];	//分配静态存储空间 60个0xAA
static uint8_t s0_buffer[1];
static uint8_t s1_buffer[1];
static uint8_t s2_buffer[32];
static uint8_t s3_buffer[24];
static uint8_t s4_buffer[1];
static uint8_t s5_buffer[1];
struct _slam2IMU
{
	//uint8_t head1,head2;
	double q[4];
	double pos[3];
	//uint8_t crc;
	//uint8_t end1;
	
}slam2IMU;

uint8_t head1,head2;
uint8_t crc;
uint8_t end1;

union HEXDOUBLE
{
double dNum;
unsigned char iNum[8];
};

union HEXDOUBLE a0,a1,a2,a3,a4,a5,a6;
// union 

void serial_sub_callback(const geometry_msgs::Pose2D::ConstPtr& msg)
{
	double x;
	double y;
	
	x=msg->x; y=msg->y;
 	
	uint8_t crc=0;
	head1 = 0xAA;
	head2 = 0x55;
	for(uint8_t i=0;i<4;i++)
		slam2IMU.q[i]=0;
	slam2IMU.q[0]=1.0;
	slam2IMU.q[1]=0;
	slam2IMU.q[2]=0;
	slam2IMU.q[3]=0;
	slam2IMU.pos[0]=x;
	slam2IMU.pos[1]=y;
	slam2IMU.pos[2]=2.5;
	// float_union linear_x,angular_z;
	// memset(s_buffer,0,sizeof(s_buffer));		//内存空间初始化为0
    // linear_x.fvalue = msg->linear.x;
    // angular_z.fvalue = msg->angular.z;
	//数据打包 
	
	end1 = 0x00;
	s_buffer[0] = head1;
	s_buffer[1] = head2;
    memcpy(&s_buffer[2],&slam2IMU,sizeof(slam2IMU));

	for(int i=2;i<58;i++)
	{
		crc+=s_buffer[i];
	}

	s_buffer[58]=crc;
	s_buffer[59]=end1;

    // uint8_t tmp;

    for(int i=0;i<60;i++)
	{
		printf("send data: %d----%x\n", i,s_buffer[i]);
	}

	// memcpy(s0_buffer,&slam2IMU.head1,sizeof(slam2IMU.head1));
	// memcpy(s1_buffer,&slam2IMU.head2,sizeof(slam2IMU.head2));
	// memcpy(s2_buffer,&slam2IMU.q[0],32);
	// memcpy(s3_buffer,&slam2IMU.pos[0],24);
	// memcpy(s4_buffer,&slam2IMU.crc,sizeof(slam2IMU.crc));
	// memcpy(s5_buffer,&slam2IMU.end1,sizeof(slam2IMU.end1));

	ser.write(s_buffer,60);
	ROS_INFO("data send successful: x=%f, y=%f", msg->x,msg->y);
}

//欧拉角转四元数
double *mod(double roll, double pitch, double yaw) 
{
	double cy,sy,cp,sp,cr,sr;
	double w,x,y,z;

	cy = cos(yaw * 0.5);
    sy = sin(yaw * 0.5);
    cp = cos(pitch * 0.5);
    sp = sin(pitch * 0.5);
    cr = cos(roll * 0.5);
    sr = sin(roll * 0.5);

	w = cy * cp * cr + sy * sp * sr;
    x = cy * cp * sr - sy * sp * cr;
    y = sy * cp * sr + cy * sp * cr;
    z = sy * cp * cr - cy * sp * sr;

	double *r = new double;
 
	r[0] = w;
	r[1] = x;
	r[2] = y;
	r[3] = z;

	return r;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "serial_node");		//ROS串口节点名称

	ros::NodeHandle my_node;

	serial_sub = my_node.subscribe("/pose2D", 1000, serial_sub_callback); //这里订阅一个写数据的话题，用于接收数据并进行发送。
	// read_pub =  my_node.advertise<std_msgs::String>("read", 1000);

	// while(1)
	// {
	// 	short int x;
	// char x0,x1;
	// x=0x1122;
	// x0=((char*)&x)[0];  //低地址单元
	// x1=((char*)&x)[1];  //高地址单元
	// printf("%x\n",x0 );
	// }   小端：数据低位在低地址,测试大端小端


	try
	{
	//设置串口属性，并打开串口
		ser.setPort("/dev/ttyUSB0");
		ser.setBaudrate(115200);		//波特率115200
		serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
	}
	catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }

    if(ser.isOpen())
    {
        ROS_INFO_STREAM("Serial Port opened");
    }
    else
    {
        return -1;
    }

	//指定循环的速率
	ros::Rate loop_rate(50);
	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
    ser.close();
	return 0;
}




