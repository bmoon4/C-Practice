// Generic Pointers

 #include <iostream>
 #include <iomanip>

 void q(void *a, void *b, int n) {

     unsigned char *ca = (unsigned char *)a;
     unsigned char *cb = (unsigned char *)b;
     unsigned char c;

     for (int i = 0; i < n; i++) {   
         c     = ca[i];
         ca[i] = cb[i];    /// �ڸ��ٲٱⰡ �Ͼ, a�� �ּҰ��� b�� �ּҰ��� �ٲ� 
         cb[i] = c;        // �ݵ�� n�� �ڷ����� ��������� 
     }
 }

 int main() {

     int a = 4, b = 7;
     float x = 2.5f, y = 3.5f;
     char j = 'j', k ='k';

     q(&a, &b, sizeof(int));   // a�� �ּҰ�(1000), b�� �ּҰ�(1004), �� �ּҰ��� ������  
     q(&x, &y, sizeof(float));  // x�� �ּҰ�(1008), y�� �ּҰ�(1012) , 4 
 	 q(&j, &k, sizeof(char));    // j�� �ּҰ�(1013), k�� �ּҰ�(1014), 1 
 	 
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
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
 
 
 */
