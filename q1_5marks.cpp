#include <iostream>
#include <utility>

// by Bokyung Moon
// Question 1-2 => 5marks

/*
	Add functions required to demonstrate the Rule of Five
	- a defalut safe state constructor.(a zombie - alive but no brains)
	- a constructor with a size_t size parameter. It allocates a 'T' table of that size.(brain)
	- the member functions required to complete the C++ 'rule-of-three'
	- the remaining member functions required to complete the C++11 'rule-of-five'
	- each member function prints the object memory size.
	
	
	Demonstrate calling the 'rule-of-five'
	- Write sample code that exercises the rule-of-five member functions
	- Move something with a large data size back and forth between a pair of object
	- Show the expected print output. These prints prove correct program operation
*/

template <class T>
class X{
	
	size_t size = 0;    // number of 'T' units in table 'data', may be zero. 
	T* data = nullptr; 	//pointer to a table of 'size' type 'T' elements  

	public:
	// these are methods of the class X	
		
		X(){                      // default constructor
	 		size = 0;
	 		data = nullptr;
	 		std::cout << "생성! ";
	 		memorySize();
	 	}
	 
	 	X(size_t _size){          // constructor with a size_t parameter
	 		size = _size;
	 		data = new T[_size]; 
	 		std::cout << "생성! ";
	 		memorySize();
	 	}
	   
	    
		X(size_t _size, T* _data){ // constructor with size_t and T* parameters

			if (_data != nullptr) {
         		size = _size;
         		data = new T[size];
                
				for (int i = 0; i < size; i++){
						data[i] = _data[i];
				}
         	} 
			else {
         		data = nullptr;
         		*this = X();
     		}
     		std::cout << "생성! ";
     		memorySize();
	 	}
	 
	 	X(const X& other){       // copy constructor (rule of 3)
		    *this = other;
		    std::cout << "복사생성! ";
		    memorySize();
	 	}
	
		X& operator=(const X& other){  // copy assignment operator (rule of 3)
			if (this != &other) {
         		size = other.size;
        		delete [] data;
         
         		if (other.data != nullptr) {
             		data = new T[size];
             		
             		for (int i = 0; i < size; i++){
						data[i] = other.data[i]; 
					 } 	
         		}
         		else {
             		data = nullptr;
         		}
     		}
     		std::cout << "복사대입연산! ";
     		memorySize();
     		return *this;
		}	
	
		X(X&& other){           // move constructor (rule of 5)
	 	    *this = std::move(other);
	 	    std::cout << "이동 생성! ";
	 		memorySize();
		}	
	
		X& operator=(X&& other){       // move assignment operator (rule of 5)
			if(&other != this){
				delete [] data;
				size = other.size;
				data = other.data;
				
				other.size = 0;
				other.data = nullptr;	
			}
			std::cout << "이동대입연산! ";
			memorySize();
			return *this;
		}
	
		~X(){	               // destructor
		 delete [] data;
		 std::cout <<"~소멸 ";
		 memorySize();
	}
	
	void memorySize(){         // a method for printing size of the instance
		std::cout << "memory size: "  << sizeof(*this) << std::endl;
	}
	
	size_t Size() const{      // a method to return the size of the instance
		return size;
	}
	
	T& operator[] (size_t i){  // an operator to return the element of a table which T* pointer is indicating
		return data[i];      
	}
	
};

int main(){

	char dummy[] ={'c', 'a', 'n', 'a', 'd', 'a'};
	
	X<char> a(sizeof(dummy)/sizeof(dummy[0]), dummy); // 'a' has values
	X<char> b;                                        // 'b' is empty
	
	
	/* let's use copy assignment operator */
	
    std::cout << "Copy-Assignment (b = a)" << std::endl;
	std::cout << "object a : ";
	
	//print a
	for(size_t i = 0 ; i < a.Size(); i++){
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;

	// Copy a to b
	b = a;
	
	//print b
	std::cout << "object b : ";
	for(size_t i = 0 ; i < b.Size(); i++){  // now b has the same value
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;
	
	//print a
	std::cout << "object a : ";
	for(size_t i = 0 ; i < a.Size(); i++){  // a still has value
		std::cout << a[i] << ' ';
	}

	std::cout << std::endl;
	std::cout << std::endl;

	
	/*let's use move assignment operator */

	std::cout << "Move-Assignment (a -> b)" << std::endl;
	std::cout << "object a : ";
	
	//print a
	for(size_t i = 0 ; i < a.Size(); i++){
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;

	// move a into b
	b = std::move(a);
	
	//print b
	std::cout << "object b : ";
	for(size_t i = 0 ; i < b.Size(); i++){  // now b has the same value
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;
	
	//print a
	std::cout << "object a : ";
	for(size_t i = 0 ; i < a.Size(); i++){  // a is empty now
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
		std::cout << std::endl;
	
	
	
	/*let's use move constructor */
	
	std::cout << "Move-Constructor (b -> c)" << std::endl;
    
    std::cout << "object b : ";
	for(size_t i = 0 ; i < b.Size(); i++){  // b has value
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;
	
	
	X<char> c(std::move(b)) ; // using move constructor (b->c)
	
	
	std::cout << "object c : ";
	for(size_t i = 0 ; i < c.Size(); i++){  // c has b's value!
		std::cout << c[i] << ' ';
	}
	std::cout << std::endl;
	
	std::cout << "object b : ";
	for(size_t i = 0 ; i < b.Size(); i++){  // b is empty
		std::cout << b[i] << ' ';
	}
	std::cout << std::endl;
std::cout << std::endl;
	
    std::cout << "Copy-Constructor (c = d)" << std::endl;
	std::cout << "object c : ";
	//print c
	for(size_t i = 0 ; i < c.Size(); i++){
		std::cout << c[i] << ' ';
	}
	std::cout << std::endl;
	
	X<char> d(c);
	//print d
		std::cout << "object d : ";
	for(size_t i = 0 ; i < d.Size(); i++){
		std::cout << d[i] << ' ';
	}
	std::cout << std::endl;
		std::cout << std::endl;	
		std::cout << std::endl;
}
/*

In 64 bit environment : size_t (8 bytes), size of pointer(8 bytes) (my laptop uses 64 bit)
In 32 bit environment : size_t (4 byte), size of pointer(4 bytes)


output:

memory size: 16 ( size_t size is 8 byte + T* data is 8 byte => 16!! ) 
memory size: 16
Copy-Assignment (b = a)
object a : c a n a d a
memory size: 16
object b : c a n a d a
object a : c a n a d a

Move-Assignment (a -> b)
object a : c a n a d a
memory size: 16
object b : c a n a d a
object a :

Move-Constructor (b -> c)
object b : c a n a d a
memory size: 16
memory size: 16
object c : c a n a d a
object b : 

--------------------------------
Process exited after 0.07225 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .


                                                 Good luck guys! 
*/


