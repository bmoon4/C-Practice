// OOP345
// Workshop 5
// Name: Bokyung Moon
// Date: 12-OCT-2017

#pragma once
#include "Message.h"
#include "Notifications.h"
#include <iostream>


w5::Notifications::Notifications() : messageTable(nullptr), messageCount(0){ //- default constructor - empty

	//std::cout << "Notification default constructor\n";
}

w5::Notifications::Notifications(const Notifications& rhs) : messageTable(nullptr), messageCount(0){ //- copy constructor

	//std::cout << "Notification copy constructor\n";

	if (rhs.messageTable){
		messageTable = new Message[MAX_SIZE];
	}

	//deep copy
	messageCount = rhs.messageCount;

	for (int i = 0; i < messageCount; i++){
		messageTable[i] = rhs.messageTable[i];
	}
}

w5::Notifications& w5::Notifications::operator=(const Notifications& rhs) {//- copy assignment operator
	//std::cout << "Notification copy = operator\n";

	if (this != &rhs){
		delete[] messageTable;

		if (rhs.messageTable){
			messageTable = new Message[MAX_SIZE];
		}

		//deep copy
		messageCount = rhs.messageCount;

		for (int i = 0; i < messageCount; i++){
			messageTable[i] = rhs.messageTable[i];
		}
	}

	return *this;
}

w5::Notifications::Notifications(Notifications&& rhs){  // - move constructor

	//std::cout << "Notification move constructor\n";

	delete[] messageTable; // delete our brains

						   //steal 'brains' from rhs
	messageTable = rhs.messageTable;
	messageCount = rhs.messageCount;

	// turn rhs into a 'zombie'
	rhs.messageTable = nullptr;
	rhs.messageCount = 0;
}

w5::Notifications&& w5::Notifications::operator=(Notifications&& rhs){ //- move assignment operator

	//std::cout << "Notification move = operator\n";

	if (this != &rhs){
		delete[] messageTable; // delete our brains
							   //steal 'brains' from rhs
		messageTable = rhs.messageTable;
		messageCount = rhs.messageCount;

		// turn rhs into a 'zombie'
		rhs.messageTable = nullptr;
		rhs.messageCount = 0;
	}

	return std::move(*this);
}

w5::Notifications::~Notifications(){ //- destructor
	//std::cout << "Notification destructor\n";
	delete[] messageTable;
}

void w5::Notifications::operator+=(const Message& msg) {//- adds msg to the set  // we cannot steal brain

	if (messageTable == nullptr){
		messageTable = new Message[MAX_SIZE];
	}

	if (messageCount < MAX_SIZE){
		messageTable[messageCount] = msg;
		messageCount++;
	}
}

void w5::Notifications::display(std::ostream& os) const {//- inserts the Message objects to the os output stream

	for (int i = 0; i < messageCount; i++){
		messageTable[i].display(os);
	}
}