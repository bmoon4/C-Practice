#include <iostream>
//trailing return-type

 class Ticket {
   public:
     enum class TicketType { Adult, Child };  // 클래스 내부에 enum 클래스 선언  
     
	 void set(TicketType tt);
     
	 TicketType get() const;
   
   private:
     TicketType ticketType;
 };

 std::ostream& operator << (std::ostream& os, const Ticket::TicketType& tt) {
     
	 const char* label = nullptr;
     
	 switch(tt) {
         case Ticket::TicketType::Adult:
             label = "Adult Ticket";
             break;
         case Ticket::TicketType::Child:
             label = "Child Ticket";
             break;
         default:
             label = "No Ticket";
     }
     
	 os << label;
     
	 return os;
 }

 void Ticket::set(TicketType tt) { ticketType = tt; }

 auto Ticket::get() const -> TicketType { return ticketType; } // 1. 작동 
 
// TicketType Ticket::get() const { return ticketType;} //  2. 컴파일 안된다  
// Ticket::TicketType Ticket::get() const { return ticketType;} // 3. 이건 작동 ( enum이 Ticket 클래스 내부에 선언되있으므로 Ticket 스코프 달아주면 작동) 

/*
 The auto keyword specifies type inference.  
 The return-type follows the closing parenthesis and depends on the identifier or the parameter list.  
 This is particularly useful with

    ** enumerations defined within a class  // 위의 코드는 여기에 해당할것. 리턴타입이 enum이라서 
    * templated functions

*/
 int main () {
     Ticket a, b;
     a.set(Ticket::TicketType::Adult);
     b.set(Ticket::TicketType::Child);
     std::cout << a.get() << std::endl;
     std::cout << b.get() << std::endl;
 }
