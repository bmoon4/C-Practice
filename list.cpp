#include <iostream>
#include <list>
//push_back(), push_front(), pop_back(), pop_front(), erase()
int main(){
	
	std::list<int> iList; // list 선언 
	std::list<int>::iterator it; // 반복자  
	
	
	int a = 1;
	iList.push_back(a);
	
	a = 12;
	iList.push_back(a);
	
	a = 23;
	iList.push_back(a);
	
  
    std::cout << "1, 12, 23 입력후 출력" << std::endl;
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	std::cout << std::endl; 
	
	
	std::cout << "맨앞에 0 추가후 출력" << std::endl;
	iList.push_front(0);

	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	
	std::cout << "맨앞의 값 출력 " << std::endl;
	a = iList.front();
	std::cout << a << std::endl;
	
	std::cout << "맨뒤의 값 출력" << std::endl;
	a = iList.back();
	std::cout << a << std::endl;
	
	std::cout << "맨뒤의 값 삭제후 출력" << std::endl;
	iList.pop_back(); // 리스트의 가장 마지막 데이터 삭제 
	
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	std::cout << "맨앞의 값 삭제후 출력" << std::endl;
	iList.pop_front(); // 리스트의 가장 앞 데이터 삭제 
	
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	std::cout << "모두삭제 " << std::endl;
	iList.clear();// 모두 삭제 
	
	if(iList.empty()){
		std::cout << "리스트에 데이터 없음" << std::endl;
	}
	else{
		std::cout << "리스트에 데이터 있음" << std::endl;
	}
	
	std::cout << "5 2 7 4 1 8 입력후 출력" << std::endl;
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
	
	
	std::cout << "임의위치 출력도전" << std::endl;
	std::cout << "1번째값인 5 띄워보기" << std::endl;
	
	it = iList.begin(); 
	std::cout << *it << std::endl;
	
    std::cout << "3번째값인 7 띄워보기" << std::endl;
	std::advance(it, 2); // 
	std::cout << *it << std::endl;   // 반복자가 이제 3번째값만 가르킴 
    
    std::cout << "4번째값인 4 띄워보기" << std::endl;
	it = iList.begin(); // 그래서 다시 디폴트 해줘야지... 안그럼 3번째값이 디폴트라서 원하는대로 안나오고 8나옴.  
	std::advance(it, 3); // 
	std::cout << *it << std::endl;

	
	std::cout << "sort적용" << std::endl;
	iList.sort();// 리스트 오름차순 정렬 
	for(it = iList.begin(); it != iList.end(); it++) {
		 std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	
	 
	
}
