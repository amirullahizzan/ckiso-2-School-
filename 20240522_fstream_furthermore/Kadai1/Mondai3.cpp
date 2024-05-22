#include <iostream>
#include <string>
#include <fstream>

int main()
{

	//以下の指定文字列と指定文字列の長さの乱数を 10 個出力してください。
	//	なお、一度出力した文字列は二度と出ないようにしてください。
	//	「文字列 文字列の長さの乱数」と出力し、改行をしてください。
	//	出力するファイルのファイル名は「ex08d04.txt」とします。



	srand((unsigned int)(time(NULL)));

	std::string dataList[15] =
	{
		"water" ,"dance ", "everyday " ,"lesson " ,"player",
		"service ","store ","yellow ","fantasy ","summer",
		"snow ","monster ","counter ","change ","color",
	};

	int randomizedNumFromStringLength[15];
	bool isDisplay[15];

	for (int i = 0; i < 15; i++)
	{
		randomizedNumFromStringLength[i] = -1;
		isDisplay[i] = false;
	}

	for (int i = 0; i < 15; i++)
	{
		randomizedNumFromStringLength[i] = rand() % (dataList[i].size() - 1) ;
	}

	int totalAppearing = 0;

	while(totalAppearing < 10)
	{
		int randomizedIndex = rand() % 15;
		if (!isDisplay[randomizedIndex])
		{
			isDisplay[randomizedIndex] = true;
			totalAppearing++;
		}
	}
	std::ofstream ofile;

	////////////////////////////FILE MANAGEMENT
	ofile.open("ex08d04.txt");
	if (!ofile.is_open())
	{
		printf("file failed to open!");
		system("pause");
		return -1;
	}

	for (int i = 0; i < 15; i++)
	{
		if (isDisplay[i])
		{
			printf("%s %d\n", dataList[i].c_str(), randomizedNumFromStringLength[i]);
			ofile << dataList[i] << " " << dataList[i].size() << std::endl;
		}
	}
	ofile.close();
	////////////////////////////FILE MANAGEMENT END


	printf("file output success!\n");

	system("pause");
	return 0;
}