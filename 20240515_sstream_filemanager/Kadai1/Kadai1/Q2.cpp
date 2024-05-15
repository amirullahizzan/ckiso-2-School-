#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
	std::fstream file;

	file.open("txt/Q2.txt", std::ios::in);

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

	for (auto& str : texts)
	{
		std::stringstream ss(str); //get one line data
		int x, y;
		std::string sign;
		while (ss >> x >> y) //do in one line until end of line
		{
			if (x > y)
			{
				sign = '>';
			}
			else if (x < y)
			{
				sign = '<';
			}
			else
			{
				sign = "==";
			}

			printf("%d %s %d", x, sign.c_str(), y);
		}

		//printf("%d %s %d", x, , y);

		printf("\n");
	}

	system("pause");

	return 0;
}