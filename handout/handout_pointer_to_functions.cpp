// Pointers to Functions

 #include <iostream>
 using namespace std;

 int flat(int x)  { return 10; }
 int line(int x)  { return x + 1; }
 int para(int x)  { return x * x + 2 * x + 1; }

 int area(int start, int end, int inc, int (*f)(int)) {
     int i, a;

     a = 0;
     for (i = start; i < end; i += inc)
         a += f(i) * inc;

     return a;
 }

 int main () {

     cout << "Under flat " << area(0, 5, 1, flat) << endl;
     cout << "Under line " << area(0, 5, 1, line) << endl;
     cout << "Under para " << area(0, 5, 1, para) << endl;
 }
 /*
 Under flat 50
 Under line 15
 Under para 55

--------------------------------
Process exited after 1.294 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 
 
 */
