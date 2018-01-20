// Enumerations, Synonyms and Storage Duration

 #include <iostream>

 enum TrafficLight {red, yellow, green};
 typedef enum TrafficLight Signal;

 void display (Signal s) {

     switch (s) {
     case red:    std::cout << "red" << std::endl;    break;
     case yellow: std::cout << "yellow" << std::endl; break;
     case green:  std::cout << "green" << std::endl;  break;
     }
 }

 void change (Signal *s) {
     static int second = 0;

     switch (*s) {
     case red:
         if(second%3 == 2) {
             *s = green;
             second = 0;
         } else {
             second++;
         }
         break;
         
     case yellow: 
	 	*s = red; 
		second = 0; break;
     
	 case green:
         if(second%3 == 2) {
             *s = yellow;
             second = 0;
         } else {
             second++;
         }
         break;
     }
 }

 int main() {
     Signal keeleAtFinch = red;

     for (int i = 0; i < 10; i++) {
         change (&keeleAtFinch);
         display (keeleAtFinch);
     }
 }
 
 /*
 red
red
green
green
green
yellow
red
red
red
green

--------------------------------
Process exited after 1.33 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
 */
