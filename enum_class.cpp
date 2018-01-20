// Scoped Enumerations
 // s_enum.cpp

 #include <iostream>

 // define the Colour type
 enum class Colour {white, red, green, blue};

 std::ostream& operator<<(std::ostream& os, const Colour& colour) {
     std::string str;
     
	 switch(colour) {
         case Colour::white:
             str = "white";
             break;
     
	     case Colour::red:
             str = "red";
             break;
     
	     case Colour::green:
             str = "green";
             break;
     
	     case Colour::blue:
             str = "blue";
             break;
     
	     default:
             str = "none";
     }
     
	 os << str.c_str();
     
	 return os;
 }

 int main() {
     
	 Colour wall, ceiling, door; // define Colour variables 
     
	 wall = Colour::red;  //클래스라서 :: 달아줌 
     ceiling = Colour::white;
     door = Colour::green;
     
	 std::cout << wall << ' ' << ceiling << ' ' << door << std::endl;
 }
