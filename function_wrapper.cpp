 // Functional - function wrapper
 // function_wrapper.cpp

 #include <iostream>
 #include <functional>

 // a simple function
 long multiply(long x, long y) { return x * y; }

 // a functor
 struct Multiply {
     long operator()(long x, long y) { return x * y; }
 };
 // function���ø����� �Լ�(������)�� ������ �ִ�. (�Ϲ��Լ�, �Լ���ü, ���ٽ�)  
 int main() {
     std::function<long(long, long)> f1 = multiply; // function
     std::function<long(long, long)> f2 = Multiply(); // functor
     std::function<long(long, long)> f3 = [](long x, long y) { return x * y; }; // lambda expression
     
     std::cout << "f1(10, 2) = " << f1(10, 2) << std::endl;  // 20
     std::cout << "f2(10, 2) = " << f2(10, 2) << std::endl;  // 20
     std::cout << "f3(10, 2) = " << f3(10, 2) << std::endl;  // 20
 }
 
 /*
 	f1(10, 2) = 20
	f2(10, 2) = 20
	f3(10, 2) = 20

--------------------------------
Process exited after 1.536 seconds with return value 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
 */
