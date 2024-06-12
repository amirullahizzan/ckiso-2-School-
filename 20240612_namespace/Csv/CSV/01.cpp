#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


bool isInteger(const std::string& s) {
	for (char const& ch : s) {
		if (!std::isdigit(ch)) return false;
	}
	return true;
}
int main()
{

	std::ifstream file;
	std::vector<std::string> fileLines;

	/////////////////////////////////////////////////////////
	//FILE ACCESS
	{

		file.open("csv/map1.csv");

		if (!file.is_open())
		{
			printf("ERROR READING FILE!");
			return EXIT_FAILURE;
		}

		std::string readFileLines;
		while (std::getline(file, readFileLines))
		{
			fileLines.push_back(readFileLines);
		}
		file.close();

	}
	/////////////////////////////////////////////////////////

	for (auto& line : fileLines)
	{
		printf(line.c_str());
		printf("\n=====================================\n");
	}

	/////////////////////////////////////////////////////////
	printf("\n");
	printf("///////////////////////////////////////////////////////////\n");
	printf("EOF\n");
	printf("///////////////////////////////////////////////////////////\n");

	printf("\n");
	printf("///////////////////////////////////////////////////////////\n");
	printf("Convert from CSV\n");
	printf("///////////////////////////////////////////////////////////\n");

//Converting to int
	std::stringstream sstreamFileLines;
	for (auto& line : fileLines)
	{
		sstreamFileLines << line;
	}

	std::string platformTypeString;
	std::vector<int> platformTypeList;

	//can also use .find , npos, and substr
	while (std::getline(sstreamFileLines, platformTypeString, ','))
	{
		platformTypeList.push_back(std::stoi(platformTypeString));
	}

	for (auto& platformType : platformTypeList)
	{
		printf("%3d", platformType);
	}


	for (auto& platformType : platformTypeList)
	{
		printf("%3d", platformType);
	}


	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}


//Converting to int

//std::vector<int> platformTypeList;
//std::vector<std::string> playerNames;

//Use for already defined variables, example, playerName, HP
//std::string line;
//for (auto& line : fileLines)
//{
//	std::stringstream sstreamFileLines(line);
//	//std::string nameString;
//	std::string platformTypeString;
//
//	//std::getline(sstreamFileLines, nameString, ',');
//	std::getline(sstreamFileLines, platformTypeString);
//
//	//if (isInteger())
//	//{
//	//
//	//}
//
//	platformTypeList.push_back(std::stoi(platformTypeString));
//	printf("asd");
//}