#include "Header1.h"
#include <iostream>

using namespace std;

//extern int a; //if want the same value

//static int a = 123;
namespace test
{
int a = 123;
}

int main()
{
	cout << func1() + test::a << endl;
	//cout << func1() + a << endl;

	system("pause");
	return 0;
}