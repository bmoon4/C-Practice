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
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .

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
             a = new int[src.n]; // ��������ڿ��� new �����Ҵ��ʿ� 
             for (unsigned i = 0u; i < src.n; ++i)
                 a[i] = src.a[i];
             n = src.n;
         }
         return *this;
     }
     Array& operator=(Array&& src) { // move assignment operator //  b = std::move(a); // calls move-assignment
         if (this != &src) {                                     // a�� ������ b�� �ű�� 
         	 delete [] a;
         	 				// �̵������ڿ��� new �����Ҵ��� ����.  
             a = src.a;		// �����ʹ� ������ �޸𸮸� ����Ű�� �ǰ� 
             n = src.n;     // ������Ƽ����� �������縸 �ؼ� 
             dummy = src.dummy;
             
             src.a = nullptr;   //������ �� null�̳� 0���� ����� �׸�  
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
