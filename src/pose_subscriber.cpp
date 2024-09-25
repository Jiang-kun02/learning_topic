/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * �����̽�����/turtle1/pose���⣬��Ϣ����turtlesim::Pose
 */
 
#include <ros/ros.h>
#include "turtlesim/Pose.h"

// ���յ����ĵ���Ϣ�󣬻������Ϣ�ص�����
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // �����յ�����Ϣ��ӡ����
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

int main(int argc, char **argv)
{
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "pose_subscriber");

    // �����ڵ���
    ros::NodeHandle n;

    // ����һ��Subscriber��������Ϊ/turtle1/pose��topic��ע��ص�����poseCallback
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

    // ѭ���ȴ��ص�����
    ros::spin();

    return 0;
}
