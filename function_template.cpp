#include <iostream>

template <typename T>
 void swap(T& a, T& b) {
 	T c;
    c = a;
    a = b;
    b = c;
 }
 
int main(int argc, char* argv[]) {   //  >swap 2.3 4.5 78 567
    if (argc > 4) {
        double a = atof(argv[1]); // 2.3
        double b = atof(argv[2]); // 4.5
        long   d = atol(argv[3]); // 78
        long   e = atol(argv[4]); // 567

        swap(a, b);

         std::cout << "Swapped values are " <<   //Swapped values are 4.5 and 2.3 
          a << " and " << b << std::endl;

         swap(d, e);

         std::cout << "Swapped values are " << //Swapped values are 567 and 78
          d << " and " << e << std::endl;
     }
 }
