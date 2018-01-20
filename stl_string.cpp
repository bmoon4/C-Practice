// string.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char ** argv ) {
    string s1 = "This is a string";
    string::iterator it;
    
    // size & length
    cout << "size is same as length: " << s1.size() << endl;
    cout << "size is same as length: " << s1.length() << endl;
    
    // + for concatenation
    cout << "concatenated strings: ";
    string s2 = "this is also a string";
    cout << s1 + ":" + s2 << endl;
    
    // compare
    cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;
    cout << "copy-assign s2 = s1" << endl;
    s2 = s1;
    cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;
    cout << "is s1 > \"other string\"? " << (s1 > "other string" ? "yes" : "no") << endl;
    cout << "is s1 < \"other string\"? " << (s1 < "other string" ? "yes" : "no") << endl;
    cout << "is \"other string\"? > s1  " << ("other string" > s1 ? "yes" : "no") << endl;
    cout << "is \"other string\" < s1? " << ("other string" < s1 ? "yes" : "no") << endl;
    
    // iteration
    cout << "each character: ";
    for( char c : s1 ) {
        cout << c << " ";
    }
    cout << endl;
    
    // insert & erase with an iterator
    it = s1.begin() + 5;
    s1.insert(it, 'X');
    cout << "after insert: " << s1 << endl;
    
    it = s1.begin() + 5;
    s1.erase(it);
    cout << "after erase: " << s1 << endl;
    
    // replace
    s1.replace(5, 2, "ain't");
    cout << "after replace: " << s1 << endl;
    
    // substr
    cout << "substr: " << s1.substr(5, 5) << endl;
    
    // find
    size_t pos = s1.find("s");
    cout << "find first \"s\" in s1 (pos): " << pos << endl;
    
    // rfind
    pos = s1.rfind("s");
    cout << "find last \"s\" in s1 (pos): " << pos << endl;
    
    return 0;
}

/*
size is same as length: 16
size is same as length: 16
concatenated strings: This is a string:this is also a string
is s1 == s2? no
copy-assign s2 = s1
is s1 == s2? yes
is s1 > "other string"? no
is s1 < "other string"? yes
is "other string"? > s1  yes
is "other string" < s1? no
each character: T h i s   i s   a   s t r i n g
after insert: This Xis a string
after erase: This is a string
after replace: This ain't a string
substr: ain't
find first "s" in s1 (pos): 3
find last "s" in s1 (pos): 13

--------------------------------
Process exited after 1.409 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
*/
