#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void test()
{
	{

		goto TEST;
	}
	{

	TEST:
		std::cout << "asd";
	}
}


int main()
{
	const char* error = NULL;

	std::ifstream file;
	std::string line;

TEST2:
	std::cout << "asd";

	file.open("test.txt");

	if (!file.is_open())
	{
		error = "�t�@�C�����J���܂���ł���";
		//std::cerr << "�t�@�C�����J���܂���ł����I" << std::endl;
		goto ON_ERROR;
		//return EXIT_FAILURE;
	}

	getline(file, line);
	if (file.fail())
	{
		//std::cerr << "�t�@�C������ǂݍ��߂܂���ł���!" << std::endl;
		error = "�t�@�C������ǂݍ��߂܂���ł���!";
		goto ON_ERROR;
	}

	std::cout << line << std::endl;

	return EXIT_SUCCESS;
ON_ERROR:
	std::cerr << error << std::endl;
	system("pause");
	return EXIT_FAILURE;
}