#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
	std::fstream file;

	file.open("txt/Q5.txt", std::ios::in);

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
		int oppositeX, oppositeY;
		int divResult = 0;
		{
			ss >> x >> y; //do in one line until end of line, use while if unknown range
			oppositeX = abs(x - 7);
			oppositeY = abs(y - 7);
			printf("%d %d", x, y);
			printf("ÉTÉCÉRÉçÇÃó†ñ  : ");
			printf("%d %d", oppositeX, oppositeY);
			printf("\n");
		}
	}

	system("pause");

	return 0;
}