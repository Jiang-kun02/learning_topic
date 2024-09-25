#include<ros/ros.h>
#include "learning_topic/Person.h"

class Person_Info
{
public:
	
	learning_topic::Person person_msg;
	
	Person_Info() : received_data(false){}
	
	//»Øµ÷º¯Êý
	void Personinfo_Callback(const learning_topic::Person::ConstPtr& msg)
	{
		std::lock_guard<std::mutex> lock(data_mutex);
		person_msg = *msg;
		received_data = true;
		ROS_INFO("Received_data: name = %s , age = %d , sex = %d " , person_msg.name.c_str() , person_msg.age , person_msg.sex);
	}
	
	bool GetPersoninfo(learning_topic::Person& info)
	{
		std::lock_guard<std::mutex> lock(data_mutex);
		if(received_data)
		{
			info = person_msg;
			return true;
		}
		return false;
	}
	
private:
	bool received_data;
	std::mutex data_mutex;

};


int main(int argc , char **argv)
{
	ros::init(argc , argv , "person_sub_lock");
	
	ros::NodeHandle nh;
	
	Person_Info person_info;
	
	ros::Subscriber sub = nh.subscribe("/person_info" , 10 , &Person_Info::Personinfo_Callback , &person_info);
	
	ros::Rate loop_rate(10);
	
	learning_topic::Person current_person;
	
	while(ros::ok())
	{
		ros::spinOnce();
		
		if(person_info.GetPersoninfo(current_person))
		{
			current_person.age++;
			ROS_INFO("Current Person: name = %s, age = %d, sex = %d", current_person.name.c_str(), current_person.age, current_person.sex);
		}
		loop_rate.sleep();
		
	}
	
	
	return 0;
}