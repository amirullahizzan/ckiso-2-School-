#include <iostream>
#include <string>
#include <fstream>

int main()
{

	//0�`96 �܂ł̗����� 10 �o�͂��Ă��������B
	//���ꂼ��̗������o�͂���ہA���s�����Ă��������B
	//�o�͂���t�@�C���̃t�@�C�����́uex08d01.txt�v�Ƃ��܂��B



	srand((unsigned int)(time(NULL)));

	int randomizedNum[10];
	for (int i = 0; i < 10; i++)
	{
		randomizedNum[i] = rand() % 97;
	}

/////////////////////////////////////////////
	std::ofstream ofile;

	ofile.open("ex08d01.txt");
	if (!ofile.is_open())
	{
		printf("file failed to open!");
		system("pause");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		ofile << randomizedNum[i] << std::endl ;
	}

	ofile.close();
/////////////////////////////////////////////

	printf("file output success!\n");

	system("pause");
	return 0;
}