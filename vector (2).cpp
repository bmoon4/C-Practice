// Sequential Containers - Vectors
 // vector.cpp

 #include <vector>
 #include <iostream>
//push_back(), pop_back()
 int main() {
     std::vector<double> prices; // initially empty

     if(prices.empty())       // is prices empty?
         std::cout << "prices is empty" << std::endl; 
         
     prices.push_back(10.43); // add 10.43
     prices.push_back(20.54); // add 20.54
     prices.push_back(32.43); // add 32.43
     
	 for(int i = 0; i < prices.size(); i++){
	 	std::cout << prices[i] << "  ";
 	 }
	 
	 std::cout << std::endl;
     
	 prices.front() = 54.11; // change 1st element 
     prices.pop_back();      // remove last element 
     
	 for(int i = 0; i < prices.size(); i++){
         std::cout << prices[i] << "  ";
     } 
	 std::cout << std::endl;
	 
	 /*
	 prices is empty
	10.43  20.54  32.43
	54.11  20.54

	--------------------------------
	Process exited after 1.109 seconds with return value 0
	계속하려면 아무 키나 누르십시오 . . .
	 */
	 
	 
 }
