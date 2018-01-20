// rvalue Reference using std::move()
// std_move.cpp
// An rvalue reference declaration identifies an object that is less permanent, possibly temporary.

 #include <iostream>
 #include <utility>

 class A {
     int a;
   public:
     A(int aa) : a(aa) {}
     void display(const char* str) const {
         std::cout << str << ' ' << a << std::endl;
     }
 };

 void print(const A& a) { a.display("lvalue "); }
 void print(A&& a)      { a.display("rvalue "); }

 int main() {
     A a(10), b(20);
     print(a);
     print(std::move(b)); // cast to rvalue using the std::move() function -> rvalue!
     print(A(30));   // a temporary object -> rvalue!
 }
 
 // output
 // lvalue  10
 // rvalue  20
 // rvalue  30
