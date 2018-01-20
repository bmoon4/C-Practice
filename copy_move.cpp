// Copy and Move
 // copy_move.cpp
 #include <iostream>
 #include <utility>



/*
Copy-Assignment
a : 0 3 6 9 12
b : 0 3 6 9 12
a : 0 3 6 9 12
Move-Assignment
a : 0 3 6 9 12
b : 0 3 6 9 12
a :

--------------------------------
Process exited after 1.501 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .

*/
 class Array {
     int* a = nullptr;
     unsigned n = 0u;
     int dummy = 0;
 public:
     Array(){}
     
     Array(unsigned no) : a(new int[no]), n(no){}
     
	 Array(const Array& src) { *this = src; }
     
	 Array(Array&& src) { *this = std::move(src); } // move constructor - rvalue!!!!!!!! 
     
	 Array& operator=(const Array& src) {
         if (this != &src) {
             delete [] a;
             a = new int[src.n]; // 복사생성자에는 new 동적할당필요 
             for (unsigned i = 0u; i < src.n; ++i)
                 a[i] = src.a[i];
             n = src.n;
         }
         return *this;
     }
     Array& operator=(Array&& src) { // move assignment operator //  b = std::move(a); // calls move-assignment
         if (this != &src) {                                     // a의 내용을 b에 옮기기 
         	 delete [] a;
         	 				// 이동생성자에는 new 동적할당이 없다.  
             a = src.a;		// 포인터는 원본의 메모리를 가리키면 되고 
             n = src.n;     // 프리미티브들은 얕은복사만 해서 
             dummy = src.dummy;
             
             src.a = nullptr;   //원본은 다 null이나 0으로 만들면 그만  
             src.n = 0u;
             src.dummy = 0;
         }
         return *this;
     }
     ~Array() { delete [] a; }
     
     int& operator[](unsigned i) {
         return n > 0u && i < n ? a[i] : dummy; }
     
	 int operator[](unsigned i) const {
         return n > 0u && i < n ? a[i] : dummy; }
     
	 unsigned size() const { return n; }
 };

 int main() {
     const unsigned size = 5;
    
	 Array a(size), b;
    
	 for (unsigned i = 0u; i < a.size(); ++i)
         a[i] = 3 * i;

     std::cout << "Copy-Assignment\n";
     std::cout << "a : ";
    
	 for (unsigned i = 0u; i < a.size(); ++i)
         std::cout << a[i] << ' ';
     std::cout << std::endl;
    
	 b = a; // calls copy-assignment
     std::cout << "b : ";
     for (unsigned i = 0u; i < b.size(); ++i)
         std::cout << b[i] << ' ';
     std::cout << std::endl;
     std::cout << "a : ";
    
	 for (unsigned i = 0u; i < a.size(); ++i)
         std::cout << a[i] << ' ';
     std::cout << std::endl;

     std::cout << "Move-Assignment\n";
     std::cout << "a : ";
    
	 for (unsigned i = 0u; i < a.size(); ++i)
         std::cout << a[i] << ' ';
     std::cout << std::endl;
    
	 b = std::move(a); // calls move-assignment
     std::cout << "b : ";
    
	 for (unsigned i = 0u; i < b.size(); ++i)
         std::cout << b[i] << ' ';
     std::cout << std::endl;
    
	 std::cout << "a : ";
     for (unsigned i = 0u; i < a.size(); ++i)
         std::cout << a[i] << ' ';
    
	 std::cout << std::endl;
 }
