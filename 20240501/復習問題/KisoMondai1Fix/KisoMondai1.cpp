#include <iostream>

using namespace std;

int Add(int a, int b)
{
	//���Z
	return a + b;
}
int Sub(int a, int b)
{
	//���Z
	return a - b;
}
int Mul(int a, int b)
{
	//�A��Z�A
	return a * b;
}
int Div(int a, int b)
{
	//���Z
	return a / b;
}
int Mod(int a, int b)
{
	//��]���Z
	return a % b;
}

int main()
{

	int input = 0;
	int input2 = 0;
	while (true)
	{
		cout << "���l����� > ";
		cin >> input;
		cout << "���l����� > ";
		cin >> input2;


		if (input2 > input)
		{
			break;
		}
		else
		{
			cout << "ERROR: ���͂Ɍ�肪����܂�" << endl;
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