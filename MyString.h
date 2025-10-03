#pragma once
class MyString
{
	char* str;
	int length;
	static int count;
public:
	MyString();
	MyString(int size);
	MyString(const char* s);
	~MyString();
	MyString(const MyString& obj);
	MyString(MyString&& obj);
	//-----------------------------------------------------------------
	void Print();
	void Input();
	void MyStrcpy(MyString& obj);// ����������� �����
	bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyStrCat(MyString& b); // ����������� �����
	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(MyString& b); // ��������� �����
	MyString operator +(MyString& obj);
	MyString operator +(const char* st);
	MyString operator +(char c);
	MyString operator -(MyString& obj);
	MyString operator -(const char* st);
	MyString operator -(char c);
	MyString operator++(int); // postfix
};

