#include <iostream>
//trailing return-type

 class Ticket {
   public:
     enum class TicketType { Adult, Child };  // Ŭ���� ���ο� enum Ŭ���� ����  
     
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

 auto Ticket::get() const -> TicketType { return ticketType; } // 1. �۵� 
 
// TicketType Ticket::get() const { return ticketType;} //  2. ������ �ȵȴ�  
// Ticket::TicketType Ticket::get() const { return ticketType;} // 3. �̰� �۵� ( enum�� Ticket Ŭ���� ���ο� ����������Ƿ� Ticket ������ �޾��ָ� �۵�) 

/*
 The auto keyword specifies type inference.  
 The return-type follows the closing parenthesis and depends on the identifier or the parameter list.  
 This is particularly useful with

    ** enumerations defined within a class  // ���� �ڵ�� ���⿡ �ش��Ұ�. ����Ÿ���� enum�̶� 
    * templated functions

*/
 int main () {
     Ticket a, b;
     a.set(Ticket::TicketType::Adult);
     b.set(Ticket::TicketType::Child);
     std::cout << a.get() << std::endl;
     std::cout << b.get() << std::endl;
 }
