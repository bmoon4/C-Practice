#include <iostream>

//default template parameter values
//A template declaration for a class accepts default parameter values. 
// We specify the default value in the same way that we specify a default value for a function parameter in a function declaration:

template <class T = int, int size = 50>

 class Array {
     T a[size];
     unsigned n;
     T dummy;
     
 public:
 	
     Array() : n(0), dummy(0) {}// �ʱ�ȭ ����Ʈ  
     
     T& operator[](unsigned i) {
         return i < 50u ? a[i] : dummy; 
     } 
 };
 
 int main() {
     Array <> a, b;   // <> Ÿ������ ���� �����Ƿ�, ����Ʈ Ÿ�� ���� 

     for (int i = 0; i < 5; i++)
         a[i] = i * i;
     b = a;
     for (int i = 0; i < 5; i++)
         std::cout << b[i] << ' ';
     std::cout << std::endl;
 }
