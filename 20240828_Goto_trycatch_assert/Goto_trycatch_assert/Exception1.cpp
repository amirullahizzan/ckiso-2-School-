#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
	std::ifstream file;

	file.open("test.txt");

	if (!file.is_open())
	{
		std::cerr << "�t�@�C�����J���܂���ł����I" << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;

	getline(file,line);

	if (file.fail())
	{
		std::cerr << "�t�@�C������ǂݍ��߂܂���ł���!" << std::endl;
	}

	std::cout << line << std::endl;

	return EXIT_SUCCESS;
}