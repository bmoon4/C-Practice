#include <utility>
#include <iostream>



class Student{
	private:
		int no;
		float* grade;
		int ng;
		
	public:
		Student(){ // defalut constructor
		 std::cout << "default constructor" << std::endl;
			no = 0;
			grade = nullptr;
			ng = 0;
		} 
		
		Student(const Student& other){ // copy constructor
		 std::cout << "copy constructor" << std::endl;
		    *this = other;
		} 
		
		
		Student& operator = (const Student& other){  //copy assignment operator
		  std::cout << "copy assignment operator" << std::endl;
			if (this != &other {
         		no = other.no;
         		ng = other.ng;
        		delete [] grade;
         
         		if (other.grade != nullptr) {
             		grade = new float[ng];
             
             		for (int i = 0; i < ng; i++){
						grade[i] = other.grade[i]; 
					 } 	
         		}
         		else {
             		grade = nullptr;
         		}
     		}
     		return *this;
		}
		
		Student(Student&& other){  // move constructor
			 std::cout << "move constructor" << std::endl;
			*this = std::move(other);
		}
		
		
	
		Student& operator = (Student&& other){ // move assignment operator
			 std::cout << "move assignment operator" << std::endl;
			if(&other != this){
				delete [] grade;
				n = other.n;
				ng = other.ng;
				grade = other.grade;
				
				other.n = 0;
				other.ng =0;
				other.grade = nullptr;
				
			}
			return *this;
		}
		
		~Student(){      // destructor
		 std::cout << "destructor" << std::endl;
			delete [] grade;
		}
		
};
