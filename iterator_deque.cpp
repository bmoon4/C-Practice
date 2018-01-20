 // Iterators - Insertion and Removal
 // iterator_deque.cpp

 #include <deque>
 #include <iostream>
// insert(), erase()
 int main() {
     std::deque<double> p(3, 10.50);  //         10.50   10.50   10.50    * ũ��3 ¥�� deque 

     p.back() = 32.43;   // reset last           10.50   10.50   32.43
     p.erase(p.begin()); // remove first         10.50   32.43
     
     for(auto i = p.begin(); i != p.end(); i++){  // 10.50   32.43
	 	std::cout << *i << "  ";
     }
	 std::cout << std::endl;
     
	 p.insert(++p.begin(), 15.64);            //    10.50    15.64    32.43
     p.insert(p.end(), 20.31);                //    10.50    15.64    32.43   20.31  *ũ�Ⱑ �ڵ����� �Ҵ� 
     
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
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
 
 */
