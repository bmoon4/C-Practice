#include <iostream>
using namespace std;
/// ---------------------- 가변인자 템플릿 -------------------------///
 
// (A) 재귀 템플릿 종료 조건.
template <typename T >
void print(const T& firstArg){
    cout << firstArg << endl;
}
 
// 가변인자 템플릿 (... types)
template <typename T, typename ... Types >
void print(const T& firstArg, const Types& ...argv){
    cout << firstArg << endl; // 첫 번째 인자를 출력
    print(argv...);           // 나머지 인자에 대해 재귀적 호출, 인자가 하나 남았을 때 (A)가 호출될 것이다.
}
 
 
int main(){
    print( "STL", "Quiz", 1, 3.14, "안녕하세요", 1.0f, "가변인자 템플릿", "제귀 템플릿");
}

/* 노트에 나온 코드도 같은 코드다.  

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
