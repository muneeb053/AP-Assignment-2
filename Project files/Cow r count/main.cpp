#include <iostream>
#include <cstdlib>
#include "StringBuffer.h"
#include <cstring>



using namespace std;

int main() {
	char* hello = "hello";
	StringBuffer* strobj = new StringBuffer(hello, 5);
	StringBuffer* strobj2 = new StringBuffer();

	*strobj2 = *strobj;
	cout << "object 1 length =" << strobj->length() << endl;
	cout << "object 2 length =" << strobj2->length() <<endl;
	strobj->append('y');
	strobj2->append('o');
	strobj2->append('u');
        cout<<"length after appending";
	cout << "object 1 length =" << strobj->length() << endl;
	cout << "object 2 length =" << strobj2->length() <<endl;
	std::cout << "new charAt 5 = " << strobj->charAt(5) << endl;

	return 0;
}
