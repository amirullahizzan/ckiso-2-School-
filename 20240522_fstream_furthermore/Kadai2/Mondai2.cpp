#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

int main()
{
	//�ȉ��̎w�蕶����Ǝw�蕶����̒����̗����� 10 �o�͂��Ă��������B
	//	�Ȃ��A��x�o�͂���������͓�x�Əo�Ȃ��悤�ɂ��Ă��������B
	//	�u������ ������̒����̗����v�Əo�͂��A���s�����Ă��������B
	//	�o�͂���t�@�C���̃t�@�C�����́uex08d04.txt�v�Ƃ��܂��B

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