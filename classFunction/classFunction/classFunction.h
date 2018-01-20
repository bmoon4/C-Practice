// Class Functions - Header
// classFunction.h

class Horse {
	unsigned age;
	unsigned no;
	static unsigned noHorses; // class variable (static member)
public:
	Horse(unsigned a);
	void display() const;
	~Horse();
	static unsigned howMany(); // class function (static function)
}; 
