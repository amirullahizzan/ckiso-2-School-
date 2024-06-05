#include <iostream>
#include <fstream>

const int WIDTH = 24;

int main()
{
	std::ifstream file;

	file.open("internet_heiwa.jpg", std::ios::in | std::ios::binary);

	if (!file.is_open())
	{
		system("pause");

		return EXIT_FAILURE;
	}

	do
	{
		unsigned char buf[WIDTH];

		file.read((char*)buf,sizeof buf);

		for (int i = 0, size = (int)file.gcount(); i < size;i++)
		{
			printf(" %02X " , buf[i]);
		}
		std::cout << std::endl;

		system("pause");
	} while (!file.eof());

	std::cout << "PROGRAM TERMINATED!" << std::endl;

	system("pause");

	return 0;
}