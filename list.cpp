#include <iostream>
#include <list>
//push_back(), push_front(), pop_back(), pop_front(), erase()
int main(){
	
	std::list<int> iList; // list ���� 
	std::list<int>::iterator it; // �ݺ���  
	
	
	int a = 1;
	iList.push_back(a);
	
	a = 12;
	iList.push_back(a);
	
	a = 23;
	iList.push_back(a);
	
  
    std::cout << "1, 12, 23 �Է��� ���" << std::endl;
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	std::cout << std::endl; 
	
	
	std::cout << "�Ǿտ� 0 �߰��� ���" << std::endl;
	iList.push_front(0);

	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	
	std::cout << "�Ǿ��� �� ��� " << std::endl;
	a = iList.front();
	std::cout << a << std::endl;
	
	std::cout << "�ǵ��� �� ���" << std::endl;
	a = iList.back();
	std::cout << a << std::endl;
	
	std::cout << "�ǵ��� �� ������ ���" << std::endl;
	iList.pop_back(); // ����Ʈ�� ���� ������ ������ ���� 
	
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	std::cout << "�Ǿ��� �� ������ ���" << std::endl;
	iList.pop_front(); // ����Ʈ�� ���� �� ������ ���� 
	
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	std::cout << "��λ��� " << std::endl;
	iList.clear();// ��� ���� 
	
	if(iList.empty()){
		std::cout << "����Ʈ�� ������ ����" << std::endl;
	}
	else{
		std::cout << "����Ʈ�� ������ ����" << std::endl;
	}
	
	std::cout << "5 2 7 4 1 8 �Է��� ���" << std::endl;
	iList.push_back(5); 
	iList.push_back(2);
	iList.push_back(7);
	iList.push_back(4);
	iList.push_back(1);
	iList.push_back(8);
	

	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	
	std::cout << "������ġ ��µ���" << std::endl;
	std::cout << "1��°���� 5 �������" << std::endl;
	
	it = iList.begin(); 
	std::cout << *it << std::endl;
	
    std::cout << "3��°���� 7 �������" << std::endl;
	std::advance(it, 2); // 
	std::cout << *it << std::endl;   // �ݺ��ڰ� ���� 3��°���� ����Ŵ 
    
    std::cout << "4��°���� 4 �������" << std::endl;
	it = iList.begin(); // �׷��� �ٽ� ����Ʈ �������... �ȱ׷� 3��°���� ����Ʈ�� ���ϴ´�� �ȳ����� 8����.  
	std::advance(it, 3); // 
	std::cout << *it << std::endl;

	
	std::cout << "sort����" << std::endl;
	iList.sort();// ����Ʈ �������� ���� 
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	
	 
	
}
