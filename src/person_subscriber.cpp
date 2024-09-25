/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * �����̽�����/person_info���⣬�Զ�����Ϣ����learning_topic::Person
 */
 
#include <ros/ros.h>
#include "learning_topic/Person.h"

// ���յ����ĵ���Ϣ�󣬻������Ϣ�ص�����
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
    // �����յ�����Ϣ��ӡ����
    ROS_INFO("Subcribe Person Info: name:%s  age:%d  sex:%d", 
			 msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char **argv)
{
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "person_subscriber");

    // �����ڵ���
    ros::NodeHandle n;

    // ����һ��Subscriber��������Ϊ/person_info��topic��ע��ص�����personInfoCallback
    ros::Subscriber person_info_sub = n.subscribe("/person_info", 10, personInfoCallback);

    // ѭ���ȴ��ص�����
    ros::spin();

    return 0;
}
