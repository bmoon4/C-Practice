// Exception Handling
 // exceptions.cpp

 #include <iostream>

 void divide(double a[], int i, int n, double divisor) {
     
	 if(i < 0 || i >= n)
         throw "Outside bounds";
     else if(i == n / 2)
         throw i;
     else if(divisor == 0)
         throw divisor;
     else
         a[i] = i / divisor;
 }

 int main() {
     bool keepdividing = true;
     double a[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6}, divisor;
     int i, n = sizeof a / sizeof a[0];

     do {
         try {
             std::cout << "Index: ";
             std::cin >> i;
             std::cout << "Divisor: ";
             std::cin >> divisor;
             divide(a, i, n, divisor);
             std::cout << "a[i] = " << a[i] << std::endl;
             std::cout << "Continuing ..." << std::endl;
         
		 } catch(const char* msg) {
             std::cout << msg << std::endl;
             keepdividing = false;
         
		 } catch(int& value) {
             std::cout << "Index is " << value << std::endl; 
             std::cout << "a[i] = " << a[i] << std::endl;
             std::cout << "Continuing ..." << std::endl;
         
		 } catch(...) {
             std::cout << "Zero Division!" << std::endl; 
             std::cout << "a[i] = " << a[i] << std::endl;
             std::cout << "Continuing ..." << std::endl;
         }
     } while (keepdividing);
 }
