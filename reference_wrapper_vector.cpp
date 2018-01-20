// Functional - reference wrapper
 // reference_wrapper_vector.cpp

 #include <iostream>
 #include <vector>
 #include <functional>

 int main() {
     std::vector<double> v(5, 10.3); // ������� 5, ��� ���Ҵ� 10.3���� ���õ� ���� v ���� 
     std::vector<std::reference_wrapper<double>> r(v.begin(), v.end()); // �ؼ��� �ʿ�
	 // vector�� Ÿ���� std::reference_wrapper<double> �̰� 
	 // �̸��� r �̰�
	 // v.begin() , v.end()�� ���� ������ ���� 
	 // �ᱹ r�� v�� ���۷������ �Ҹ��� 
     for (auto& i : v)
         i *= 3;            // ���� v ���� ���ҿ� 3�� ���� 
         
     for (auto i : r)       //  ���� r�� ���빰 ��� 
        std::cout << i << " ";
     /*
	  30.9 30.9 30.9 30.9 30.9 ��� 
	 */
	 std::cout << std::endl; 
 }
