// Algorithms - Inner Product
 // inner_product.cpp

 #include <iostream>
 #include <numeric>
 #include <functional>

/*
template <class InputIterator1, class InputIterator2, class T>
   T inner_product (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init)

init : Initial value for the accumulator.


template <class InputIterator1, class InputIterator2, class T, class BinaryOperation1, class BinaryOperation2>
   T inner_product (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryOperation1 binary_op1, BinaryOperation2 binary_op2);

binary_op1 :
    Binary operation taking two elements of type T as arguments, and returning the result of an accumulation operation.
    This can either be a function pointer or a function object.
binary_op2 : 
    Binary operation taking two elements of type T as arguments, and returning the result of the inner product operation.
    This can either be a function pointer or a function object.


*/


 int main() {
     int a[] = {3, 2, 4, 1}, b[] = {1, 2, 3, 4}, s;

     s = std::inner_product(a, &a[4], b, (int)0);  // 마지막 자리 반복자는 항상 마지막 인덱스+1 => 그래서 &a[3]이 아니고 &a[4] 이다.  
     std::cout << "dot product = " << s <<  std::endl; // (3*1) + (2*2) + (4*3) + (1*4) = 23
     
     s = std::inner_product(a, &a[4], b, (int)0,   std::plus<int>(),                [](int x, int y) { return (x - y) * (x - y); });
	                                            // BinaryOperation1 binary_op1,  BinaryOperation2 binary_op2
     std::cout << "sum of " "(a[i]-b[i])^2 = " << s <<  std::endl; 
 }
