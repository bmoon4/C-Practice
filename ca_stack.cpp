// Container Adapters - Stacks
 // ca_stack.cpp

 #include <stack>
 #include <iostream>
//push(), pop()
 int main() {
     std::stack<double> prices; // initially empty 

     prices.push(10.43); // add 10.43     1�� 
     prices.push(20.54); // add 20.54     2�� 
     prices.push(32.43); // add 32.43     3�� 
     
	 prices.top() = 5.41;  // 3���� 32.43�� 5.41�� �ٲ�  top()�� �ְ���! 
     
	 while(!prices.empty()) {
         std::cout << prices.top() << "  ";  // �ְ��� ��� 
         prices.pop();  // �ְ��� ���� 
     }
     std::cout << std::endl;
 }
 
 /*
                       32.43       5.41       5.41 *����� ���� 
            20.54      20.54      20.54      20.54              20.54 *����� ���� 
 10.43      10.43      10.43      10.43      10.43              10.43               10.43 *����� ���� 
 
 */
