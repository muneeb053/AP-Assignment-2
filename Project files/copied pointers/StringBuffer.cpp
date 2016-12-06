#include "StringBuffer.h"
#include <iostream>

StringBuffer::StringBuffer() 
{
	strBuffer = nullptr;	
	strlen = 0;		
}
StringBuffer::~StringBuffer()
{
	delete[] strBuffer;
}

StringBuffer::StringBuffer(const StringBuffer& object) {
	strlen = object.length(); 
	strBuffer = new char[strlen];  
	for (int i = 0; i < strlen; i++)
	{
		strBuffer[i] = object.charAt(i); 
	}
}
StringBuffer::StringBuffer(char* ptr, int len)
{
	strBuffer = new char[len];
	strlen = len;

	for (int i = 0; i < strlen - 1; i++)
	{
		strBuffer[i] = ptr[i];
	}
}
char StringBuffer::charAt(int i) const
{
	if (i < strlen)
	{
		return *(strBuffer + i);
	}
	else {

		throw"out of limit array index";
	}
}
int StringBuffer::length() const {
	return strlen;
}

void StringBuffer::reserve(int len)
{
	
	strBuffer = new char[len];
}
void StringBuffer::append(char c)
{
	char* temp = strBuffer;
	strlen++;
	strBuffer = new char[strlen];
	for (int i = 0; i < strlen - 1; i++)
	{
		strBuffer[i] = temp[i];
	}
	strBuffer[strlen - 1] = c;
	delete[] temp;
}
