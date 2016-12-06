
#include "StringBuffer.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	char* stro = "hello";//smrt strng with constnt char

	StringBuffer* stro1 = new StringBuffer(stro, 5);
	StringBuffer* stro2 = new StringBuffer();
	// object referencing
	*stro2 = *stro1;

	int i = 0;
//cheking refrnce of obj
	reflink* lnk = stro1->get_link();

	
	cout << "length of object 1 is=" << stro1->length() << std::endl;//calling lenth function
	cout << "length of object 2 is =" << stro2->length() << std::endl;
	// Checking if reference is found or not

	// apepnd func call
	stro1->append('y'); // append object 1
	stro2->append('o'); // append object 2
	stro2->append('u'); // appedn object 2
        cout<<"length after appending\n";
         cout << "length of object 1 is=" << stro1->length() << std::endl;//calling lenth function
	cout << "length of object 2 is =" << stro2->length() << std::endl;
	return 0;
}
