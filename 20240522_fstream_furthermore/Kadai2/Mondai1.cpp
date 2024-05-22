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

	std::ifstream ifile;

	ifile.open("../Kadai1/ex08d01.txt");
	if (!ifile.is_open())
	{
		printf("file failed to open!");
		system("pause");
		return -1;
	}

	srand((unsigned int)(time(NULL)));
	std::string fileLines;
	std::vector<std::string> savedFileLines;
	//////////////////////////////////////////////////
	while (std::getline(ifile, fileLines))
	{
		savedFileLines.push_back(fileLines);
	}
	//////////////////////////////////////////////////
	for(auto& timeStr : savedFileLines)
	{
	
		int convertToAMPM = stoi(timeStr);
		printf("Original : %2d || ", convertToAMPM);

		std::string AMPMStr = "";

		if (convertToAMPM > 24)
		{
			convertToAMPM %= 24;
		} 

		if (convertToAMPM == 24)
		{
			convertToAMPM = 0;
			AMPMStr = "AM";
		}
		else if(convertToAMPM > 12)
		{
			convertToAMPM %= 12;
			AMPMStr = "PM";
		}
		else
		{
			AMPMStr = "AM";
		}

		printf("%2d %s\n", convertToAMPM, AMPMStr.c_str());
		//		std::getline(std::cout,randomizedStr);
	}


	ifile.close();

	std::cout << std::endl;

	system("pause");
	return 0;
}