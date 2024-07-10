#include <iostream>
#include <vector>

int main()
{
	/*std::shared_ptr<int> shareds;
	std::vector<int> vectors;
	int hoge = 125;
	int* hoge2 = &hoge;

	auto foo1 = hoge;
	auto foo2 = hoge2;

	std::cout << foo1 << std::endl;
	std::cout << (*foo2) << std::endl;*/

	int nums[10] = {
		58,69,1 ,4 ,74,
		36,22,10,65,83
	};

	//”z—ñnums—v‘f‚ðˆê‚Ð‚Æ‚Â‚¸‚Âo—Í
	for (int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << std::endl;
	}

	for (auto num : nums)
	{
		//std::cout << num << std::endl;
	}


	system("pause");

	return 0;
}