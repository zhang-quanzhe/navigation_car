#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Vector3Stamped.h"
#include <sbgEComLib.h>
#include <sbgEComIds.h>
#include <cmath>

sensor_msgs::Imu imu_msg;
sensor_msgs::NavSatFix nav_msg;
geometry_msgs::PoseStamped pose_msg;
geometry_msgs::Vector3Stamped euler_angels_msg;//欧拉角
geometry_msgs::Vector3Stamped vel_ekf_msg;//NED速度

bool new_imu_msg;
bool new_nav_msg;
bool new_twist_msg;
bool new_euler_angels_msg;

/*!
 *  Callback definition called each time a new log is received.
 *  \param[in]  pHandle                 Valid handle on the sbgECom instance that has called this callback.
 *  \param[in]  msgClass                Class of the message we have received
 *  \param[in]  msg                   Message ID of the log received.
 *  \param[in]  pLogData                Contains the received log data as an union.
 *  \param[in]  pUserArg                Optional user supplied argument.
 *  \return                       SBG_NO_ERROR if the received log has been used successfully.
 */
SbgErrorCode onLogReceived(SbgEComHandle *pHandle, SbgEComClass msgClass, SbgEComMsgId msg, const SbgBinaryLogData *pLogData, void *pUserArg)
{
  // float time_of_week;
  switch (msg){
    case SBG_ECOM_LOG_EKF_EULER:
      euler_angels_msg.vector.x = pLogData->ekfEulerData.euler[0]*180/3.14;
      euler_angels_msg.vector.y = pLogData->ekfEulerData.euler[1]*180/3.14;
      euler_angels_msg.vector.z = pLogData->ekfEulerData.euler[2]*180/3.14;

      new_euler_angels_msg = true;
      break;
    case SBG_ECOM_LOG_EKF_QUAT:
      //imu_msg.orientation.x = pLogData->ekfQuatData.quaternion[1];
      //imu_msg.orientation.y = pLogData->ekfQuatData.quaternion[2];
      //imu_msg.orientation.z = pLogData->ekfQuatData.quaternion[3];
      //imu_msg.orientation.w = pLogData->ekfQuatData.quaternion[0];
      double x,y,z,w;
         x = pLogData->ekfQuatData.quaternion[1];
         y = pLogData->ekfQuatData.quaternion[2];
         z = pLogData->ekfQuatData.quaternion[3];
         w = pLogData->ekfQuatData.quaternion[0];
      double roll, pitch, yaw,sinr_cosp,cosr_cosp,sinp,cy,sy,cp,sp,cr,sr,siny_cosp,cosy_cosp;
       sinr_cosp = 2 * (w * x + y * z);
       cosr_cosp = 1 - 2 * (x * x + y * y);
     roll = std::atan2(sinr_cosp, cosr_cosp);
      sinp = 2 * (w * y - z * x);
      if (std::abs(sinp) >= 1)
          pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
      else
          pitch = std::asin(sinp);
       siny_cosp = 2 * (w * z + x * y);
       cosy_cosp = 1 - 2 * (y * y + z * z);
      yaw = std::atan2(siny_cosp, cosy_cosp);
   
      cy = cos(yaw * 0.5);
      sy = (-1)*sin(yaw * 0.5);
      cp = cos(pitch * 0.5);
      sp = (-1)*sin(pitch * 0.5);
      cr = cos(roll * 0.5);
      sr = sin(roll * 0.5);


 
      imu_msg.orientation.w = cy * cp * cr + sy * sp * sr;
      imu_msg.orientation.x = cy * cp * sr - sy * sp * cr;
      imu_msg.orientation.y = sy * cp * sr + cy * sp * cr;
      imu_msg.orientation.z = sy * cp * cr - cy * sp * sr;





      pose_msg.pose.orientation.x = pLogData->ekfEulerData.euler[1];
      pose_msg.pose.orientation.y = pLogData->ekfEulerData.euler[2];
      pose_msg.pose.orientation.z = pLogData->ekfEulerData.euler[3];
      pose_msg.pose.orientation.w = pLogData->ekfEulerData.euler[0];

      new_imu_msg = true;
      break;
    case SBG_ECOM_LOG_EKF_NAV:
      nav_msg.latitude  = pLogData->ekfNavData.position[0];
      nav_msg.longitude = pLogData->ekfNavData.position[1];
      nav_msg.altitude  = pLogData->ekfNavData.position[2];

      vel_ekf_msg.vector.x = pLogData->ekfNavData.velocity[0];//NED速度，未经验证
      vel_ekf_msg.vector.y = pLogData->ekfNavData.velocity[1];
      vel_ekf_msg.vector.y = pLogData->ekfNavData.velocity[2];

      new_nav_msg = true;
      break;
    case SBG_ECOM_LOG_SHIP_MOTION:
      // imu_msg.linear_acceleration.x = pLogData->shipMotionData.shipVel[0];
      // imu_msg.linear_acceleration.y = pLogData->shipMotionData.shipVel[1];
      // imu_msg.linear_acceleration.z = pLogData->shipMotionData.shipVel[2];
      // new_imu_msg = true;
      break;

    case SBG_ECOM_LOG_IMU_DATA:
      imu_msg.linear_acceleration.x = pLogData->imuData.accelerometers[0];
      imu_msg.linear_acceleration.y = pLogData->imuData.accelerometers[1]*(-1);
      imu_msg.linear_acceleration.z = pLogData->imuData.accelerometers[2]*(-1);

      imu_msg.angular_velocity.x= pLogData->imuData.gyroscopes[0];
      imu_msg.angular_velocity.y = pLogData->imuData.gyroscopes[1]*(-1);
      imu_msg.angular_velocity.z = pLogData->imuData.gyroscopes[2]*(-1);
      new_imu_msg = true;
      break;
    // case SBG_ECOM_LOG_UTC_TIME:
    //   pInsSBG->new_time = true;
    //   pInsSBG->year          = pLogData->utcData.year;
    //   pInsSBG->month         = pLogData->utcData.month;
    //   pInsSBG->day           = pLogData->utcData.day;
    //   pInsSBG->hour          = pLogData->utcData.hour;
    //   pInsSBG->minute        = pLogData->utcData.minute;
    //   pInsSBG->second        = pLogData->utcData.second;
    //   pInsSBG->nanoSecond    = pLogData->utcData.nanoSecond;
    //   pInsSBG->gpsTimeOfWeek = pLogData->utcData.gpsTimeOfWeek;
      // break;
    default:
      break;
  }
  return SBG_NO_ERROR;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sbg_ellipse");

  ros::NodeHandle n;
  ros::Publisher imu_pub = n.advertise<sensor_msgs::Imu>("imu", 10);
  ros::Publisher gps_pub = n.advertise<sensor_msgs::NavSatFix>("fix", 10);
  ros::Publisher pose_pub = n.advertise<geometry_msgs::PoseStamped>("imu_pose", 10);
  ros::Publisher euler_pub = n.advertise<geometry_msgs::Vector3Stamped>("euler_angels", 10);

  std::string uart_port;
  int uart_baud_rate;

  n.param<std::string>("uart_port", uart_port, "/dev/ttyUSB0");
  n.param<int>("uart_baud_rate", uart_baud_rate, 115200);

    // ********************* Initialize the SBG  *********************
  SbgEComHandle       comHandle;
  SbgInterface        sbgInterface;
  SbgEComDeviceInfo   deviceInfo;
  SbgErrorCode        errorCode;

  errorCode = sbgInterfaceSerialCreate(&sbgInterface, uart_port.c_str(), uart_baud_rate);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgInterfaceSerialCreate Error");}

  errorCode = sbgEComInit(&comHandle, &sbgInterface); // Init the SBG
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComInit Error");}

  errorCode = sbgEComCmdGetInfo(&comHandle, &deviceInfo); // Get device info
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdGetInfo Error");}

  ROS_INFO("CONNEXTION SET-UP");

  // ****************************** SBG Config ******************************
  // ToDo: improve configuration capabilities
  errorCode = sbgEComCmdOutputSetConf(&comHandle, SBG_ECOM_OUTPUT_PORT_A, SBG_ECOM_CLASS_LOG_ECOM_0, SBG_ECOM_LOG_EKF_EULER, SBG_ECOM_OUTPUT_MODE_DIV_8);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdOutputSetConf SBG_ECOM_LOG_EKF_EULER Error");}

  errorCode = sbgEComCmdOutputSetConf(&comHandle, SBG_ECOM_OUTPUT_PORT_A, SBG_ECOM_CLASS_LOG_ECOM_0, SBG_ECOM_LOG_EKF_QUAT, SBG_ECOM_OUTPUT_MODE_DIV_8);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdOutputSetConf SBG_ECOM_LOG_EKF_QUAT Error");}

  errorCode = sbgEComCmdOutputSetConf(&comHandle, SBG_ECOM_OUTPUT_PORT_A, SBG_ECOM_CLASS_LOG_ECOM_0, SBG_ECOM_LOG_EKF_NAV, SBG_ECOM_OUTPUT_MODE_DIV_8);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdOutputSetConf SBG_ECOM_LOG_EKF_NAV Error");}

  errorCode = sbgEComCmdOutputSetConf(&comHandle, SBG_ECOM_OUTPUT_PORT_A, SBG_ECOM_CLASS_LOG_ECOM_0, SBG_ECOM_LOG_IMU_DATA, SBG_ECOM_OUTPUT_MODE_DIV_8);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdOutputSetConf SBG_ECOM_LOG_IMU_DATA Error");}

  errorCode = sbgEComCmdOutputSetConf(&comHandle, SBG_ECOM_OUTPUT_PORT_A, SBG_ECOM_CLASS_LOG_ECOM_0, SBG_ECOM_LOG_SHIP_MOTION, SBG_ECOM_OUTPUT_MODE_DIV_8);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdOutputSetConf SBG_ECOM_LOG_SHIP_MOTION Error");}

  // SAVE AND REBOOT
  errorCode = sbgEComCmdSettingsAction(&comHandle, SBG_ECOM_SAVE_SETTINGS);
  if (errorCode != SBG_NO_ERROR){ROS_WARN("sbgEComCmdSettingsAction Error");}

  ROS_INFO("CONFIGURATION DONE");

  // ************************** SBG Callback for data ************************
  bool test = false;
  sbgEComSetReceiveLogCallback(&comHandle, onLogReceived, NULL);

  ROS_INFO("START RECEIVING DATA");

  euler_angels_msg.header.frame_id = "map";
  imu_msg.header.frame_id = "map";
  nav_msg.header.frame_id = "map";
  pose_msg.header.frame_id = "map";

  ros::Rate loop_rate(25);
  while (ros::ok())
  {
    int errorCode = sbgEComHandle(&comHandle);

    if(new_euler_angels_msg){
      euler_angels_msg.header.stamp = ros::Time::now();
      euler_pub.publish(euler_angels_msg);  
      new_euler_angels_msg = false;
    }
    if(new_nav_msg){
      nav_msg.header.stamp = ros::Time::now();
      gps_pub.publish(nav_msg);  
      new_nav_msg = false;
    }

    if(new_imu_msg){
      imu_msg.header.stamp = ros::Time::now();
      imu_pub.publish(imu_msg);
      pose_msg.header.stamp = ros::Time::now();
      pose_pub.publish(pose_msg);

      new_imu_msg = false;
    }

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
