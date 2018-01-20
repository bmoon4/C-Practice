// Class Variables - Header
// classVariable.h

class Horse {
	unsigned age;
	unsigned no;

public:
	static unsigned noHorses; //�갡 Ŭ�������� (static ���� �̳�)
	Horse(unsigned a);
	void display() const;
	~Horse();
}; 


/*
Static Member�� Ư¡
- Ŭ��������, Ŭ���� �Լ���� �Ѵ� -> ��? ��������ʹ� �޸� Ŭ������ �ϳ����� �����Ǽ� �׷��� �θ��ٰ���

- main�Լ� ȣ�������� �޸𸮰����� �ö󰡼� �ʱ�ȭ�Ѵ�(�����Լ��� ����)

- ����� Ŭ������ ��ü ������ ���� ������ ����Ѵ�

- static ��� �ʱ�ȭ������ �ʱ�ȭ�ؾ��Ѵ�.
    -- static unsigned noHorses = 0; �̶�
    -- Ŭ���� �ۿ��� unsigned Horse::noHorses = 0; �̶� ������ �ƴұ�? �� ������ ����� �϶�� �ϴ°ɱ�???
*/