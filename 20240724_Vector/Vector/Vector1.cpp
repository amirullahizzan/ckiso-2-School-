#include <iostream>
#include <vector>

//Book vector1.cpp
int main()
{
	std::vector<int> v(10);

	for (int i = 0, size = v.size(); i < size; i++)
	{
		v[i] = i * i;
	}

	v.resize(5);

	for (size_t i = 0, size = v.size(); i < size; i++)
	{
		std::cout << v[i] << std::endl;
	}

	std::cout << std::endl;


	system("pause");


	return 0;
}