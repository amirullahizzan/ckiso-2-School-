#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
int main()
{
	std::fstream file;
	file.open("txt/Q1.txt");
	if (!file.is_open())
	{
		printf("File open error!");
		system("pause");
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
	int lowestValue = 9999;
	int highestValue = -9999;
	for (auto& str : texts)
	{
		if (stoi(str) < lowestValue)
		{
			lowestValue = stoi(str);
		}
		if (stoi(str) > highestValue)
		{
			highestValue = stoi(str);
		}
		printf("%d\n", stoi(str));
	}

	printf("=====================\n");
	printf("Lowest Value %d\n", lowestValue);
	printf("Highest Value %d\n", highestValue);
	printf("=====================\n");

	file.close();


	system("pause");

	return 0;
}