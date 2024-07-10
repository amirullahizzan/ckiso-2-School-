#include <iostream>

template <typename TYPE>
void FillArray(TYPE* array, size_t size, TYPE value)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = value;
	}
}

template <typename TYPE>
void ShowArray(const TYPE* array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{

	const int SIZE = 3;
	int i[SIZE];
	double d[SIZE];

	FillArray<int>(i,SIZE,0);
	FillArray<double>(d,SIZE,0);
	ShowArray(i,SIZE);
	ShowArray(d,SIZE);

	//Show<double, int>(2,0);


	system("pause");

	return 0;
}