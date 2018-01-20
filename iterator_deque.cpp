 // Iterators - Insertion and Removal
 // iterator_deque.cpp

 #include <deque>
 #include <iostream>
// insert(), erase()
 int main() {
     std::deque<double> p(3, 10.50);  //         10.50   10.50   10.50    * 크기3 짜리 deque 

     p.back() = 32.43;   // reset last           10.50   10.50   32.43
     p.erase(p.begin()); // remove first         10.50   32.43
     
     for(auto i = p.begin(); i != p.end(); i++){  // 10.50   32.43
	 	std::cout << *i << "  ";
     }
	 std::cout << std::endl;
     
	 p.insert(++p.begin(), 15.64);            //    10.50    15.64    32.43
     p.insert(p.end(), 20.31);                //    10.50    15.64    32.43   20.31  *크기가 자동으로 할당 
     
	 for(auto i = p.begin(); i != p.end(); i++){  // 10.50    15.64    32.43   20.31
         std::cout << *i << "  ";
     }
     std::cout << std::endl;
 }
 /*
 10.5  32.43
 10.5  15.64  32.43  20.31

--------------------------------
Process exited after 0.795 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 
 */
