#include "StringBuffer.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	
	StringBuffer* obj = new StringBuffer();
	// Appending characters
	obj->append('h');
	obj->append('e'); 
	obj->append('l'); 
	obj->append('l'); 
	obj->append('o');
	cout << "Owned Pointer Implementation " << std::endl;
	// Checking Length Function
	cout << "Object 1 Length =" << obj->length() << std::endl;
	// Checking CharAt Function
	std::cout << "Object 1 charAt 0 = " << obj->charAt(0) << std::endl;

	return 0;
}
