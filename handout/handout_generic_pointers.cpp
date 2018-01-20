// Generic Pointers

 #include <iostream>
 #include <iomanip>

 void q(void *a, void *b, int n) {

     unsigned char *ca = (unsigned char *)a;
     unsigned char *cb = (unsigned char *)b;
     unsigned char c;

     for (int i = 0; i < n; i++) {   
         c     = ca[i];
         ca[i] = cb[i];    /// 자리바꾸기가 일어남, a의 주소값과 b의 주소값을 바꿈 
         cb[i] = c;        // 반드시 n은 자료형의 사이즈여야함 
     }
 }

 int main() {

     int a = 4, b = 7;
     float x = 2.5f, y = 3.5f;
     char j = 'j', k ='k';

     q(&a, &b, sizeof(int));   // a의 주소값(1000), b의 주소값(1004), 각 주소값의 사이즈  
     q(&x, &y, sizeof(float));  // x의 주소값(1008), y의 주소값(1012) , 4 
 	 q(&j, &k, sizeof(char));    // j의 주소값(1013), k의 주소값(1014), 1 
 	 
     std::cout << std::setprecision(1) << std::fixed;
     std::cout << "(a,b) = (" << a << ',' << b << ')' << std::endl;
     std::cout << "(x,y) = (" << x << ',' << y << ')' << std::endl; 
     std::cout << "(j,k) = (" << j << ',' << k << ')' << std::endl; 
 }
 
 /*
 (a,b) = (7,4)
 (x,y) = (3.5,2.5)
 (j,k) = (k, j)

--------------------------------
Process exited after 1.276 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 
 
 */
