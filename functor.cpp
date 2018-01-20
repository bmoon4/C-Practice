#include <iostream>

struct Object{
	void operator() (int i) const{
		std::cout << i << std::endl;
	}
}; 

void Foo(int i){
	std::cout << i << std::endl;
}

int main(){
	Foo(42);
	Object o;
	o(42);
	return 0;
}
