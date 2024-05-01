#include <iostream>
#include <string>


using namespace std;

bool IsPalindrome(string _inputStr)
{
	//	回文 = Palindrome
	size_t palindromeMiddlePos;
	if (_inputStr.length() % 2 != 0)
	{
		palindromeMiddlePos = _inputStr.length() / 2;
		_inputStr.erase(palindromeMiddlePos, 1);
	}

	size_t j = _inputStr.length() - 1;
	size_t k = 0;
	for (int i = 0; i < _inputStr.length() / 2; i++)
	{
		_inputStr[k] = std::tolower(_inputStr[k]);
		_inputStr[j] = std::tolower(_inputStr[j]);
		if (_inputStr[k] != _inputStr[j])
		{
			return false;
		}
		k++;
		j--;
	}

	return true;
}

bool IsAFullWidth(char _inputChar)
{
	return _inputChar >= 65 && _inputChar <= 122;
}

bool IsAFullWidth(string _inputString)
{
	const int FIRST_ASCII_CODE = 65;
	const int LASE_ASCII_CODE = 122;
	for (char character : _inputString)
	{
		if (character >= 65 && character <= 122) return true;
	}
	return false;
}


bool IsBannedSymbols(char _char)
{
	if (_char == ' ')return true;
	if (_char == ',')return true;
	if (_char == '!')return true;
	if (_char == '.')return true;
	if (_char == '?')return true;
	if (_char == '-')return true;
	return false;
}

int CountCharNoSymbols(string _inputStr)
{
	int charCount = 0;

	for (char character : _inputStr)
	{
		if (IsBannedSymbols(character)) continue;
		charCount++;
	}

	return charCount;
}

string GetAlphacharacterString(string _inputStr)
{
	string filteredString;
	for (char character : _inputStr)
	{
		if (!IsAFullWidth(character)) continue;
		if (IsBannedSymbols(character))continue;
		filteredString += character;
	}

	return filteredString;
}



bool IsLessThanThreeCharNoSymbols(string _inputStr)
{
	return CountCharNoSymbols(_inputStr) < 3;
}

int main()
{
	string inputStr;

	while (true)
	{
		cout << "文字列の入力(stopで終了) > ";
		std::getline(std::cin, inputStr);

		if (inputStr == "stop")
		{
			cout << "プログラムを終了します..." << endl;
			break;
		}
		if (IsLessThanThreeCharNoSymbols(inputStr))
		{
			cout << "[ERROR]: 入力は3文字以上です\n";
			continue;
		}
		if (!IsAFullWidth(inputStr))
		{
			cout << "[ERROR] 文字列にA～Z、a～z以外の文字が含まれています\n";
			continue;
		}

		cout << "入力された文字列: " << inputStr << endl;

		string filteredString = GetAlphacharacterString(inputStr);

		if (IsPalindrome(filteredString))
		{
			cout << "回文です" << endl;
		}
		else
		{
			cout << "回文ではありません" << endl;
		}

		cout << endl;
	}
	system("pause");
	return 0;
}