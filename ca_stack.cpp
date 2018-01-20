// Container Adapters - Stacks
 // ca_stack.cpp

 #include <stack>
 #include <iostream>
//push(), pop()
 int main() {
     std::stack<double> prices; // initially empty 

     prices.push(10.43); // add 10.43     1층 
     prices.push(20.54); // add 20.54     2층 
     prices.push(32.43); // add 32.43     3층 
     
	 prices.top() = 5.41;  // 3층의 32.43을 5.41로 바꿈  top()은 최고층! 
     
	 while(!prices.empty()) {
         std::cout << prices.top() << "  ";  // 최고층 출력 
         prices.pop();  // 최고층 삭제 
     }
     std::cout << std::endl;
 }
 
 /*
                       32.43       5.41       5.41 *출력후 삭제 
            20.54      20.54      20.54      20.54              20.54 *출력후 삭제 
 10.43      10.43      10.43      10.43      10.43              10.43               10.43 *출력후 삭제 
 
 */
