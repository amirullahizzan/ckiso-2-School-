#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	fstream file;
	file.open("text.txt", ios::in);
	if (!file.is_open())
	{
		return EXIT_FAILURE;
	}

	string str;
	getline(file,str);
	file.close();
	cout << str << endl;

	system("pause");
	return 0;
}