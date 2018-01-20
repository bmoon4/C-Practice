#include <iostream>
#include <utility>
// by Bokyung Moon
// Question 1-1 => 10marks

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
		
		Student(int sn) {  // constructor with a parameter
			std::cout << "constructor with a parameter" << std::endl;
     		float g[] = {0.0f};
     		grade = nullptr;
     		*this = Student(sn, g, 0);
 		}
		
		
		Student(int sn, const float* g, int ng_) { // constructor with 3 parameters
		 	std::cout << "constructor with 3 parameters" << std::endl;
     		
			bool valid = sn > 0 && g != nullptr && ng_ >= 0; 
     		
			if (valid){
				for (int i = 0; i < ng_ ; i++){
					valid = g[i] >= 0.0f && g[i] <= 100.0f;
				}
		    }

			if (valid) {
         		no = sn;
         		ng = ng_;
         
         		if (ng > 0) {
             		grade = new float[ng];
             		
					for (int i = 0; i < ng; i++){
						grade[i] = g[i];
				    }
         		} 
				else {
             		grade = nullptr;
         		}
     		} 
			else {
         		grade = nullptr;
         		*this = Student();
     		}
 		}
		
		
		Student(const Student& other){ // copy constructor (rule of 3)
			std::cout << "copy constructor" << std::endl;
		    *this = other;
		} 
		
		
		Student& operator = (const Student& other){  //copy assignment operator (rule of 3)
			std::cout << "copy assignment operator" << std::endl;
			if (this != &other) {
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
		
		Student(Student&& other){  // move constructor (rule of 5)
			std::cout << "move constructor" << std::endl;
			*this = std::move(other);
		}
		
		
		Student& operator = (Student&& other){ // move assignment operator (rule of 5)
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
		
		~Student(){      // destructor (rule of 3)
			std::cout << "destructor" << std::endl;
			delete [] grade;
		}
		
};
