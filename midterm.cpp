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
	
	
	// ������ �Ǵ� ���� 
	print( L"C++11 is a better c++" );     // �����Ͷ�� ���... const wchar_t* -> �׷��� l-value  
	print( "C++11 is a better c++" );     //  l-value ���ܻ����̴�   //  const char[]( not temporary?) :: Lvalues are not objects.
	print(std::string( "C++ NOOOO" ) );       //  r-value  // this is a string object, which is temporary without name.
	//print(&std::string( "C++ NOOOO" ) ); �� �����߻� -taking address of temporary 
	
	std::string a = "i am a string";    
	print(a);  // l-value
	print(&a); // r-value �ּҰ�����... �̰� ��...???? 
	
	std::string a2 = "i am a string pointer";
	std::string* aptr = &a2; 
	print(aptr);
	print(a2);
	
	
	int* dynamic = new int[10];
	
	print(dynamic);


	
	// ������ �����͸� �ּҰ��� ��µɶ� l-value�� ���� 
	// �����Ͱ� �ƴϰ� �׳� ���� �ּҰ� ��µɶ��� ���� �����ϻ��̹Ƿ� r-value 
	
	
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
l-value: value = C++11 is a better c++  // �ּҰ� ������ �����ϹǷ� l-value....... 
r-value: value = C++ NOOOO
l-value: value = i am a string

--------------------------------
Process exited after 1.205 seconds with return value 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . ..

*/
