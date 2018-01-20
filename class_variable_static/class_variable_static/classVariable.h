// Class Variables - Header
// classVariable.h

class Horse {
	unsigned age;
	unsigned no;

public:
	static unsigned noHorses; //얘가 클래스변수 (static 붙은 이놈)
	Horse(unsigned a);
	void display() const;
	~Horse();
}; 


/*
Static Member의 특징
- 클래스변수, 클래스 함수라고도 한다 -> 왜? 멤버변수와는 달리 클래스당 하나씩만 생성되서 그렇게 부른다고함

- main함수 호출이전에 메모리공간에 올라가서 초기화한다(전역함수와 동일)

- 선언된 클래스의 객체 내에서 직접 접근을 허용한다

- static 멤버 초기화문으로 초기화해야한다.
    -- static unsigned noHorses = 0; 이랑
    -- 클래스 밖에서 unsigned Horse::noHorses = 0; 이랑 같은거 아닐까? 왜 후자의 방법을 하라고 하는걸까???
*/