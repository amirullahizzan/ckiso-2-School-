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