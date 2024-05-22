#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	//�ȉ��̎w�蕶����Ǝw�蕶����̒����̗����� 10 �o�͂��Ă��������B
	//	�Ȃ��A��x�o�͂���������͓�x�Əo�Ȃ��悤�ɂ��Ă��������B
	//	�u������ ������̒����̗����v�Əo�͂��A���s�����Ă��������B
	//	�o�͂���t�@�C���̃t�@�C�����́uex08d04.txt�v�Ƃ��܂��B

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