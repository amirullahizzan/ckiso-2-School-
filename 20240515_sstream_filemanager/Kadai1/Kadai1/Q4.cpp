#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
	std::fstream file;

	file.open("txt/Q4.txt", std::ios::in);

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

	int divisibleBy3Count = 0;
	for(auto& str : texts)
	{
		//std::stringstream ss(str); //get one line data
		if (stoi(str) % 3 == 0)
		{
			printf("%2d is divisible by 3", stoi(str));
			divisibleBy3Count++;
			printf("\n");
		}
	}

	printf("Total numbers divisible by 3 = %d\n", divisibleBy3Count);

	system("pause");

	return 0;
}