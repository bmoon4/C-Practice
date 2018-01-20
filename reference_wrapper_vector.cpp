// Functional - reference wrapper
 // reference_wrapper_vector.cpp

 #include <iostream>
 #include <vector>
 #include <functional>

 int main() {
     std::vector<double> v(5, 10.3); // 사이즈는 5, 모든 원소는 10.3으로 세팅된 벡터 v 선언 
     std::vector<std::reference_wrapper<double>> r(v.begin(), v.end()); // 해석이 필요
	 // vector의 타입은 std::reference_wrapper<double> 이고 
	 // 이름은 r 이고
	 // v.begin() , v.end()의 값을 가지고 있음 
	 // 결국 r은 v의 레퍼런스라는 소리임 
     for (auto& i : v)
         i *= 3;            // 벡터 v 안의 원소에 3을 곱함 
         
     for (auto i : r)       //  벡터 r의 내용물 출력 
        std::cout << i << " ";
     /*
	  30.9 30.9 30.9 30.9 30.9 출력 
	 */
	 std::cout << std::endl; 
 }
