// Function Pointers
 // function_pointers.cpp
// ��������, �������� �������ִ� ����� ���� �� �Լ���
// �Լ������ͷ� ����
// sort�Լ��� �Ķ���ͷ� ���� 
 #include <iostream>

 // ascending order comparison(�Լ����ø�1) 
 template <typename T>
 bool ascending(T a, T b) { return a > b; }

 // descending order comparison (�Լ����ø�2) 
 template <typename T>
 bool descending(T a, T b) { return a < b; }

 // bubble sortm(�Լ����ø�3) 
 template <typename T>
 void sort(T* a, int n, bool (*comp)(T, T)) {     // �з��� �迭, �迭�� ������, �Լ��� ���� ex) sort(a, n, ascending<int>); 
     for (int i = n - 1; i > 0; i--) {            //  ascending<int>�� �־��൵ �Ǵ� ����: �Լ��̸��� �� �Լ��޸��ּ��̱⶧�� (�迭ó��) 
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
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
 */
