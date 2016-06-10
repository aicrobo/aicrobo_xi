//#include <ros/ros.h>
//#include <geometry_msgs/Twist.h>
//#include <sensor_msgs/Joy.h>
//
//class TeleopTurtle
//{
//public:
//  TeleopTurtle();
//
//private:
//  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
//
//  ros::NodeHandle nh_;
//
//  int linear_, angular_;
//  double l_scale_, a_scale_;
//  ros::Publisher vel_pub_;
//  ros::Subscriber joy_sub_;
//
//};
//
//
//TeleopTurtle::TeleopTurtle():
//  linear_(1),
//  angular_(2)
//{
//  nh_.param("axis_linear", linear_, linear_);
//  nh_.param("axis_angular", angular_, angular_);
//  nh_.param("scale_angular", a_scale_, a_scale_);
//  nh_.param("scale_linear", l_scale_, l_scale_);
//
//  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("turtle1/command_velocity", 1);
//  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback, this);
//
//}
//
//void TeleopTurtle::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
//{
//  geometry_msgs::Twist speed;
//  speed.angular.z = a_scale_*joy->axes[angular_];
//  speed.linear.x = l_scale_*joy->axes[linear_];
//  vel_pub_.publish(speed);
//}
//
//
//int main(int argc, char** argv)
//{
//  ros::init(argc, argv, "teleop_turtle");
//  TeleopTurtle teleop_turtle;
//
//  ros::spin();
//}

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

ros::Publisher cmdVelPub;

void joyCallback(sensor_msgs::Joy joy)
{
  geometry_msgs::Twist speed;
  ROS_INFO("get the joy message");
  speed.angular.z = 0.5*joy.axes[0];
  speed.linear.x = 0.5*joy.axes[1];
  cmdVelPub.publish(speed);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "aicroboxi_joy_teleop");
  ros::NodeHandle nh;
  ros::NodeHandle ph ( "~" );

  ros::Subscriber joysub = nh.subscribe("/axis/joy", 10, joyCallback);
  cmdVelPub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

  ros::Rate loopRate(10);
  ROS_INFO("Rovio pub ON...");
  while (ros::ok())
  {
    ros::spinOnce();
    loopRate.sleep();

  }


  return 0;

}
