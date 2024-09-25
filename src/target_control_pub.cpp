#include<ros/ros.h>
#include <eigen3/Eigen/Geometry> 
#include "learning_topic/Person.h"



//@brief 	函数通过机器人 |自身位置-目标位置|*比例 = 设置速度
//@param1 	机器人的自身位置
//@param2	机器人的目标位置
//@ret		返回一个2*1的列向量，因为只有线x速度,和角y速度
Eigen::Matrix<float , 2 , 1> Speed_Control(Eigen::Matrix<float , 2 , 1> Robotposition , Eigen::Matrix<float , 2 , 1> Targetposition)
{
	float k = 1.0;
	(Robotposition[0][0] - Targetposition[0][0]) * k
	
}





int main(int argc , char **argv)
{
	
	
	
	return 0;
}