#include <iostream>

using namespace std;

int Add(int a, int b)
{
	//加算
	return a + b;
}
int Sub(int a, int b)
{
	//減算
	return a - b;
}
int Mul(int a, int b)
{
	//、乗算、
	return a * b;
}
int Div(int a, int b)
{
	//除算
	return a / b;
}
int Mod(int a, int b)
{
	//剰余演算
	return a % b;
}

int main()
{

	int input = 0;
	int input2 = 0;
	while (true)
	{
		cout << "数値を入力 > ";
		cin >> input;
		cout << "数値を入力 > ";
		cin >> input2;


		if (input2 > input)
		{
			break;
		}
		else
		{
			cout << "ERROR: 入力に誤りがあります" << endl;
		}


	}

	cout << input << " + " << input2 << " = " << Add(input, input2) << endl;
	cout << input << " - " << input2 << " = " << Sub(input, input2) << endl;
	cout << input << " * " << input2 << " = " << Mul(input, input2) << endl;
	cout << input << " / " << input2 << " = " << Div(input, input2) << endl;
	cout << input << " % " << input2 << " = " << Mod(input, input2) << endl;

	system("pause");
	return 0;
}