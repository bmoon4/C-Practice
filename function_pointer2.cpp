// Function Pointers
 // function_pointers.cpp
// 오름차순, 내림차순 정렬해주는 기능을 가진 두 함수를
// 함수포인터로 만들어서
// sort함수에 파라미터로 삽입 
 #include <iostream>

 // ascending order comparison(함수템플릿1) 
 template <typename T>
 bool ascending(T a, T b) { return a > b; }

 // descending order comparison (함수템플릿2) 
 template <typename T>
 bool descending(T a, T b) { return a < b; }

 // bubble sortm(함수템플릿3) 
 template <typename T>
 void sort(T* a, int n, bool (*comp)(T, T)) {     // 분류할 배열, 배열의 사이즈, 함수의 종류 ex) sort(a, n, ascending<int>); 
     for (int i = n - 1; i > 0; i--) {            //  ascending<int>만 넣어줘도 되는 이유: 함수이름이 곧 함수메모리주소이기때문 (배열처럼) 
         for (int j = 0; j < i; j++) {
             if (comp(a[j], a[j+1])) {
                 T temp = a[j];
                 a[j] = a[j+1];
                 a[j+1] = temp;
             }
         }
     }
 }

 template <typename T>
 void display(T* a, int n) {
     for (int i = 0; i < n; i++)
         std::cout << a[i] << ' ';
     std::cout << std::endl;
 }

 int main() {
     int a[] = {1, 5, 2, 3, 6, 7, 2};
     int n = sizeof a / sizeof (int);

     sort(a, n, ascending<int>);
     display(a, n);
	
	/*
	The type specialization <int> in the call to the sort function addresses the ambiguity regarding the type to be compared.  
	Without this specialization, the compiler cannot determine for which type to generate comparison code.  
	*/
     sort(a, n, descending<int>);
     display(a, n);
 }
 /*
 1 2 2 3 5 6 7
7 6 5 3 2 2 1

--------------------------------
Process exited after 1.387 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 */
