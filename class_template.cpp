#include <iostream>

template <typename T>
 class Array {
     T a[50];
     unsigned n;
     T dummy;
     
 public:
     Array() : n{0u}, dummy{0} {} //초기화리스트 
     
	 T& operator[](unsigned i) {
         return i < 50u ? a[i] : dummy; 
     } 
 };
 /*
 	The compiler replaces type T with the argument specified in the call to the Array template. 
	The following program creates an array of longs:
 */
 int main() {
     Array<long> a, b;

     for (int i = 0; i < 5; i++)
         a[i] = i * i;
     
	 b = a;
     
	 for (int i = 0; i < 5; i++)
         std::cout << b[i] << ' ';
     
	 std::cout << std::endl;
}
