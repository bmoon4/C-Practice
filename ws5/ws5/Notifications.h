// OOP345
// Workshop 5
// Name: Bokyung Moon
// Date: 12-OCT-2017

#include "Message.h"
#include <iostream>

namespace w5{
	const int MAX_SIZE = 10;

	class Notifications{
		Message* messageTable;
		int messageCount;

	public:
		Notifications();
		Notifications(const Notifications& rhs);
		Notifications& operator=(const Notifications& rhs); //- copy assignment operator
		Notifications(Notifications&& rhs);  // - move constructor
		Notifications&& operator=(Notifications&& rhs); //- move assignment operator
		~Notifications(); //- destructor
		void operator+=(const Message& msg); //- adds msg to the set  // we cannot steal brain
		void display(std::ostream& os) const; //- inserts the Message objects to the os output stream

	}; // class Notifications

}	// namespace w5