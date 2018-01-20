#include <iostream>
using namespace std;


int Function1(int a, int b){
   return a+b;
}

int main(){
	 
	int (*FunctionPointer)(int, int);   //�Լ� ������ ���� -> �������� �̸��� FunctionPointer�� �׳� ����( �ƹ��ų��ᵵ ��) 
										// �Ű������� int�� �ΰ��� �ް� ����Ÿ���� int�� �Լ�������!
										//   void (*foo)(int); ��� �Ű������� int�� �ް� ��ȯŸ���� void�� �Լ��� ������ 
	FunctionPointer = Function1; 

 	cout<<Function1<<endl; //Function1�� �ּҰ� ��� 

  	cout<<FunctionPointer<<endl; //�Լ��������� �� ���(= Function1�� �ּҰ�)

  	cout<<"========================="<<endl;

  	cout<<Function1(10, 20)<<endl;

  	cout<<FunctionPointer(10, 20)<<endl;

    cout<<"========================="<<endl; 


	return 0;

}

/*

	1
	1
	=========================
	30
	30
	=========================

	--------------------------------
	Process exited after 1.704 seconds with return value 0
	����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .

*/

/* �Լ������͸� ����ϴ� ���� -> �Լ��� �����Ͷ�� ������Ÿ������ ǥ���� ���������鼭 �ٸ� �Լ��� �з����ͷ� ������ ����
	�̺�Ʈ����� �ڵ��� �Ҷ�. �� �ݹ��Լ��� ����Ҷ� �������� -> �Ű������� �Լ��� �������ְԵǹǷ�! 
*/



