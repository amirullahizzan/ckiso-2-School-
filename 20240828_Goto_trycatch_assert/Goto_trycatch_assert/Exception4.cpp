#include <iostream>

void Error()
{
	int* p = NULL;

	try
	{
		p = new int[10];
		throw "�G���[����!";
		delete[] p;
	}
	catch(...)
	{
		delete[] p; 
		throw;
	}
}

int main()
{
	try
	{
		Error();
	}
	catch (const char* error)
	{
		std::cerr << error << std::endl;
	}

	return 0;
}