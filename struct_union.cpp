// Structs with Unions
 // struct_union.cpp

 #include <iostream>
 #include <cstring>

 enum ProductId {sku, upc}; // �̳ѵ���....(�󺧸��̶�� ��������) 

 typedef struct {
     ProductId id;
     
	 union { // some have skus, some upcs
         int  sku;
         char upc[13];
     } code; // ����ü �̸� 
     
 } Product; // ����ü �̸� 

 
 int main() {
     Product p[2]; // ����ü �迭 2�� ����  (0��, 1��) 

     p[0].id = sku;            // ����ü 0���� id(enum)�� sku 
     p[0].code.sku = 4789;     // ����ü 0���� code(����ü)�� sku�� 4789 
     
     p[1].id = upc;            // ����ü 1���� id(enum)�� upc 
     std::strcpy(p[1].code.upc, "0360002607555"); // ����ü 1���� code(����ü)�� upc�� 0360002607555  


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
