#include <iostream>

using namespace std;

#define IS_DEBUG true

int main()
{
	if(IS_DEBUG == true)
	{
		cout << "デバッグ" << endl;
	}
	else
	{
		cout << "リリース" << endl;
	}

	system("pause");

	return 0;
}