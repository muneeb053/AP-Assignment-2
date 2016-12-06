

#include <iostream>
#include "StringBuffer.h"

StringBuffer::StringBuffer()
{
	str = nullptr;
}
StringBuffer::~StringBuffer()
{
	if (str->refcount == 1)
	{
		delete[] str->strbuf;
		delete str;
	}
	else
	{
		str->refcount--;
	}
}


StringBuffer::StringBuffer(const StringBuffer& obj) {


	str->len = obj.length();
	str->strbuf = new char[str->len];
	for (int i = 0; i<str->len; i++)
	{
		str->strbuf[i] = obj.charAt(i);
	}
}

StringBuffer::StringBuffer(char* ptr, int length)
{
	
	str = new strinB;
	str->strbuf = new char[length];
	str->len = length;
	for (int i = 0; i < length - 1; i++)
	{
		str->strbuf[i] = ptr[i];
	}
}

char StringBuffer::charAt(int index) const
{
	if (index < str->len)
	{
		return *(str->strbuf + index);
	}
	else {
		throw"array out of bounds";
	}

}

int StringBuffer::length() const
{
	return str->len;
}

void StringBuffer::reserve(int length)
{

	str = new strinB;
	str->strbuf = new char[length];
}

void StringBuffer::append(char c)
{

	if (str->refcount>1)
	{
		strinB* str1 = new strinB;
		str1->len = str->len + 1;
		str1->strbuf = new char[str1->len];
		for (int i = 0; i < str->len; i++)
		{
			str1->strbuf[i] = str->strbuf[i];
		}
		str1->strbuf[str->len] = c;
		str->refcount--;
		str = str1;

	}
	else
	{

		char* str1 = str->strbuf;
		str->len++;
		str->strbuf = new char[str->len];
		for (int i = 0; i < str->len - 1; i++)
		{
			str->strbuf[i] = str1[i];
		}
		str->strbuf[str->len - 1] = c;
		delete[] str1;

	}


}
strinB::strinB()
{
	strbuf = nullptr;
	len = 0;
	refcount = 1;
}
// Operator Overloading
StringBuffer& StringBuffer::operator = (const StringBuffer& obj)
{
	str = obj.str;
	str->refcount++;
	return *this;
}


