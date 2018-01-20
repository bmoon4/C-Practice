// Lambda Expressions
 // capture_by_value.cpp

 #include <iostream>

 template<typename Func> // 함수 템플릿 1 
 int add(int i, Func func) { return func(i); }

 template<typename Func>  // 함수 템플릿 2 
 int sub(int i, Func func) { return func(i); }
 
// [=] denotes capture by value. 

/* 람다: 이름없는 함수 (자바스크립트에서 var add = function(int a, int b){} 라던가  var add = (int a, int b)=>{} 를 떠올려보기  

	[] 는 일단 캡처라 부르며, 이전 scope에서 선언된 변수들을 사용 할 수있게 할것인지 설정하는 부분이라고 이해함

	[=]로 작성하게 되면, 이전 scope의 모든 변수를 call by value 형태로 사용 

	[&]로 작성하게 되면, call by reference 형태로 사용해서 데이터 자체를 변경하면 이전 scope의 변수 자체 데이터 값도 변경 가능하게 함

*/
 int main() {
     int k = 4;
     
     std::cout << add(10, [=](int i){ return i + k; }) << std::endl;   // 14
     std::cout << sub(10, [=](int i){ return i - k; }) << std::endl;   // 6
 }
 
 
  /* add 라는 함수에 패러미터를 (정수형 숫자 , 함수) 이렇게 넣는데
  함수 부분을 별도로 만들어서 함수포인터로 집어 넣은게 아니라
  아예 패러미터에다가 함수를 새로 파버림* 
  
    [=](int i){
		return i+k;
	}
	
	라는 (람다)함수를 만들어서 add 함수의 패러미터로 넘겨버린것
	
	근데 add함수의 내용을 보자  
	 
	 int add(int i(여기에 10이 들어가고), Func func(여기에 람다함수들어감)) { 
	 	return func(i); 
	 }
	 
	 Func func 부분에 람다함수가 들어가는데
	 add에서 return을 보면 그 람다함수를 다시 쳐부르고 앉았다
	 
	 그럼 패러미터로 들어간 람다함수를 다시 봐야한다
	 
	 i가 10, k가 4이므로
	 
	 [=](10){
	 	return 10 + 4;
	}
	 
	 결국에 14가 반환된다. 
	 
	 
	 잘 생각해보면 이건 콜백함수의 개념이다. 
	 자바스크립트에서 배운 것은 함수도 객체이며, 다른 함수의 패러미터로 삽입이 가능하다는 것이었다.
	  이걸 똑같이 c++에서도 구현이 가능하다
	  
	  함수포인터로 다른 함수에 패러미터로 넘기거나
	  아니면 람다표현식으로 패러미터에 함수를 새로 파거나. 
	  
	어려운 내용아니다. 다시 복습해보자.  
  
  / 
