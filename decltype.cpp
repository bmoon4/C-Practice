// decltype with templates
 // decltype.cpp

 /*
 decltype (C++11)
 decltype 키워드는 특정 표현식의 타입을 알려주는 키워드.
 문법은 decltype (‘expression’)

 서로다른 자료형 두 개를 더했을때 어떤 자료형을 리턴?
                    -> decltype 키워드가 자료형을 판단해준다.

 */



 #include <iostream>
 
 template<typename T, typename U>
 auto add(const T& t, const U& u) -> decltype(t + u) { return t + u; } 
 // 어떤 타입으로 반환할지 미정이므로 auto 처리함  
 

 int main() {
     int i = 3, j = 6;
     double x = 4.5;
     std::string y = "안녕";
	 std::string z = "하세요!";
	 
     std::cout << add(i, j) << std::endl;    // 9
     std::cout << add(i, x) << std::endl;    // 7.5
     std::cout << add(y, z) << std::endl;    // 안녕하세요! 
 }
