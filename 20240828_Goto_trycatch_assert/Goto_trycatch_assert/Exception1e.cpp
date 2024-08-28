#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{


	try
	{
		std::ifstream file;

		file.open("test.txt");

		if (!file.is_open())
		{
			throw "�t�@�C�����J���܂���ł���";
		}

		std::string line;

		getline(file, line);

		if (file.fail())
		{
			throw "�t�@�C������ǂݍ��߂܂���ł���";
		}

		std::cout << line << std::endl;
	}
	catch (const char* error)
	{
		std::cerr << error << std::endl;
		return EXIT_FAILURE;
	}


	system("pause");

	return 0;
}