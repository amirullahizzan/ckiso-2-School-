#include <iostream>
#include <string>
#include <fstream>

int main()
{


	srand((unsigned int)(time(NULL)));

	int randomizedNum[10];
	for (int i = 0; i < 10; i++)
	{
		randomizedNum[i] = rand() % (50 - 1) + 2;
	}

	/////////////////////////////////////////////
	std::ofstream ofile;

	ofile.open("ex08d03.txt");
	if (!ofile.is_open())
	{
		printf("file failed to open!");
		system("pause");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0 && i != 0)
		{
			std::cout << std::endl;
			ofile << std::endl;
		}
		printf("%2d ", randomizedNum[i]);
		ofile << randomizedNum[i] << " ";
	}
	ofile.close();
	/////////////////////////////////////////////



	std::cout << std::endl;
	printf("file output success!\n");

	system("pause");
	return 0;
}