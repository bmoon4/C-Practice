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
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .

std::move�� ������ ��ü�� move�����ִ� ���� �ƴ϶�� ���� ���� �߿��ϴ�. 
��� ��޵� �̾߱����� std::move�� �ܼ��� rvalue reference�� ĳ������ ���� ���̴�.
��, std::move�� ������ move�� �����ִ� ���� �ƴ϶� �ܼ��� move�� �� �ִ� ���Ǹ� ���߰� ���ִ� �Լ���� ���̴�. 
�׸��� �����ε� rvalue reference�� ���ڸ� �Ѱ�ٰ� �ؼ� ������ move�� �Ǵ°� �ƴϴ�. 


 CQuestInfo & operator = ( CQuestInfo &&quest )
    {
        printf( "move ���� ������\n" );
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

move ������ : Name�� ���� ���� (�Ű������� �ش��ϴ� ������ ���� ��ü quest�� �ǹ�) �� Name �ּҸ� �״�� �ް� 
���� Name ������ ������ NULL�� �����. <�ݵ�� NULL�� ����� ��� �Ѵ�. �׷��� ������ ������ �Ҹ�ɽ� ������ ����ٰ� �Ѵ�.>

�� Ȯ���� ���� Name�� ���� ���翬��(������) �� new ������ �������� �ʴ� move �����ڰ� �ӵ��鿡 �־ �� �����ٴ� ���� �� �� �ִ�.
���� ������ �� Move ���� �������� ��쿡�� �ڵ常���ε� �� �ӵ����̸� �� �� ���� ���̴�.


*/
