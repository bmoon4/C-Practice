// Structs with Unions
 // struct_union.cpp

 #include <iostream>
 #include <cstring>

 enum ProductId {sku, upc}; // 이넘등장....(라벨링이라고 생각하자) 

 typedef struct {
     ProductId id;
     
	 union { // some have skus, some upcs
         int  sku;
         char upc[13];
     } code; // 공용체 이름 
     
 } Product; // 구조체 이름 

 
 int main() {
     Product p[2]; // 구조체 배열 2개 생성  (0번, 1번) 

     p[0].id = sku;            // 구조체 0번의 id(enum)은 sku 
     p[0].code.sku = 4789;     // 구조체 0번의 code(공용체)의 sku를 4789 
     
     p[1].id = upc;            // 구조체 1번의 id(enum)은 upc 
     std::strcpy(p[1].code.upc, "0360002607555"); // 구조체 1번의 code(공용체)의 upc를 0360002607555  


    for (int i = 0; i < 2; i++)
         switch(p[i].id) {
           case sku:
               std::cout << p[i].code.sku << std::endl;
               break;
           case upc:
               std::cout << p[i].code.upc << std::endl; 
               break;
         }
 }
