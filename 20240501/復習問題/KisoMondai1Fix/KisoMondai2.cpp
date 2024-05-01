#include <iostream>

using namespace std;

int main()
{
	int inputMinRand;
	int inputMaxRand;
	int targetNumber;
	int appearCount = 0;

	while (true)
	{
		while (true)
		{
			cout << "数値を入力 > ";
			cin >> inputMinRand;
			if (inputMinRand < 0)
			{
				cout << "ERROR: 入力に誤りがあります" << endl;
				continue;
			}
			break;
		}

		while (true)
		{
			cout << "数値を入力 > ";
			cin >> inputMaxRand;
			if (inputMaxRand < 0)
			{
				cout << "ERROR: 入力に誤りがあります" << endl;
				continue;
			}
			if (inputMaxRand < inputMinRand + 5)
			{
				cout << "ERROR: 入力に誤りがあります" << endl;
				continue;
			}
			break;
		}

		while (true)
		{
			cout << "数値を入力 > ";
			cin >> targetNumber;
			if (inputMaxRand < 0)
			{
				cout << "ERROR: 入力に誤りがあります" << endl;
				continue;
			}
			break;
		}

		while (true)
		{
			int randResult = inputMinRand + rand() % +inputMaxRand;
			printf("%3d\n", randResult);
			if (randResult == targetNumber)appearCount++;
			if (appearCount == 3) break;
		}
		if (appearCount == 3) break;
	}

	system("pause");
	return 0;
}