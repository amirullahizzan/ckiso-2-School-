#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	fstream file;

	file.open("test.txt", ios::out);
	if (! file.is_open())
	{
		return EXIT_FAILURE;
	}

	file << "ファイルに書き込んじゃえ。" << endl;
	file.close();

	system("pause");
	return 0;
}