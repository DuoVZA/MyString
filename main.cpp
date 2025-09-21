#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj;
	obj.Input();
	obj.Print();
	cout << obj.MyChr('o') << endl;
	obj.MyDelChr('w');
	obj.Print();
}