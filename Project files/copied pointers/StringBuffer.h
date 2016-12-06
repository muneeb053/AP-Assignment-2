#pragma once // for copied pointers

#include <iostream>

class StringBuffer {
public:

	StringBuffer(); 
	~StringBuffer(); 

	char charAt(int) const;	//char index
	int length() const; // string length
	void reserve(int);     // Memory Allocation
	void append(char);      //Appending character to string
	StringBuffer(const StringBuffer&); 
	StringBuffer(char*, int);	
private:
	char* strBuffer;  //string buffer (store the original string)
	int strlen;   // string length
};

