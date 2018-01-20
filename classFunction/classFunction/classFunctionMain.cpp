// Class Functions - Application
// classFunctionMain.cpp

#include <iostream>
#include "classFunction.h"

int main() {
	std::cout << Horse::howMany() << " horses\n"; // 0 
	
	{
		Horse silver(3), northernDancer(4);

		silver.display();
		northernDancer.display();

		std::cout << Horse::howMany() << " horses" << std::endl;  // 2
		std::cout << silver.howMany() << " horses" << std::endl;  // 2
		std::cout << northernDancer.howMany() << " horses" << std::endl;  // 2
	}
	std::cout << Horse::howMany() << " horses\n"; // 0
	getchar();
}

/*
	0 horses
	Horse 1 is 3 years old
	Horse 2 is 4 years old
	2 horses
	2 horses
	2 horses
	0 horses
*/