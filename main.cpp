#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj1;
	cout << "Enter first text or letter: ";
	obj1.Input();
	MyString obj2("C++");
	MyString obj3 = obj1 + obj2;
	MyString obj4 = obj3 + " hello";
	MyString obj5 = obj4 + 'h';
	MyString obj6 = move(obj5);
	MyString obj7 = obj6 - " hello";
	MyString obj8 = obj7 - 'h';
	MyString obj9 = obj8++;
	obj1.Print();
	obj2.Print();
	obj3.Print();
	obj4.Print();
	obj5.Print();
	obj6.Print();
	obj7.Print();
	obj8.Print();

}