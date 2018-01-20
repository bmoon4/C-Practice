// Inserting Enumeration Constants
 // i_enum.cpp

 #include <iostream>

 // define the Colour type
 enum class Colour {white, yellow, red, green, blue}; // added yellow 

 std::ostream& operator<<(std::ostream& os, const Colour& colour) {
     std::string str;
     
	 switch(colour) {
         case Colour::white:
             str = "white";
             break;
     
	     case Colour::yellow:
             str = "yellow"; 
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
     Colour wall, ceiling, door, window;
     
	 wall = Colour::red;
     ceiling = Colour::white;
     door = Colour::green;
     window = Colour::yellow;
     
	 std::cout << wall << ' ' << window << ' ' << ceiling << ' ' << door << std::endl;
 }
