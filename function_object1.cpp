#include <iostream>
 // 함수객체를 functor라고 부른다.  
 // 어떤 객체를 함수처럼 사용한다는 것은 객체에 괄호를 붙여서
 // 마치 겉보기엔 함수를 호출하는것처럼 사용  한다는 의미이다.
 // 이게 불편해져서 나중에 람다가 생김  
class myFunctorClass
{
	private:
        int _x;
    
	public:
        myFunctorClass (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
   
};
 
 // functor는 객체지만(클래스니까) 함수처럼 사용이 가능한데  
int main()
{
    myFunctorClass addFive( 5 );
    std::cout << addFive( 6 ) << std::endl;   // 마치 함수마냥 객체에 괄호를 붙여서 쓰고 있음. 결과는  11
 	std::cout << addFive( 5 ) << std::endl;    // 10 
    return 0;
}

// 이렇게 객체를 함수호출하듯 쓰려면 어떻게 해야할까?
// 함수 호출 연산자 ()를 반드시 오버로딩 해야한다. 
//  int operator() (int y) { return _x + y; } 이렇게 
