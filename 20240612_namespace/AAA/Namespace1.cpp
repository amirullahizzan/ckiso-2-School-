#include <iostream>

namespace Name1
{
	void Func()
	{
		std::cout << "Name1::Func" << std::endl;
	}
}
namespace Name2
{
	void Func()
	{
		std::cout << "Name2::Func" << std::endl;
	}
}

namespace test
{
	void ASd()
	{
		
	}
}

using namespace test;

void Func()
{
	using namespace std;
	cout << "::Func" << std::endl;
}

namespace
{
	void testFunc()
	{

	}
}

int main()
{
	ASd();
	Name1::Func();
	Name2::Func();
	Func();
	testFunc();

	system("pause");
	return 0;
}