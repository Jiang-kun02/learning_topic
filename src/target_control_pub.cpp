#include<ros/ros.h>
#include <eigen3/Eigen/Geometry> 
#include "learning_topic/Person.h"



//@brief 	����ͨ�������� |����λ��-Ŀ��λ��|*���� = �����ٶ�
//@param1 	�����˵�����λ��
//@param2	�����˵�Ŀ��λ��
//@ret		����һ��2*1������������Ϊֻ����x�ٶ�,�ͽ�y�ٶ�
Eigen::Matrix<float , 2 , 1> Speed_Control(Eigen::Matrix<float , 2 , 1> Robotposition , Eigen::Matrix<float , 2 , 1> Targetposition)
{
	float k = 1.0;
	(Robotposition[0][0] - Targetposition[0][0]) * k
	
}





int main(int argc , char **argv)
{
	
	
	
	return 0;
}