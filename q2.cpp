#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Bokyung Moon
// Q2 - 5 marks

struct X{ //구조체이므로 전부 public임에 주의
 
	static uint64_t count; // 클래스 변수 count 선언! 
	void operator -- (int argNotUsed){count++;} // 클래스변수 count값에 조작을 가하는 연산자오버로딩, *주의: 연산자는 --인데 실제로는 count++! 
	void operator()(void) {count++;}            // 클래스변수 count값에 조작을 가하는 연산자오버로딩, *주의: 연산자는 ()인데 실제로는 count++!
	virtual X* clone() = 0;                     // 순수가상함수 -> 자식클래스에서 반드시 구체화 
};

uint64_t X::count; // count is global static variable now

struct Y : public X {
	Y() {count = 42;}    // Y의 객체는 count = 42가 디폴트 
	virtual Y* clone() {return new Y(*this);} // 자기자신과 같은 값을 가지는 객체(clone) 를 생성해서 리턴 
};


// X에 ()연산자가 있으므로 -> X와 Y는 함수객체다 (functor) 


int main(){
	/*람다표현식 
	  p는 함수로서, 전역 static인 count를 출력할것임 
	*/ 
	auto P = [] { 
		static int call = 0;
		cout << string("#") + to_string(++call) + "=" + to_string(X::count) + "\n";
	};
	
	
	Y y1, y2, y3;         // Y클래스의 객체 y1, y2, y3를 생성했고, 이들은 count로 42를 디폴트로 가지고 있을것임 
	Y *yPtr = y1.clone(); // clone()을 통해 y1과 같은 값을 가진 객체(복사본)를 새로 생성했을것이고, yPtr은 그 복사본 가리킴 
	
	
	/*람다표현식 등장*/
	for(size_t i = 2; i < 4 ; i++){ // 루프는 2번 돈다 (i=2, i=3) 
		[&] { y1--; y2--; y3--; (*yPtr)--;} ();  
	}
	/*
	--연산자는 count++이다  
	[&]-> 레퍼런스를 가져온다 
	i=2일때 : y1.count = 43, y2.count = 44, y3.count = 45, yPtr(y1의 복제판).count = 46  => 루프 한번 돌았는데 static인 count는 42에서 46이 되어버렸다 
	i=3일때 : y1.count = 47, y2.count = 48, y3.count = 49, yPtr(y1의 복제판).count = 50 => 루프 다 돈 결과 static인 count는 50! 	
	*/
	P(); // #1 = 50 출력 
	
	
	
	Y ya, yb, yc, yd; // Y클래스의 객체 ya, yb, yc, yd 생성, count는 42을 가지고 있음 
	for(size_t i = 2; i < 4 ; i++){
		[&] { ya(); yb(); yc(); yd();} ();  
	}
	/*
	()연산자는 count++ 이다.  
	[&]-> 레퍼런스를 가져온다 
	i=2일때 : y1.count = 43, y2.count = 44, y3.count = 45, yPtr(실은 y1).count = 46  => 루프 한번 돌았는데 static인 count는 42에서 46이 되어버렸다 
	i=3일때 : y1.count = 47, y2.count = 48, y3.count = 49, yPtr(실은 y1).count = 50 => 루프 다 돈 결과 static인 count는 50! 	
	*/
	P(); // #2 = 50 출력  
	
	
	//  X, Y는 함수객체(functor)다. ()연산자를 지원하기 때문에 y1()이런식으로 함수처럼 사용가능하기 때문
	//  따라서 이전까지 만든 y1이니 ya니 하는 모든 객체들은 사실 함수객체였음 
	//  function wrapper template (std::function<>)은 함수객체를 의미함 
	 								
	vector< function<void()> > jobs(4, Y() );  
	// 벡터 이름은 jobs, 사이즈는 4고 각 원소들은 함수객체 Y, (새로 4개나 만든 덕분에 count = 42로 다시 세팅됨) -> {Y, Y, Y, Y}   
	// 벡터의 타입 설정을 <function<void()>로 한건 이 벡터의 요소들의 타입이 함수객체이기 때문 
	
	
	jobs.push_back(y1);                  // 벡터 jobs에 y1삽입 +> {Y, Y, Y, Y, y1} 
	jobs.insert(jobs.end(), y2 );  	     // 끝자리에는 y2를 삽입 -> {Y, Y, Y, Y, y1, y2} 
	jobs.insert(jobs.begin(),{ya, yb} ); // 맨앞에 {ya, yb}삽입 ->  {ya, yb, Y, Y, Y, Y, y1, y2} 
	
	for(auto job: jobs){  // jobs의 내용물을 하나씩 살펴본다. 
		job(); // 결국 ya(), yb(), Y(), Y(), Y(), Y(), y1(), y2()하라는 이야기 
	}
	/*
	 ()연산자는 ++이므로 또 count가 올라간다. 
	 ya.count = 43, yb.count = 44, Y.count = 45, Y.count = 46, Y.count = 47, Y.count = 48, y1.count = 49, y2.count = 50
	 결과적으로 count는 50 
	*/
	P(); //#3 = 50 출력 
	
	
	
	X::count = 42;  // 다시 count를 42로 세팅
	// 벡터 jobs는  {ya, yb, Y, Y, Y, Y, y1, y2} 
	for(auto iterator = jobs.begin(); iterator != jobs.end();iterator++){
		[&]{(*iterator) ();} ();	
	}
	/*
	 람다표현식 재등장 
	 [&]니까 레퍼런스 가져옴
	 iterator가 가리키는 값에 ()연산자 또 씀
	 ()연산자는 ++count  
	 
	 ya.count = 43, yb.count = 44, Y.count = 45, Y.count = 46, Y.count = 47, Y.count = 48, y1.count = 49, y2.count = 50
	
	 역시나 count는 50이 된다.  
	*/
	
	P(); // #4 = 50 출력 
	
    
	// 벡터 jobs =  {ya, yb, Y, Y, Y, Y, y1, y2} 
	X::count = 42; // 다시 count를 42로 세팅 
	
	while(not jobs.empty()){ // 원소가 다 없어질때까지 돌려본다.  
		
		function<void()> job = move( jobs.back() ); // 함수객체 job = 가장 끝에 있는 함수객체 가져옴(std::move()임)
												    // **functional 라이브러리는 utility의 std::move()를 지원한다 
		jobs.pop_back(); // 가장끝 슬롯 삭제 
		                 // {ya, yb, Y, Y, Y, Y, y1, y2} -> {ya, yb, Y, Y, Y, Y, y1,'이동후 빈 자리'} -> {ya, yb, Y, Y, Y, Y, y1}
		job(); // job 함수객체의 ()연산자 실행 
	}
	
	/*
 
	 y2의 연산자 ()실행 -> count = 43  
	 y1의 연산자 ()실행  -> 44
	 Y()  -> 45
	 Y()  -> 46
	 Y()  -> 47
	 Y() -> 48
	 yb() -> 49
	 ya() -> 50
	 count는 50이 된다.  
	*/
	
	P();// #5 = 50 출력 


/*
 #1=50
 #2=50
 #3=50
 #4=50
 #5=50

--------------------------------
Process exited after 1.399 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
*/
}
