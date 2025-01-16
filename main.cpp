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

	vector<int> vec = { 1,27,307,95,298,77 };

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








	cout << endl << endl << "---		�����(find, find_if, find_if_not)		---" << endl;

	auto pl = find(begin(vec), end(vec), 28); // ���������� ��������, ����������� �� �� ����� � ���������, ��� ��������� �������, ���� �� ������ - ������ end()
	
	if (pl != end(vec))
	{
		cout << "�����!" << endl;
	}
	else
	{
		cout << "���((" << endl;
	}

	cout << endl;

	auto res = find_if(begin(vec), end(vec), [](int a) { // find_if_not - �� �� �����, �� ���������� ��������������� �����

		return a % 2 == 0;
		});

	if (res != end(vec))
	{
		cout << "����!" << endl;
	}
	else
	{
		cout << "���((" << endl;
	}

	auto res2 = find_if(begin(vs), end(vs), [](const Students& s) {

		return s.score > 99 && s.score < 101;

		});






	cout << endl << endl << "---		Copy, copy_if		---" << endl;

	vector<Students> result;

	//copy(begin(vs), end(vs), back_inserter(result));

	copy_if(begin(vs), end(vs), back_inserter(result), [](const Students& st)
		{
			return st.score > 150;
		});

	cout << "����� ���������:	" << result.size() << endl;

	for (auto elem : result)
	{
		cout << "���:	" << elem.name << "	�����:	" << elem.score << endl;
	}





	cout << endl << endl << "---		�������� - remove, remove_if		---" << endl;

	vector<int> v = { 1,2,88,91,26,10,3 }; // remove �� ������� ��������, � ��������� �� � ����� � ���������� �������� �� ������� �� ��������� ������������� ���������

	//auto ress = remove(begin(v), end(v), 10);

	//v.erase(ress, v.end()); // erase ������� �������� �� ����������

	//for (auto elem : v)
	//{
	//	cout << elem << endl;
	//}

	cout << endl;

	for (auto elem : vs)
	{
		cout << "���:	" << elem.name << "	�����:	" << elem.score << endl;
	}

	vs.erase(remove_if(begin(vs), end(vs), [](const Students& st) // ����� ����� ��, ��� ������ remove_if ���� ������������ � �������� ������� ��������� erase
		{
			return st.score < 150;
		}), end(vs));

	cout << endl;

	for (auto elem : vs)
	{
		cout << "���:	" << elem.name << "	�����:	" << elem.score << endl;
	}

	return 0;
}