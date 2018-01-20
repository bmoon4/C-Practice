// Sequential Containers - Double-Ended Queues
 // deque.cpp

 #include <deque>  // for deque template
 #include <iostream>
//pop_front(),  pop_back(), push_front(), push_back() 
 int main() {
     std::deque<double> prices(3, 10.50), costs; 

     prices.back() = 32.43; // reset last
     prices.pop_front();    // remove first
     
     for(int i = 0; i < prices.size(); i++){
	   std::cout << prices[i] << "  ";   // 10.5  32.43
 	 }
	 std::cout << std::endl;
     
	 costs = prices;
     costs.push_front(5.64);  // add 5.64 -> 5.64  10.5  32.43
     costs.push_front(20.31); // add 20.31 -> 20.31  5.64  10.5  32.43
     costs.at(1) += 10.0;     // add 10.0
     
	 for(int i = 0; i < costs.size(); i++){
         std::cout << costs[i] << "  ";   // 20.31  15.64  10.5  32.43
 	 }
	 std::cout << std::endl;
 }
 
 /*
 10.5  32.43
 20.31  15.64  10.5  32.43

--------------------------------
Process exited after 1.319 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 */
