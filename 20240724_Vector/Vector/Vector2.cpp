#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(0);


	v.reserve(v.size() + 1);
	v[v.size() - 1] = 3;

	for (auto& a : v)
	{
		std::cout << a << std::endl;
	}

	system("pause");


	return 0;
}