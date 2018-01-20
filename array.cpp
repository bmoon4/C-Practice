#include <iostream>

class Array {
   
     int a[50];
     unsigned n;
     int dummy;
 
 public:
     Array() : n{0u}, dummy{0} {} //초기화리스트 
     
     int& operator[](unsigned i) {
         return i < 50u ? a[i] : dummy; 
     }
	  
 };
 
 int main() {
     Array a, b;

     for (int i = 0; i < 5; i++)
         a[i] = i * i;
     
	 b = a;
     
	 for (int i = 0; i < 5; i++)
         std::cout << b[i] << ' ';
     
	 std::cout << std::endl;
}
