/*!
 * Author: Yuanbo She yuanboshe@126.com
 * Group: AICRobo http://aicrobo.github.io
 *
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2014, AICRobo.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>

ros::Publisher cmdVelPub;

void shutdown(int sig)
{
  cmdVelPub.publish(geometry_msgs::Twist());
  ROS_INFO("aicrobo_example_move cpp ended!");
  ros::shutdown();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "aicroboxi_example_move");
  std::string topic = "/cmd_vel";
  ros::NodeHandle node;
  cmdVelPub = node.advertise<geometry_msgs::Twist>(topic, 1);
  ros::Rate loopRate(10);
  signal(SIGINT, shutdown);
  ROS_INFO("aicrobo_example_move cpp start...");

  geometry_msgs::Twist speed; // 控制信号载体 Twist message
  while (ros::ok())
  {
    speed.linear.x = 0.1; // 设置线速度为0.1m/s，正为前进，负为后退
    speed.angular.z = 0.4; // 设置角速度为0.4rad/s，正为左转，负为右转
    cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人

    loopRate.sleep();
  }

  return 0;
}
