#include <iostream>
#include <cstdlib>
#include <cstring>

#include "StringBuffer.h"

using namespace std;

int main(int argc, char** argv) {

	StringBuffer* object = new StringBuffer();
	object->append('a');
	object->append('b');
	object->append('c');
	object->append('d');
	object->append('e');
	cout << "Copied Pointers: " << endl;
	cout << "Object length: " << object->length() << endl;
	cout << "Object charAt 0: " << object->charAt(0) << endl;
	delete object;
	getchar();
	return 0;
}

