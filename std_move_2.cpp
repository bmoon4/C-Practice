// move example
#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

int main () {
  std::string foo = "foo-string";
  std::string bar = "bar-string";
  std::vector<std::string> myvector;

  myvector.push_back (foo);                    // copies
  myvector.push_back (std::move(bar));         // moves

  std::cout << "myvector contains:";
  for (std::string& x:myvector) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}

/*
myvector contains: foo-string bar-string

--------------------------------
Process exited after 1.629 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .

std::move는 실제로 객체를 move시켜주는 것이 아니라는 점이 정말 중요하다. 
계속 언급된 이야기지만 std::move는 단순히 rvalue reference로 캐스팅을 해줄 뿐이다.
즉, std::move는 실제로 move를 시켜주는 것이 아니라 단순히 move될 수 있는 조건만 갖추게 해주는 함수라는 것이다. 
그리고 실제로도 rvalue reference로 인자를 넘겼다고 해서 무조건 move가 되는게 아니다. 


 CQuestInfo & operator = ( CQuestInfo &&quest )
    {
        printf( "move 대입 연산자\n" );
        if ( this != &quest )
        {
            delete []Name;
            Name = quest.Name;
            NameLen = quest.NameLen;

            quest.Name = NULL;
            quest.NameLen = 0;
        }
        return *this;
    }

move 생성자 : Name에 대해 원본 (매개변수에 해당하는 우측값 참조 객체 quest를 의미) 의 Name 주소를 그대로 받고 
기존 Name 포인터 변수는 NULL로 만든다. <반드시 NULL로 만들어 줘야 한다. 그렇지 않으면 원본이 소멸될시 문제가 생긴다고 한다.>

→ 확실히 봐도 Name에 대한 복사연산(값복사) 및 new 연산을 수행하지 않는 move 생성자가 속도면에 있어서 더 빠르다는 것을 알 수 있다.
대입 연산자 및 Move 대입 연산자의 경우에도 코드만으로도 그 속도차이를 알 수 있을 것이다.


*/
