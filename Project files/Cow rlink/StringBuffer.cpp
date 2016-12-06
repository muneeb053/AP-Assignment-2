// COW with reflinking
#include "StringBuffer.h"
#include <iostream>

StringBuffer::StringBuffer()
{
	stb = nullptr;
}

char StringBuffer::charAt(int index) const
{
	if (index <stb->strlen)
	{
		return *(stb->sbuf + index);
	}
	else {

		throw" out ov bounds (array)";
	}
}


StringBuffer::~StringBuffer() //
{
	if (stb->_recount == 1)
	{
		delete[] stb->sbuf;
		delete stb->rlink;//deletes refrnces
		delete stb;
	}
	else
	{
		stb->_recount--;
		StringBuffer* add = this;
		if (stb->rlink->adrs == this)
		{
			reflink* temp = stb->rlink;
			stb->rlink = stb->rlink->next;
			delete temp;
		}

		else {

			reflink* ptr = stb->rlink;
			reflink* prev = NULL;

			while (ptr)
			{
				if (ptr->adrs == this)
				{
					prev->next = ptr->next;
					delete ptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
	}

}
StringBuffer::StringBuffer(const StringBuffer& stro) {


	stb->strlen = stro.length();
	stb->sbuf = new char[stb->strlen];
	for (int i = 0; i<stb->strlen; i++)
	{
		stb->sbuf[i] = stro.charAt(i);
	}
	reflink* rlinking = new reflink;
	rlinking->adrs = this;
	rlinking->next = NULL;
	if (stb->rlink == NULL)
	{
		stb->rlink = rlinking;
	}
	else
	{
		reflink* ptr = stb->rlink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

StringBuffer::StringBuffer(char* ptr, int length)
{
	stb = new stringB;
	stb->sbuf = new char[length];
	stb->strlen = length;
	for (int i = 0; i < length - 1; i++)
	{
		stb->sbuf[i] = ptr[i];
	}
	reflink* rlinking = new reflink;
	rlinking->adrs = this;
	rlinking->next = NULL;

	if (stb->rlink == NULL)
	{
		stb->rlink = rlinking;
	}
	else
	{
		reflink* ptr = stb->rlink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}
stringB::stringB()
{
	sbuf = nullptr;
	strlen = 0;
	_recount = 1;
	rlink = NULL;
}




int StringBuffer::length() const {
	// -> returns the length of the buffer
	return stb->strlen;
}

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	stb = new stringB;
	stb->sbuf = new char[length];
	reflink* rlinking = new reflink;
	rlinking->adrs = this;
	rlinking->next = NULL;
	if (stb->rlink == NULL)
	{
		stb->rlink = rlinking;
	}
	else
	{
		reflink* ptr = stb->rlink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

void StringBuffer::append(char c)
{
	// -> appendingcharacter at end of string

	if (stb->_recount>1)
	{
		stringB* str1 = new stringB;
		str1->strlen = stb->strlen + 1;
		str1->sbuf = new char[str1->strlen];
		for (int i = 0; i < stb->strlen; i++)
		{
			str1->sbuf[i] = stb->sbuf[i];
		}
		str1->sbuf[stb->strlen] = c;
		stb->_recount--;
		if (stb->rlink->adrs == this)
		{
			reflink* str1 = stb->rlink;
			stb->rlink = stb->rlink->next;
			delete str1;
		}
		else {
			reflink* ptr = stb->rlink;
			reflink* prev = NULL;
			while (ptr)
			{
				if (ptr->adrs == this)
				{
					prev->next = ptr->next;
					delete ptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
		stb = str1;
		reflink* rlinking = new reflink;
		rlinking->adrs = this;
		rlinking->next = NULL;
		if (stb->rlink == NULL)
		{
			stb->rlink = rlinking;
		}
		else
		{
			reflink* ptr = stb->rlink;
			reflink*  prev = NULL;
			while (ptr)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = rlinking;
		}

	}
	else
	{

		char* str1 = stb->sbuf;
		stb->strlen++;
		stb->sbuf = new char[stb->strlen];
		for (int i = 0; i < stb->strlen - 1; i++)
		{
			stb->sbuf[i] = str1[i];
		}
		stb->sbuf[stb->strlen - 1] = c;
		delete[] str1;

	}


}
reflink* StringBuffer::get_link() {
	return stb->rlink;

}

StringBuffer& StringBuffer::operator = (const StringBuffer& stro)
{
	stb = stro.stb;
	stb->_recount++;
	reflink* rlinking = new reflink;
	rlinking->adrs = this;
	rlinking->next = NULL;
	if (stb->rlink == NULL)
	{
		stb->rlink = rlinking;
	}
	else
	{
		reflink* ptr = stb->rlink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
	return *this;
}


