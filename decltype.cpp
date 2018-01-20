// decltype with templates
 // decltype.cpp

 /*
 decltype (C++11)
 decltype Ű����� Ư�� ǥ������ Ÿ���� �˷��ִ� Ű����.
 ������ decltype (��expression��)

 ���δٸ� �ڷ��� �� ���� �������� � �ڷ����� ����?
                    -> decltype Ű���尡 �ڷ����� �Ǵ����ش�.

 */



 #include <iostream>
 
 template<typename T, typename U>
 auto add(const T& t, const U& u) -> decltype(t + u) { return t + u; } 
 // � Ÿ������ ��ȯ���� �����̹Ƿ� auto ó����  
 

 int main() {
     int i = 3, j = 6;
     double x = 4.5;
     std::string y = "�ȳ�";
	 std::string z = "�ϼ���!";
	 
     std::cout << add(i, j) << std::endl;    // 9
     std::cout << add(i, x) << std::endl;    // 7.5
     std::cout << add(y, z) << std::endl;    // �ȳ��ϼ���! 
 }
