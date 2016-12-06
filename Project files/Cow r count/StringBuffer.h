#pragma once
#include <iostream>

class strinB
{
public:
	char* strbuf;
	int len;
	int refcount;
	strinB();
};
class StringBuffer {

public:
	StringBuffer();
	~StringBuffer();
	StringBuffer(const StringBuffer&);
	StringBuffer(char*, int);
	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);

	StringBuffer& operator = (const StringBuffer&);

private:
	strinB*  str;
};
