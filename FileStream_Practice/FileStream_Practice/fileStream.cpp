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
		cout << "�Է¹��� ���ڿ�::" << s << endl;
	}
	else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}
	getchar();
	return 0;
}