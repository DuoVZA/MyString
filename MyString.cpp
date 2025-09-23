#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length];
	count++;
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length];
	count++;
}

MyString::MyString(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
	count++;
}

MyString::~MyString()
{
	delete[] str;
}

MyString::MyString(const MyString& obj):length(obj.length)
{
	str = new char[length+1];
	strcpy_s(str, length + 1, obj.str);
	count++;
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
	cin.getline(str, length+1);
}

void MyString::MyStrcpy(MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	count++;
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
	char* newStr = new char[newLength];

	for (size_t i = 0; i < length; i++)
	{
		newStr[i] = str[i];
	}
	for (size_t i = 0; i < b.length; i++)
	{
		newStr[length+i] = b.str[i];
	}
	delete[] str;
	str = newStr;
	length = newLength;
	count++;
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

void MyString::PrintCount()
{
	cout << "Count = " << count << endl;
}

int MyString::count = 0;