// vector.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char ** argv ) {
    cout << "vector from initializer list: " << endl;
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto it = vi1;
    
    cout << "size: " << vi1.size() << endl;  	// 10
    cout << "front: " << vi1.front() << endl;   // 1
    cout << "back: " << vi1.back() << endl;  	// 10
    // iterator
    vector<int>::iterator itbegin = vi1.begin();    // auto itbegin = vi1.begin(); 이렇게 해도 가능 
    vector<int>::iterator itend = vi1.end();        // auto itend = vi1.end();
   
   cout << "체크" << endl;
   cout << itbegin[0] << endl;
   cout << itbegin[1] << endl;
   cout << itbegin[2] << endl;
   
    for (auto it = itbegin; it != itend; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
	
	vi1.at(1) = 22;
	vi1[2] = 33;
    
	cout << "change 2 to 22: 2->" << vi1.at(1)<< endl;
    cout << "change 3 to 33: 3->" << vi1.at(2)<< endl;
    
	
    for (auto it = itbegin; it != itend; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    
    cout << "element at 5: " << vi1[5] << endl;
    cout << "element at 5: " << vi1.at(5) << endl;
    
    //std::advance(iterator, index)사용  
    auto IT = vi1.begin();
    std::advance(IT, 5);
    cout << "element at 5 (std::advance()사용 ): " << *IT << endl;

    
    cout << "range-based for loop:" << endl;
    for (int & i : vi1) {
        cout << i << ' ';
    }
    cout << endl;
    
    cout << "insert 42 at begin + 5: " << endl;
    vi1.insert(vi1.begin() + 5, 42);  			
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;
    
    
    cout << "erase at begin + 5: " << endl;
    vi1.erase(vi1.begin() + 5);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;
    
    cout << "push_back 47: " << endl;
    vi1.push_back(47);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1.back() " << vi1.back() << endl;
    
    cout << "range-based for loop: " << endl;
    for(int & v : vi1) {
        cout << v << ' ';
    }
    cout << endl << endl;
    
    
   
    // *** 주의 ***     배열에서 벡터로 복사해오기!!! 
    // from C-array
    
	const static size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
	cout << "vector from C-array: " << endl;
	
	vector<int> vi2 (ia, ia + size);
    
	for( int & i : vi2 ) {
        cout << i << ' ';
    }
    cout << endl << endl;
    
    // vector of strings
    
	cout << "vector of strings:" << endl;
    vector<string> vs = { "one", "two", "three", "four", "five" };
    
    for(string & v : vs) {
        cout << v << endl;
    }
    
    return 0;
}

/*
vector from initializer list:
size: 10
front: 1
back: 10
1 2 3 4 5 6 7 8 9 10
change 2 to 22: 2->22
change 3 to 33: 3->33
1 22 33 4 5 6 7 8 9 10
element at 5: 6
element at 5: 6
range-based for loop:
1 22 33 4 5 6 7 8 9 10
insert 42 at begin + 5:
size: 11
vi1[5]: 42
erase at begin + 5:
size: 10
vi1[5]: 6
push_back 47:
size: 11
vi1.back() 47
range-based for loop:
1 22 33 4 5 6 7 8 9 10 47

vector from C-array:
1 2 3 4 5 6 7 8 9 10

vector of strings:
one
two
three
four
five

--------------------------------
Process exited after 1.196 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
*/
