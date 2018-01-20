#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream is;
	is.open("text.txt");

	string s;

	if (is.is_open()) {
		getline(is, s, '\n');
		cout << "입력받은 문자열::" << s << endl;
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}
	getchar();
	return 0;
}