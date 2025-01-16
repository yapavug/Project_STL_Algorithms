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

	bool operator ()(const Students& s) // Предикат - функтор, тк возвращает bool и является оператором ()
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
	cout << "---		SORT(сортировка)		---" << endl;

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
		Students("Вася", 150),
		Students("Петя", 100),
		Students("Маша", 20),
		Students("Даша", 200),
		Students("Федя", 220),
		Students("Ваня", 60),
	};

	for (auto elem : vs)
	{
		cout << "Имя:	" << elem.Get_name() << "	Кол-во баллов:	" << elem.Get_score() << endl;
	}

	cout << endl;

	sort(begin(vs), end(vs), [](const Students& s1, const Students& s2) {

		return s1.score > s2.score;

	}); 

	for (auto elem : vs)
	{
		cout << "Имя:	" << elem.Get_name() << "	Кол-во баллов:	" << elem.Get_score() << endl;
	}

	cout << endl;

	cout << endl << endl << "---		Поиск(find, find_if, find_if_not)		---" << endl;

	auto pl = find(begin(vec), end(vec), 28); // Возвращает итератор, указывающий на то место в коллекции, где находится элемент, если не найдет - вернет end()
	
	if (pl != end(vec))
	{
		cout << "Нашел!" << endl;
	}
	else
	{
		cout << "Увы((" << endl;
	}

	cout << endl;

	auto res = find_if(begin(vec), end(vec), [](int a) { // find_if_not - то же самое, но возвращает инверсированный ответ

		return a % 2 == 0;
		});

	if (res != end(vec))
	{
		cout << "Есть!" << endl;
	}
	else
	{
		cout << "Увы((" << endl;
	}

	auto res2 = find_if(begin(vs), end(vs), [](const Students& s) {

		return s.score > 99 && s.score < 101;

		});



	return 0;
}