#include <iostream>
// non-type template parameter
// Non-type template parameters can receive the size of an array.  
/*
���ø��� �μ� ��Ͽ� ���޵Ǵ� ���� ��� Ÿ���̴�. �˰����� ���� Ÿ�Ը� �ٸ� �Լ��� Ŭ������ �ۼ��ϰ� ���� �� ���ø��� ����Ѵ�. 
�׷��� Ÿ���� �ƴ� ����� ���ø� �μ��� ������ �� �ִµ� �̸� ��Ÿ�� �μ�(Nontype Argument)��� �Ѵ�.
*/
template <class T, int size>  // ���⼭ int size�� ��Ÿ�� �μ� (����� ������ ����) 
 
 class Array {
     T a[size];
     unsigned n;
     T dummy;
 
 public:
     Array() : n{0u}, dummy{0} {} //�ʱ�ȭ ����Ʈ  
     
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
