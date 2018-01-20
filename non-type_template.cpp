#include <iostream>
// non-type template parameter
// Non-type template parameters can receive the size of an array.  
/*
템플릿의 인수 목록에 전달되는 것은 통상 타입이다. 알고리즘은 같되 타입만 다른 함수나 클래스를 작성하고 싶을 때 템플릿을 사용한다. 
그러나 타입이 아닌 상수를 템플릿 인수로 전달할 수 있는데 이를 비타입 인수(Nontype Argument)라고 한다.
*/
template <class T, int size>  // 여기서 int size가 비타입 인수 (상수가 들어오기 때문) 
 
 class Array {
     T a[size];
     unsigned n;
     T dummy;
 
 public:
     Array() : n{0u}, dummy{0} {} //초기화 리스트  
     
	 T& operator[](unsigned i) {
         return i < 50u ? a[i] : dummy; 
     } 
 };
 
 
 int main() {
     Array <int, 50> a, b;

     for (int i = 0; i < 5; i++)
         a[i] = i * i;
         
     b = a;
     
	 for (int i = 0; i < 5; i++)
         std::cout << b[i] << ' ';
     
	 std::cout << std::endl;
 }
