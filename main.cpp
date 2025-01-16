#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



class Students
{
public:
	Students(string name, int score)
	{
		this->name = name;
		this->score = score;
	};

	bool operator ()(const Students& s) // �������� - �������, �� ���������� bool � �������� ���������� ()
	{
		return s.score > 100;
	}

	string Get_name()
	{
		return this->name;
	}

	int Get_score()
	{
		return this->score;
	}


	string name;
	int score;
};



int main()
{
	setlocale(LC_ALL, "ru");
	cout << "---		SORT(����������)		---" << endl;

	vector<int> vec = { 1,28,308,94,299,77 };

	for (auto elem : vec)
	{
		cout << elem << endl;
	}
	
	cout << endl;

	sort(begin(vec), end(vec), [](int a, int b) {

		return a < b;

		});

	for (auto elem : vec)
	{
		cout << elem << endl;
	}

	cout << endl;

	const int SIZE = 5;

	int arr[SIZE] = { 1,10,77,2,3 };

	for (auto elem : arr)
	{
		cout << elem << endl;
	}

	cout << endl;

	sort(begin(arr), end(arr), [](int a, int b) {

		return a < b;

		});

	for (auto elem : arr)
	{
		cout << elem << endl;
	}

	cout << endl;


	vector<Students> vs =
	{
		Students("����", 150),
		Students("����", 100),
		Students("����", 20),
		Students("����", 200),
		Students("����", 220),
		Students("����", 60),
	};

	for (auto elem : vs)
	{
		cout << "���:	" << elem.Get_name() << "	���-�� ������:	" << elem.Get_score() << endl;
	}

	cout << endl;

	sort(begin(vs), end(vs), [](const Students& s1, const Students& s2) {

		return s1.score > s2.score;

	}); 

	for (auto elem : vs)
	{
		cout << "���:	" << elem.Get_name() << "	���-�� ������:	" << elem.Get_score() << endl;
	}

	cout << endl;




	return 0;
}