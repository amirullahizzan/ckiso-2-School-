#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Kadai2.h"

/////////////////////
//RUBBER DUCK
/////////////////////
int main()
{

	std::cout << "Input \"exit\" to stop program \n";
	std::cout << "Input \"all\" to print all\n";
	while (true)
	{
		std::cout << "=================" << std::endl;
		std::string fileNameInput;
		std::cout << "Insert filename : data/Q2/ > ";
		std::cin >> fileNameInput;

		if (fileNameInput == "exit")
		{
			system("pause");
			break;
		}

		std::string path = "data/Q2/";

		std::ifstream file;
		file.open(path + fileNameInput);
		std::vector<std::string> fileStrings;
		if (!file.is_open())
		{
			std::cout << "File read error" << std::endl;
			system("pause");
			return EXIT_FAILURE;
		}
		else
		{
			printf_s("%s\n", (path + fileNameInput).c_str());
			std::cout << "=================" << std::endl;

			std::string container;

			while (std::getline(file, container))
			{
				fileStrings.push_back(container);
				if (file.eof())
				{
					break;
				}
			}
		}
		file.close();

		PrintText(fileStrings);

		const int maxRubberInOneBox = 3;

		std::vector<int> countVec;

		int boxCount = 0;
		int index = 0;
		int overAndExcess = 0;
		for (auto& fileS : fileStrings)
		{
			std::stringstream ss(fileS);

			while (ss >> fileS)
			{
				int duckCount = std::stoi(fileS);

				if (index == 0) 
				{
					boxCount = duckCount;
					index++;
					continue;
				}

				countVec.emplace_back(duckCount);

				if (duckCount > 3)
				{
				overAndExcess += duckCount % 3;
				}
				else if(duckCount < 3)
				{
				overAndExcess += 3 - duckCount;
				}

			}

		}
		std::cout << "=================" << std::endl;
		std::cout << "Box Count : " << boxCount << std::endl;
		//std::cout << "=================" << std::endl;

		for (auto& count : countVec)
		{
		//printf_s("%d\n", count);
		}

		std::cout << "=================" << std::endl;
		std::cout << "Over & Excess : " << overAndExcess << std::endl;
	}

}

void PrintText(std::vector<std::string>& fileString)
{
	for (auto& fileS : fileString)
	{
		printf_s("%s\n", fileS.c_str());
	}
}
