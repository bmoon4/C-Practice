// Unions
 // union.cpp

 #include <iostream>
 #include <cstring>
 
// An object of union type can only hold the value of one of its members at any particular time.  
 union Product { // some have skus, some have upcs 
     int sku;
     char upc[13];
 };

// �׷��ϱ� ����ü Product�� sku�� �ްų� upc�� �ްų� �Ҽ� �ִ� �޸� �����ΰ���
// ���ÿ� �� ������ ���� - ������ �������־!
// ����ü �������� ���� �ٸ� ������ ���� �޸𸮰��� ���� �� ��.  


 int main() {
     Product cereal, tissue;

     cereal.sku = 4789;
     std::strcpy(tissue.upc, "0360002607555");

     std::cout << cereal.sku << std::endl;
     std::cout << tissue.upc << std::endl; 
 }
