#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	//以下の指定文字列と指定文字列の長さの乱数を 10 個出力してください。
	//	なお、一度出力した文字列は二度と出ないようにしてください。
	//	「文字列 文字列の長さの乱数」と出力し、改行をしてください。
	//	出力するファイルのファイル名は「ex08d04.txt」とします。


	srand((unsigned int)(time(NULL)));

	int randomizedAmount = rand() % (15 - 1) + 1;
	std::vector<int> randomizedNum;

	randomizedNum.resize(15);

	printf("Numbers will be printed : %zu times\n", randomizedNum.size());

	//////////////////////////////////////////FILE MANAGEMENT
	std::ofstream ofile;

	ofile.open("ex08d05.txt");
	if (!ofile.is_open())
	{
		printf("file failed to open!");
		system("pause");
		return -1;
	}

	ofile << "Numbers will be printed : " << randomizedNum.size() << " times" <<  std::endl;

	for (int i = 0; i < randomizedNum.size(); i++)
	{
		if (i % 2 == 0 && i != 0)
		{
			std::cout << std::endl;
			ofile << std::endl;
		}
		randomizedNum[i] = rand() % (99 - 1) + 2;
		printf("%2d ", randomizedNum[i]);
		ofile << randomizedNum[i] << " ";
	}

	ofile.close();
	//////////////////////////////////////////

	std::cout << std::endl;
	printf("file output success!\n");

	system("pause");
	return 0;
}