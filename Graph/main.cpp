#include<iostream>
#include<vector>
using namespace std;

void f1(vector<int> vec)
{
	for (int i = 0; i < 10; i++)
	{
		vec.emplace_back(i + 1);
	}
}

void f2(vector<int> & vec)
{
	for (int i = 0; i < 10; i++)
	{
		vec[i] = i + 1;
	}
}

void f3(vector<int> * vec)
{
	for (int i = 0; i < 10; i++)
	{
		(*vec)[i] = i + 2;
	}
}

void showVec(vector<int> vec)
{
	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << endl;
	}
	cout << "*******************" << endl;
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.emplace_back(i);
	}
	showVec(vec);
	f1(vec);
	showVec(vec);
	f2(vec);
	showVec(vec);
	f3(& vec);
	showVec(vec);
	system("pause");
	return 0;
}