/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * �����̽�����turtle1/cmd_vel���⣬��Ϣ����geometry_msgs::Twist
 */
 
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	// ROS�ڵ��ʼ��
	ros::init(argc, argv, "velocity_publisher");

	// �����ڵ���
	ros::NodeHandle n;

	// ����һ��Publisher��������Ϊ/turtle1/cmd_vel��topic����Ϣ����Ϊgeometry_msgs::Twist�����г���10
	ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	// ����ѭ����Ƶ��
	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok())
	{
	    // ��ʼ��geometry_msgs::Twist���͵���Ϣ
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x = 0.5;
		vel_msg.angular.z = 0.2;

	    // ������Ϣ
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", 
				vel_msg.linear.x, vel_msg.angular.z);

	    // ����ѭ��Ƶ����ʱ
	    loop_rate.sleep();
	}

	return 0;
}
