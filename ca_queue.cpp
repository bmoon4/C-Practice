 // Container Adapters - Queues
 // ca_queue.cpp

 #include <queue>
 #include <iostream>
//push(), pop()
 int main() {
     std::queue<int> tickets; // initially empty 

     tickets.push(10); // add 10
     tickets.push(20); // add 20
     tickets.push(32); // add 32
     tickets.back() = 30;  // 32->30
     
     while(!tickets.empty()) {
         std::cout << tickets.front() << "  "; 
         tickets.pop();
     }
     std::cout << std::endl;
 }
 
 /*
 						10 <- �����¹���  
 						10    				20
 						10    				20        		32
 						10    				20 		  		30 (tickets.back() = 30)
   <- �����¹���		10 *����� pop      20        		30 
 						20 *����� pop		30
						30 *����� pop  
 
 */
