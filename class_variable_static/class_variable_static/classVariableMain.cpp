// Class Variables - Application
// classVariableMain.cpp

#include <iostream>
#include "classVariable.h"

int main() {
	std::cout << Horse::noHorses << " horses\n";  // 0   
	
	{//이건왜한겨 (소멸자써먹을라고)
		Horse silver(3), northernDancer(4);  // 1, 2  (지역변수로 생성된 객체2개)
		
		silver.display();
		northernDancer.display();
		
		std::cout << Horse::noHorses << " horses" << std::endl;  //2
		
		std::cout << silver.noHorses << " horses" << std::endl;  //2
		
		std::cout << northernDancer.noHorses << " horses" << std::endl; //2
	}//블록종료와 동시에 소멸자호출되면서
	// 두 객체 소멸되면서 --연산실행 -> 2가 1이되고 , 1이 0이됨
	std::cout << Horse::noHorses << " horses\n"; // 따라서 0 

	getchar();

}






/* 
	
	Note that we can access a class variable even if there are no instances of the class.  
	
	*/

/*
이제알았음!
static 변수는 클래스의 인스턴스화 되는 시점에 메모리에 생성되는게 아니라 
이미 이전부터 메모리에 생성되어버린다. (인스턴스화와 무관하게) -> 객체가 생기기도 전에 컴파일당시 생성되버림

그래서 인스턴스가 없어도 (있던지말던지간에) 메모리에 이미 존재하기때문에 접근이 가능

static으로 선언된 변수 또는 함수는 동일한 클래스에서 만들어진 객체에서 공유된다. 즉, 객체가 몇개가 생기든 클래스당 오직 한개만 생긴다.
이때문에 static멤버는 클래스멤버라고 불린다. 


위코드의 중요한 점은 static멤버는 인스턴스화가 몇개가 뜨던간에 한개뿐이고
그 한개가지고 계속 써먹음. 종료될때까지.
*/