 // Range-Based for
 // for_each.cpp

 #include <iostream>

 int main () {
     int a[] {1, 2, 3, 4, 5, 6};

     for (int& e : a)
         std::cout << e << ' ';
     std::cout << std::endl;
     
     
     
     char b[] {'a', 'b', 'c'};
     for (auto& e : b)
         std::cout << e << ' ';
     std::cout << std::endl;
     
 }
