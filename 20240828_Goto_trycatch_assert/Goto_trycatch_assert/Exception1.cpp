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
		std::cerr << "ファイルを開けませんでした！" << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;

	getline(file,line);

	if (file.fail())
	{
		std::cerr << "ファイルから読み込めませんでした!" << std::endl;
	}

	std::cout << line << std::endl;

	return EXIT_SUCCESS;
}