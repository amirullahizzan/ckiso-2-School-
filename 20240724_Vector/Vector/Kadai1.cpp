#include <iostream>
#include <vector>

int main()
{
	std::vector<int> dataVec;

	int input = 0;

	while (true)
	{
		std::cout << "”’l‚ğ“ü—Í(-1‚Ì“ü—Í‚ÅI—¹) > ";
		std::cin >> input;

		if (input == -1)
		{
			break;
		}
		else if (input < -1 || input > 100)
		{
			printf("ERROR: “ü—Í‚Í100‚Ü‚Å‚Ì³‚Ì’l‚Å‚·\n");
			continue;
		}
		else
		{
			dataVec.push_back(input);
		}

		
	}

	int index = 0;
	for (auto& value : dataVec)
	{
		size_t lastIndex = (dataVec.size() - 1);
		printf("[%d] : %3d\n", index, dataVec[lastIndex - index]);
		index++;
	}

	system("pause");
	return 0;
}