#include <iostream>
using namespace std;
/// ---------------------- �������� ���ø� -------------------------///
 
// (A) ��� ���ø� ���� ����.
template <typename T >
void print(const T& firstArg){
    cout << firstArg << endl;
}
 
// �������� ���ø� (... types)
template <typename T, typename ... Types >
void print(const T& firstArg, const Types& ...argv){
    cout << firstArg << endl; // ù ��° ���ڸ� ���
    print(argv...);           // ������ ���ڿ� ���� ����� ȣ��, ���ڰ� �ϳ� ������ �� (A)�� ȣ��� ���̴�.
}
 
 
int main(){
    print( "STL", "Quiz", 1, 3.14, "�ȳ��ϼ���", 1.0f, "�������� ���ø�", "���� ���ø�");
}

/* ��Ʈ�� ���� �ڵ嵵 ���� �ڵ��.  

#include <iostream>

 template <typename T>
 void print(const T& t) {
     std::cout << t << std::endl;
 }

 template <typename T, typename... etc>
 void print(const T& t,const etc&... pp) { 
     std::cout << t << " | ";
     print(pp...);
 }

 int main() {
     print(100);
     print("abcd", 100, 34.56);
 }



*/
