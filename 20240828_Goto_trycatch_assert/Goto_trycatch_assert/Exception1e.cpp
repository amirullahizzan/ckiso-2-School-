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
			throw "ファイルを開けませんでした";
		}

		std::string line;

		getline(file, line);

		if (file.fail())
		{
			throw "ファイルから読み込めませんでした";
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