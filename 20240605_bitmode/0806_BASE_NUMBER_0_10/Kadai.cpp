#include <string>
#include <iostream>
#include <cmath>
#include <vector>


std::string ConvertToNBase(int _value, int _fromBase, int _toBase)
{

	if (_toBase <= 1 || _toBase > 10)
	{
		std::cerr << "Cannot convert less than 2 and more than 10 " << std::endl;
		return ""; //cerr
	}

	if (_fromBase > _toBase)
	{
		std::vector<std::string> convertedPerDigitsString;
		int leftover = _value % _toBase;
		int division = _value / _toBase;
		convertedPerDigitsString.push_back(std::to_string(leftover));
		while (true)
		{
			leftover = division % _toBase;
			division /= _toBase;
			convertedPerDigitsString.push_back(std::to_string(leftover));
			if (division < _toBase)
			{
				int last = _toBase / division;
				convertedPerDigitsString.push_back(std::to_string(division));

				std::reverse(convertedPerDigitsString.begin(), convertedPerDigitsString.end());

				std::string output = "";
				for (auto& converted : convertedPerDigitsString)
				{
					output += converted;
				}

				return output;
			}
		}
	}
	else
	{
		//std::pow(0, 0);
	}

	return "";
}


int main()
{
	//std::string s;
	//std::getline(std::cin, s);
	int num1 = 42;

	int base = 2;

	std::string convertedStr = ConvertToNBase(num1, 10, 2);
	printf(convertedStr.c_str());



	return 0;
}