 // Initializing Data Members
 // initialize.cpp

 #include <iostream>
 #include <string>

 int nItems = 0;
 
 class Item{
     int item = ++nItems;              // default initializer
     const std::string name {"empty"}; // default initializer 
   public:
     Item() {}   // 2 defaults
     
     Item(const char* n) : name{n} {} // 1 member-list initializer, 1 default
     
	 Item(const char* n, int i) : name{n}, item{i} {} // 2 member-list initializers, 0 defaults
     
	 const char* itemName() const { return name.c_str(); }
     
	 int itemNo() const { return item; }
 };

 int main() {
     std::cout << nItems << std::endl;
   
     Item a;
     std::cout << a.itemName() << ' ' << a.itemNo() << '\n';
   
     Item b("apple");
     std::cout << b.itemName() << ' ' << b.itemNo() << '\n';
   
     Item c("grape", 6);
     std::cout << c.itemName() << ' ' << c.itemNo() << '\n';
   
     std::cout << nItems << std::endl;
 }
