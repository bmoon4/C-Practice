#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Bokyung Moon
// Q2 - 5 marks

struct X{ //����ü�̹Ƿ� ���� public�ӿ� ����
 
	static uint64_t count; // Ŭ���� ���� count ����! 
	void operator -- (int argNotUsed){count++;} // Ŭ�������� count���� ������ ���ϴ� �����ڿ����ε�, *����: �����ڴ� --�ε� �����δ� count++! 
	void operator()(void) {count++;}            // Ŭ�������� count���� ������ ���ϴ� �����ڿ����ε�, *����: �����ڴ� ()�ε� �����δ� count++!
	virtual X* clone() = 0;                     // ���������Լ� -> �ڽ�Ŭ�������� �ݵ�� ��üȭ 
};

uint64_t X::count; // count is global static variable now

struct Y : public X {
	Y() {count = 42;}    // Y�� ��ü�� count = 42�� ����Ʈ 
	virtual Y* clone() {return new Y(*this);} // �ڱ��ڽŰ� ���� ���� ������ ��ü(clone) �� �����ؼ� ���� 
};


// X�� ()�����ڰ� �����Ƿ� -> X�� Y�� �Լ���ü�� (functor) 


int main(){
	/*����ǥ���� 
	  p�� �Լ��μ�, ���� static�� count�� ����Ұ��� 
	*/ 
	auto P = [] { 
		static int call = 0;
		cout << string("#") + to_string(++call) + "=" + to_string(X::count) + "\n";
	};
	
	
	Y y1, y2, y3;         // YŬ������ ��ü y1, y2, y3�� �����߰�, �̵��� count�� 42�� ����Ʈ�� ������ �������� 
	Y *yPtr = y1.clone(); // clone()�� ���� y1�� ���� ���� ���� ��ü(���纻)�� ���� �����������̰�, yPtr�� �� ���纻 ����Ŵ 
	
	
	/*����ǥ���� ����*/
	for(size_t i = 2; i < 4 ; i++){ // ������ 2�� ���� (i=2, i=3) 
		[&] { y1--; y2--; y3--; (*yPtr)--;} ();  
	}
	/*
	--�����ڴ� count++�̴�  
	[&]-> ���۷����� �����´� 
	i=2�϶� : y1.count = 43, y2.count = 44, y3.count = 45, yPtr(y1�� ������).count = 46  => ���� �ѹ� ���Ҵµ� static�� count�� 42���� 46�� �Ǿ���ȴ� 
	i=3�϶� : y1.count = 47, y2.count = 48, y3.count = 49, yPtr(y1�� ������).count = 50 => ���� �� �� ��� static�� count�� 50! 	
	*/
	P(); // #1 = 50 ��� 
	
	
	
	Y ya, yb, yc, yd; // YŬ������ ��ü ya, yb, yc, yd ����, count�� 42�� ������ ���� 
	for(size_t i = 2; i < 4 ; i++){
		[&] { ya(); yb(); yc(); yd();} ();  
	}
	/*
	()�����ڴ� count++ �̴�.  
	[&]-> ���۷����� �����´� 
	i=2�϶� : y1.count = 43, y2.count = 44, y3.count = 45, yPtr(���� y1).count = 46  => ���� �ѹ� ���Ҵµ� static�� count�� 42���� 46�� �Ǿ���ȴ� 
	i=3�϶� : y1.count = 47, y2.count = 48, y3.count = 49, yPtr(���� y1).count = 50 => ���� �� �� ��� static�� count�� 50! 	
	*/
	P(); // #2 = 50 ���  
	
	
	//  X, Y�� �Լ���ü(functor)��. ()�����ڸ� �����ϱ� ������ y1()�̷������� �Լ�ó�� ��밡���ϱ� ����
	//  ���� �������� ���� y1�̴� ya�� �ϴ� ��� ��ü���� ��� �Լ���ü���� 
	//  function wrapper template (std::function<>)�� �Լ���ü�� �ǹ��� 
	 								
	vector< function<void()> > jobs(4, Y() );  
	// ���� �̸��� jobs, ������� 4�� �� ���ҵ��� �Լ���ü Y, (���� 4���� ���� ���п� count = 42�� �ٽ� ���õ�) -> {Y, Y, Y, Y}   
	// ������ Ÿ�� ������ <function<void()>�� �Ѱ� �� ������ ��ҵ��� Ÿ���� �Լ���ü�̱� ���� 
	
	
	jobs.push_back(y1);                  // ���� jobs�� y1���� +> {Y, Y, Y, Y, y1} 
	jobs.insert(jobs.end(), y2 );  	     // ���ڸ����� y2�� ���� -> {Y, Y, Y, Y, y1, y2} 
	jobs.insert(jobs.begin(),{ya, yb} ); // �Ǿտ� {ya, yb}���� ->  {ya, yb, Y, Y, Y, Y, y1, y2} 
	
	for(auto job: jobs){  // jobs�� ���빰�� �ϳ��� ���캻��. 
		job(); // �ᱹ ya(), yb(), Y(), Y(), Y(), Y(), y1(), y2()�϶�� �̾߱� 
	}
	/*
	 ()�����ڴ� ++�̹Ƿ� �� count�� �ö󰣴�. 
	 ya.count = 43, yb.count = 44, Y.count = 45, Y.count = 46, Y.count = 47, Y.count = 48, y1.count = 49, y2.count = 50
	 ��������� count�� 50 
	*/
	P(); //#3 = 50 ��� 
	
	
	
	X::count = 42;  // �ٽ� count�� 42�� ����
	// ���� jobs��  {ya, yb, Y, Y, Y, Y, y1, y2} 
	for(auto iterator = jobs.begin(); iterator != jobs.end();iterator++){
		[&]{(*iterator) ();} ();	
	}
	/*
	 ����ǥ���� ����� 
	 [&]�ϱ� ���۷��� ������
	 iterator�� ����Ű�� ���� ()������ �� ��
	 ()�����ڴ� ++count  
	 
	 ya.count = 43, yb.count = 44, Y.count = 45, Y.count = 46, Y.count = 47, Y.count = 48, y1.count = 49, y2.count = 50
	
	 ���ó� count�� 50�� �ȴ�.  
	*/
	
	P(); // #4 = 50 ��� 
	
    
	// ���� jobs =  {ya, yb, Y, Y, Y, Y, y1, y2} 
	X::count = 42; // �ٽ� count�� 42�� ���� 
	
	while(not jobs.empty()){ // ���Ұ� �� ������������ ��������.  
		
		function<void()> job = move( jobs.back() ); // �Լ���ü job = ���� ���� �ִ� �Լ���ü ������(std::move()��)
												    // **functional ���̺귯���� utility�� std::move()�� �����Ѵ� 
		jobs.pop_back(); // ���峡 ���� ���� 
		                 // {ya, yb, Y, Y, Y, Y, y1, y2} -> {ya, yb, Y, Y, Y, Y, y1,'�̵��� �� �ڸ�'} -> {ya, yb, Y, Y, Y, Y, y1}
		job(); // job �Լ���ü�� ()������ ���� 
	}
	
	/*
 
	 y2�� ������ ()���� -> count = 43  
	 y1�� ������ ()����  -> 44
	 Y()  -> 45
	 Y()  -> 46
	 Y()  -> 47
	 Y() -> 48
	 yb() -> 49
	 ya() -> 50
	 count�� 50�� �ȴ�.  
	*/
	
	P();// #5 = 50 ��� 


/*
 #1=50
 #2=50
 #3=50
 #4=50
 #5=50

--------------------------------
Process exited after 1.399 seconds with return value 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
}
