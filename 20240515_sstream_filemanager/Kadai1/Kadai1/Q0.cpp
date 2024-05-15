#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int main()
{

	std::fstream file;
	file.open("txt/Q0.txt");
	if (!file.is_open())
	{
		printf("Something is wrong!\n");
		system("pause");
	}

	std::string str[5];
	for (int i = 0 ; i < 5;i++)
	{
	getline(file,str[i]);
	}
	file.close();
	
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += stoi(str[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", str[i].c_str());
	}
		printf("SUM : %d\n\n", sum);

	system("pause");

	return 0;
}