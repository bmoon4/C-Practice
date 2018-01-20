#include <iostream>
 // �Լ���ü�� functor��� �θ���.  
 // � ��ü�� �Լ�ó�� ����Ѵٴ� ���� ��ü�� ��ȣ�� �ٿ���
 // ��ġ �Ѻ��⿣ �Լ��� ȣ���ϴ°�ó�� ���  �Ѵٴ� �ǹ��̴�.
 // �̰� ���������� ���߿� ���ٰ� ����  
class myFunctorClass
{
	private:
        int _x;
    
	public:
        myFunctorClass (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
   
};
 
 // functor�� ��ü����(Ŭ�����ϱ�) �Լ�ó�� ����� �����ѵ�  
int main()
{
    myFunctorClass addFive( 5 );
    std::cout << addFive( 6 ) << std::endl;   // ��ġ �Լ����� ��ü�� ��ȣ�� �ٿ��� ���� ����. �����  11
 	std::cout << addFive( 5 ) << std::endl;    // 10 
    return 0;
}

// �̷��� ��ü�� �Լ�ȣ���ϵ� ������ ��� �ؾ��ұ�?
// �Լ� ȣ�� ������ ()�� �ݵ�� �����ε� �ؾ��Ѵ�. 
//  int operator() (int y) { return _x + y; } �̷��� 
