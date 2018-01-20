 // Postfix, Prefix, and Unary Expressions

 #include <iostream>
 using namespace std;

 char* reverse(char *out, const char *in) { // reverse(copy, name)
     unsigned int length = 0;
     char *p = out;

     while(*in++ != '\0') length++;
     in--;
		
     while (length-- != '\0') {
         *p++ = *--in;
         cout << p[-1] << ' ';
     }
     *p = '\0';
     return out;
 }

 int main() {
     char name[] = "star";
     char copy[5];

     cout << "=>" << reverse(copy, name) << endl;
     
	 reverse(name, copy)[3] = 'y';
     cout << "=>" << name << endl;
 }
 
 /*
 r a t s =>rats
 s t a r =>stay

--------------------------------
Process exited after 1.394 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 */
