// OOP345
// Workshop 5
// Name: Bokyung Moon
// Date: 12-OCT-2017
#pragma once
#include "Message.h"

using namespace w5;
using namespace std;

Message::Message(ifstream & in, char c) {
	string line;

	getline(in, line, c);

	auto cr = line.find("\r");
	
	if (cr != string::npos) {
		line.erase(line.begin() + cr);
	}

	size_t index = 0;

	while (index < line.size() && line[index] != ' ') {
		
		if (line[index] == ' ') {
			break;
		}

		user += line[index];
		index++;
	}

	index++;

	if (index < line.size() && line[index] == '@') {
		index++;
		while (index < line.size() && line[index] != ' ') {
			if (line[index] == ' ') {
				break;
			}
			reply += line[index];
			index++;
		}
		index++;
	}

	while (index < line.size()) {
		tweet += line[index];
		index++;
	}
	index++;
}

bool Message::empty() const {
	return tweet.empty();
}

void Message::display(ostream & ostr) const {
	if (!empty()) {
		ostr << "Message\n";
		ostr << "  User  : " << user << "\n";
		
		if (!reply.empty()) {
			ostr << "  Reply : " << reply << "\n";
		}

		ostr << "  Tweet : " << tweet << "\n";
		ostr << "\n";
	}
}