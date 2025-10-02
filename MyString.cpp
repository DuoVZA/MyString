#include "MyString.h"
#include <cstring>
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length+1];
	str[0] = '\0';
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length];
}

MyString::MyString(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

MyString::~MyString()
{
	delete[] str;
}

MyString::MyString(const MyString& obj):length(obj.length)
{
	str = new char[length+1];
	strcpy_s(str, length + 1, obj.str);
}

MyString::MyString(MyString&& obj)
{
	length = obj.length;
	str = obj.str;
	obj.length = 0;
	obj.str = nullptr;
}

void MyString::Print()
{
	cout << str << endl;
}

void MyString::Input()
{
	char buff[1024];
	cin.getline(buff, 1024);
	if (str!=nullptr) {delete[] str;}
	length = strlen(buff);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buff);
}

void MyString::MyStrcpy(MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}

bool MyString::MyStrStr(const char* st)
{
	char* temp = strstr(str, st);
	if (temp != nullptr)
	{
		return true;
	}
	return false;
}

int MyString::MyChr(char c)
{
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			return i+1;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int newLength = length + b.length;
	char* newStr = new char[newLength+1];

	for (size_t i = 0; i < length; i++)
	{
		newStr[i] = str[i];
	}
	for (size_t i = 0; i < b.length; i++)
	{
		newStr[length+i] = b.str[i];
	}
	newStr[newLength] = '\0';
	delete[] str;
	str = newStr;
	length = newLength;
}

void MyString::MyDelChr(char c)
{
	int newLength = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] !=c)
		{
			newLength++;
		}
	}
	char* newStr = new char[newLength];
	int j = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i]!=c)
		{
			newStr[j++] = str[i];
		}
	}
	delete[] str;
	str = newStr;
	length = newLength;
}

int MyString::MyStrCmp(MyString& b)
{
	int minLength = (length < b.length) ? length : b.length;
	for (size_t i = 0; i < minLength; i++)
	{
		if (str[i] != b.str[i])
		{
			return str[i] - b.str[i];
		}
	}
	return length - b.length;
}

MyString MyString::operator+(MyString& obj)
{
	MyString temp;
	temp.length = this->length + obj.length;
	temp.str = new char[temp.length + 1];
	strcpy_s(temp.str, temp.length + 1, this->str);
	strcat_s(temp.str, temp.length + 1, obj.str);
	return temp;
}

MyString MyString::operator+(const char* st)
{
	MyString temp;
	temp.length = this->length + strlen(st);
	temp.str = new char[temp.length + 1];
	strcpy_s(temp.str, temp.length + 1, this->str);
	strcat_s(temp.str, temp.length + 1, st);
	return temp;
}

MyString MyString::operator+(char c)
{
	MyString temp;
	temp.length = this->length + 1;
	temp.str = new char[temp.length + 1];
	strcpy_s(temp.str, temp.length + 1, this->str);
	temp.str[this->length] = c;
	temp.str[temp.length] = '\0';
	return temp;
}

MyString MyString::operator-(MyString& obj)
{
	const char* pos = strstr(this->str, obj.str);
	if (!pos) return MyString(*this);
	MyString temp;
	temp.length = this->length - obj.length;
	temp.str = new char[temp.length + 1];
	int prefixLen = pos - this->str;
	strcpy_s(temp.str, prefixLen, this->str);
	temp.str[prefixLen] = '\0';
	strcat_s(temp.str, prefixLen, pos + obj.length);
	return temp;
}

MyString MyString::operator-(const char* st)
{
	const char* pos = strstr(this->str, st);
	if (!pos) return MyString(*this);
	MyString temp;
	temp.length = this->length - strlen(st);
	temp.str = new char[temp.length + 1];
	size_t prefixLen = pos - this->str;
	strncpy_s(temp.str, temp.length + 1, this->str, prefixLen);
	temp.str[prefixLen] = '\0';
	strcat_s(temp.str, temp.length + 1, pos + strlen(st));
	return temp;
}

MyString MyString::operator-(char c)
{
	MyString temp;
	temp.length = this->length;
	temp.str = new char[temp.length + 1];
	int idx = 0;
	for (int i = 0; i < this->length; i++) 
	{
		if (this->str[i] != c) 
		{
			temp.str[idx++] = this->str[i];
		}
	}
	temp.str[idx] = '\0';
	temp.length = strlen(temp.str);
	return temp;
}

MyString MyString::operator++(int)
{
	MyString temp;
	temp.length = this->length + 1;
	temp.str = new char[temp.length + 1];
	strcpy_s(temp.str, temp.length + 1, str);
	temp.str[temp.length + 1] += ' ';
	delete[] str;
	str = temp.str;
	length = temp.length;
	return temp;
}