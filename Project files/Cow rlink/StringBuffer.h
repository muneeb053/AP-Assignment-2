#pragma once
#include <iostream>
class reflink;
class stringB;
class StringBuffer;

class reflink
{
public:
	StringBuffer* adrs;
	reflink* next;
};

class stringB
{
public:
	char* sbuf;
	int strlen;
	int _recount;
	reflink* rlink;
	stringB();
};

class StringBuffer {
private:
	stringB*  stb;

public:
	StringBuffer();
	~StringBuffer();
	StringBuffer(const StringBuffer&);
	StringBuffer(char*, int);
	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
	reflink* get_link();
	StringBuffer& operator = (const StringBuffer&);


};

