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
		error = "ファイルを開けませんでした";
		//std::cerr << "ファイルを開けませんでした！" << std::endl;
		goto ON_ERROR;
		//return EXIT_FAILURE;
	}

	getline(file, line);
	if (file.fail())
	{
		//std::cerr << "ファイルから読み込めませんでした!" << std::endl;
		error = "ファイルから読み込めませんでした!";
		goto ON_ERROR;
	}

	std::cout << line << std::endl;

	return EXIT_SUCCESS;
ON_ERROR:
	std::cerr << error << std::endl;
	system("pause");
	return EXIT_FAILURE;
}