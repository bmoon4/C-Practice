#include <iostream>
#include <utility>

template<typename T> void print(const T&  x) { std::cout << "l-value: value = " << x << std::endl; }
template<typename T> void print(const T&& x) { std::cout << "r-value: value = " << x << std::endl; }



int main(){
	
	char broiled = 'X';
	bool makes = true;
	double trouble = 665.0;
	
	print( broiled );
	print( broiled + 2);
	print( std::move(broiled) );
	print( makes + trouble );       // bool + double = r-value ???? 
	print( 2 + 10.6 );
	print( trouble );
	
	
	// 문제가 되는 구간 
	print( L"C++11 is a better c++" );     // 포인터라는 얘기... const wchar_t* -> 그래서 l-value  
	print( "C++11 is a better c++" );     //  l-value 예외사항이다   //  const char[]( not temporary?) :: Lvalues are not objects.
	print(std::string( "C++ NOOOO" ) );       //  r-value  // this is a string object, which is temporary without name.
	//print(&std::string( "C++ NOOOO" ) ); 는 에러발생 -taking address of temporary 
	
	std::string a = "i am a string";    
	print(a);  // l-value
	print(&a); // r-value 주소값나옴... 이건 왜...???? 
	
	std::string a2 = "i am a string pointer";
	std::string* aptr = &a2; 
	print(aptr);
	print(a2);
	
	
	int* dynamic = new int[10];
	
	print(dynamic);


	
	// 성질상 포인터면 주소값이 출력될때 l-value로 나옴 
	// 포인터가 아니고 그냥 순수 주소값 출력될때는 그저 숫자일뿐이므로 r-value 
	
	
	return 0;
}

/*
l-value: value = X
r-value: value = 90
r-value: value = X
r-value: value = 666
r-value: value = 12.6
l-value: value = 665
l-value: value = 0x488008
l-value: value = C++11 is a better c++  // 주소값 추출이 가능하므로 l-value....... 
r-value: value = C++ NOOOO
l-value: value = i am a string

--------------------------------
Process exited after 1.205 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . ..

*/
