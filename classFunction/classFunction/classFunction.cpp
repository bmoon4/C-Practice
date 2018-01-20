// Class Functions - Implementation
// classFunctioncpp

#include <iostream>
#include "classFunction.h"

unsigned Horse::noHorses = 0; // class variable (static member) √ ±‚»≠!!

Horse::Horse(unsigned a) : age{ a }, no{ ++noHorses } {}

void Horse::display() const {
	std::cout << "Horse " << no << " is " << age << " years old\n";
}

Horse::~Horse() { noHorses--; }

unsigned Horse::howMany() { return noHorses; } // class function