/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * �����̽�����/person_info���⣬�Զ�����Ϣ����learning_topic::Person
 */
 
#include <ros/ros.h>
#include <iostream>
#include "learning_topic/Person.h"

int main(int argc, char **argv)
{
    // ROS�ڵ��ʼ��
    ros::init(argc, argv, "person_publisher");

    // �����ڵ���
    ros::NodeHandle n;

    // ����һ��Publisher��������Ϊ/person_info��topic����Ϣ����Ϊlearning_topic::Person�����г���10
    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info", 10);

    // ����ѭ����Ƶ��
    ros::Rate loop_rate(1);

    int count = 0;
	
	// ��ʼ��learning_topic::Person���͵���Ϣ
	learning_topic::Person person_msg;
	person_msg.name = "Tom";
	person_msg.age  = 18;
	person_msg.sex  = learning_topic::Person::male;
	
	
    while (ros::ok())
    {
		person_msg.age = std::rand();
        // ������Ϣ
		person_info_pub.publish(person_msg);

       	ROS_INFO("Publish Person Info: name:%s  age:%d  sex:%d", 
				  person_msg.name.c_str(), person_msg.age, person_msg.sex);

        // ����ѭ��Ƶ����ʱ
        loop_rate.sleep();
    }

    return 0;
}
