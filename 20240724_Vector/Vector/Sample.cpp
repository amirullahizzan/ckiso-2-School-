#include <iostream>
#include <array>


int main()
{

	//if you want to make this
	int a[10]{0};

	//
	std::array < int, 10> a2{0};

	for (auto& var : a)
	{
		//printf("%d\n" , var);
	}

	std::cout << "-------------------" << std::endl;
	for (auto& var : a2)
	{
		printf("%d\n" , var);
	}



	system("pause");

	return 0;
}