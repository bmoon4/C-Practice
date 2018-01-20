#include <iostream>

template <typename T = int, int size = 50> 

 class Array {
     T a[size];
     unsigned n;
     T dummy;
     static unsigned count; //static 멤버 선언 

 public:
     Array() : n{0}, dummy{0} { ++count; }
     
     T& operator[](unsigned i) {
         return i < 50u ? a[i] : dummy; 
     } 
     
	 static unsigned cnt() { return count; } 
     
	 ~Array() { --count; }
 };

 template <typename T = int, int size = 50>
 unsigned Array<T, size>::count = 0u; //비주얼스튜디오에서는 되는데.. 왜 여기선 안돌아가니.. 
 
 
  int main() {
  	
     Array<> s, t;
     Array<double> u;
     Array<int, 40> v;

     std::cout << Array<>::cnt() << std::endl;        // 2
     std::cout << Array<double>::cnt() << std::endl;  // 1
     std::cout << Array<int, 40>::cnt() << std::endl; // 1
}
