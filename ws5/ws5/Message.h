// OOP345
// Workshop 5
// Name: Bokyung Moon
// Date: 12-OCT-2017
#pragma once
#include <string>
#include <fstream>

namespace w5{
	class Message{
		
		std::string user, reply, tweet;
	public:
		Message() {};
		Message(std::ifstream& in, char c); //- constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.  c is the character that delimits each record
		bool empty() const; //- returns true if the object is in a safe empty state
		void display(std::ostream& os) const; //- displays the Message objects within the container
	}; // class Message

} // namespace w5