#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void Open(std::ifstream& file, const char* filename)
{
	file.open(filename);
	if (!file.is_open())
	{
		throw "�t�@�C�����J���܂���ł���!";
	}
}

void GetLine(std::ifstream& file , std::string& line)
{
	getline(file, line);

	if (file.fail())
	{
		throw "�t�@�C������ǂݍ��߂܂���I";
	}
}

int main()
{
	try
	{
		std::ifstream file;
		Open(file, "test.txt");

		std::string line;

		GetLine(file, line);
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
		return EXIT_FAILURE;
	}

	system("pause");

	return EXIT_SUCCESS;

}