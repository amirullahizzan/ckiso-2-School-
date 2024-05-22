#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

int main()
{
	//以下の指定文字列と指定文字列の長さの乱数を 10 個出力してください。
	//	なお、一度出力した文字列は二度と出ないようにしてください。
	//	「文字列 文字列の長さの乱数」と出力し、改行をしてください。
	//	出力するファイルのファイル名は「ex08d04.txt」とします。

	std::ifstream ifile;

	ifile.open("../Kadai1/ex08d03.txt");
	if (!ifile.is_open())
	{
		printf("file failed to open!");
		system("pause");
		return -1;
	}

	srand((unsigned int)(time(NULL)));
	std::string fileLines;
	std::vector<std::string> savedFileLines;
	////////////////////////////////////////////////// FILE OPEN
	while (std::getline(ifile, fileLines))
	{
		savedFileLines.push_back(fileLines);
	}
	ifile.close();

	////////////////////////////////////////////////// FILE CLOSE]

	int upper = 999;
	int bottom = -999;
	for (auto& number : savedFileLines)
	{
		
		if (number >= 25 && number > )
		{
			bottom 
		}
		printf("%2d %s\n", convertToAMPM, AMPMStr.c_str());
		//		std::getline(std::cout,randomizedStr);
	}



	std::cout << std::endl;

	system("pause");
	return 0;
}