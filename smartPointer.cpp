#include <iostream>

using namespace std;

class My{

    int m_A;
	int m_B;

	public:
		My (int a=0, int b=0){
			m_A = a;
        	m_B = b;
		}

    	~My(){}
		
		void Print() const{
			cout << "a: " << m_A << "  b: " << m_B << endl;
		}
 };


//////////////////////////////////////


 class MyPtr{

 	My* m_My;

	public:
		MyPtr (My* my){
			m_My = my;
		}

        ~MyPtr(){
			delete m_My;
		}


        My* operator->() const{
			return m_My;
		}

 };


/////////////////////////////////////////


 int main(){

        My my1(50, 60);
        my1.Print();
		
		MyPtr my2 = new My(10, 20);
		my2->Print();

		

		return 0;
}


