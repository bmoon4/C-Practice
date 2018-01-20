// Class Variables - Application
// classVariableMain.cpp

#include <iostream>
#include "classVariable.h"

int main() {
	std::cout << Horse::noHorses << " horses\n";  // 0   
	
	{//�̰ǿ��Ѱ� (�Ҹ��ڽ�������)
		Horse silver(3), northernDancer(4);  // 1, 2  (���������� ������ ��ü2��)
		
		silver.display();
		northernDancer.display();
		
		std::cout << Horse::noHorses << " horses" << std::endl;  //2
		
		std::cout << silver.noHorses << " horses" << std::endl;  //2
		
		std::cout << northernDancer.noHorses << " horses" << std::endl; //2
	}//�������� ���ÿ� �Ҹ���ȣ��Ǹ鼭
	// �� ��ü �Ҹ�Ǹ鼭 --������� -> 2�� 1�̵ǰ� , 1�� 0�̵�
	std::cout << Horse::noHorses << " horses\n"; // ���� 0 

	getchar();

}






/* 
	
	Note that we can access a class variable even if there are no instances of the class.  
	
	*/

/*
�����˾���!
static ������ Ŭ������ �ν��Ͻ�ȭ �Ǵ� ������ �޸𸮿� �����Ǵ°� �ƴ϶� 
�̹� �������� �޸𸮿� �����Ǿ������. (�ν��Ͻ�ȭ�� �����ϰ�) -> ��ü�� ����⵵ ���� �����ϴ�� �����ǹ���

�׷��� �ν��Ͻ��� ��� (�ִ�������������) �޸𸮿� �̹� �����ϱ⶧���� ������ ����

static���� ����� ���� �Ǵ� �Լ��� ������ Ŭ�������� ������� ��ü���� �����ȴ�. ��, ��ü�� ��� ����� Ŭ������ ���� �Ѱ��� �����.
�̶����� static����� Ŭ���������� �Ҹ���. 


���ڵ��� �߿��� ���� static����� �ν��Ͻ�ȭ�� ��� �ߴ����� �Ѱ����̰�
�� �Ѱ������� ��� �����. ����ɶ�����.
*/