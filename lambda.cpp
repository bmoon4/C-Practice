// Lambda Expressions
 // lambda.cpp
/*
 A lambda expression takes the form

 [capture-list](parameter-declaration-clause)-> optional-return-type {
     // function body
 }

	capture-list is an optional comma separated list of the capture specifications 
	for the non-local variables accessed by the function body. 
	parameter-declaration-clause is a comma separated list of the parameters that receive 
	values of local variables within the scope of the function body.  


*/
 #include <iostream>

 int main() {
     // lambda expressions
     //람다: 이름없는 함수 (자바스크립트에서 var add = function(int a, int b){} 라던가  var add = (int a, int b)=>{} 를 떠올려보기  
     auto hello = []() { return "Hello World"; };
     auto add4  = [](int i) { return i + 4; };
     auto sub4  = [](int i) { return i - 4; };

     // calls on the lambda expressions
     std::cout << hello()  << std::endl;   // Hello World
     std::cout << add4(10) << std::endl;   // 14
     std::cout << sub4(10) << std::endl;   // 4
 }
