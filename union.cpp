// Unions
 // union.cpp

 #include <iostream>
 #include <cstring>
 
// An object of union type can only hold the value of one of its members at any particular time.  
 union Product { // some have skus, some have upcs 
     int sku;
     char upc[13];
 };

// 그러니까 공용체 Product는 sku만 받거나 upc만 받거나 할수 있는 메모리 공간인거지
// 동시에 다 받을수 없음 - 공간이 한정되있어서!
// 공용체 말마따나 서로 다른 변수가 같은 메모리공간 쓰는 것 뿐.  


 int main() {
     Product cereal, tissue;

     cereal.sku = 4789;
     std::strcpy(tissue.upc, "0360002607555");

     std::cout << cereal.sku << std::endl;
     std::cout << tissue.upc << std::endl; 
 }
