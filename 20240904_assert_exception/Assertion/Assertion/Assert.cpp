#include <iostream>
#include <cassert>
//#include <assert>

using namespace std;

class Array
{
public:
	Array(int size = 5)
	{
		assert(size >= 0);
		m_array = new int[size];
		m_size = size;
	}
	~Array()
	{
		delete[] m_array;
		m_array = nullptr;
	}

	void set(int v, int i)
	{
		//assert(i >= 0 && i < size(), "�͈͊O�ł��I");
		assert("�͈͊O�ł��I" && i >= 0 && i < size());

		//static_assert(i >= 0 && i < size(), "test");
		m_array[i] = v;
	}
	int size() const
	{
		return m_size;
	}

private:
	int* m_array = nullptr;
	int m_size = 0;
};

int main()
{
	Array nums1(5);

	nums1.set(10, -1);

	for (int i = 0; i < nums1.size(); i++)
	{
		int n = 0;
		cout << "���l�̓��� > " << flush;
		cin >> n;
		nums1.set(n, i);
	}

	system("pause");
	return 0;
}