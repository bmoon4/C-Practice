#include <iostream>
using namespace std;


int Function1(int a, int b){
   return a+b;
}

int main(){
	 
	int (*FunctionPointer)(int, int);   //함수 포인터 선언 -> 포인터의 이름은 FunctionPointer로 그냥 정함( 아무거나써도 됌) 
										// 매개변수로 int형 두개를 받고 리턴타입은 int인 함수포인터!
										//   void (*foo)(int); 라면 매개변수로 int를 받고 반환타입은 void인 함수의 포인터 
	FunctionPointer = Function1; 

 	cout<<Function1<<endl; //Function1의 주소값 출력 

  	cout<<FunctionPointer<<endl; //함수포인터의 값 출력(= Function1의 주소값)

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
	계속하려면 아무 키나 누르십시오 . . .

*/

/* 함수포인터를 사용하는 이유 -> 함수를 포인터라는 데이터타입으로 표현이 가능해지면서 다른 함수의 패러미터로 넣을수 있음
	이벤트기반의 코딩을 할때. 즉 콜백함수를 써야할때 유용해짐 -> 매개변수로 함수를 넣을수있게되므로! 
*/



