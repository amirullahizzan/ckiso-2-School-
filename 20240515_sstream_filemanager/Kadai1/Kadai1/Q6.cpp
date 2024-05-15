#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
	std::fstream file;

	file.open("txt/Q6.txt", std::ios::in);

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

	for (auto& text : texts)
	{
		std::stringstream ss(text); //get one line data
		int w, x, y, z;
		int divResult = 0;
		{
			ss >> w >> x >> y >> z; //do in one line until end of line
			printf("%2d %2d %2d %2d", w, x, y, z);
			int diffWX = abs(w - x);
			int diffXY = abs(x - y);
			int diffYZ = abs(y - z);
			printf(" || ");
			printf("ç∑ï™ : %2d", diffWX);
			printf(" || ");
			printf("ç∑ï™ÇÃåvéZ = %2d", diffWX + diffXY + diffYZ);
			printf("\n");
		}
	}

	system("pause");

	return 0;
}