// Generic Pointer Type
// void.cpp

 #include <iostream>

 int main() {
     int i;
     void* v = &i;
     int* j;
     
	 j = static_cast<int*>(v);  // OK - j now holds the address of i 
     
	 std::cout << &i << std::endl;
     std::cout << j << std::endl;
     std::cout << v << std::endl;
 }
 /*
 
0x22fe3c
0x22fe3c
0x22fe3c

--------------------------------
Process exited after 0.7743 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 
 
 */
