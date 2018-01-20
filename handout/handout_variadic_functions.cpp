#include <iostream>


 template <typename T, typename... etc>
 void list(const T& t, const etc&... pp) { 
 
	std::cout << "List of values " << std::endl;
	
	const int size = t;
    
    int x[size] = {pp...};
      
    for(int i = 0; i < size ; i++)
	std::cout << i + 1 << " : " << x[i] << std::endl;
    
	
 }

 int main() {
     list(6, 1, 2, 3, 4, 5, 8);
     list(3, 7, 8, 9);
 }
 

