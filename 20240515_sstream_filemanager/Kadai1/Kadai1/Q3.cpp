#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
	std::fstream file;

	file.open("txt/Q3.txt", std::ios::in);

	if (!file.is_open())
	{
		printf("File open error!");
		system("pause");
		return EXIT_FAILURE;
	}

	//////////////////////////////////////////////////
	std::vector<std::string> texts;
	{
		std::string str;
		while (std::getline(file, str))
		{
			texts.push_back(str);
		}
	}
	file.close();
	//////////////////////////////////////////////////

	for(auto& str : texts)
	{
		std::stringstream ss(str); //get one line data
		int x, y;
		int divResult = 0;
		while (ss >> x >> y) //do in one line until end of line
		{
			if (y == 0)
			{
				printf("0Ç≈äÑÇÍÇ»Ç¢ÇÊÅI");
			}
			else
			{
				divResult = x / y;
				printf("%d ÅÄ %d = %d ", x, y, divResult);
			}
		}

		printf("\n");
	}

	system("pause");

	return 0;
}