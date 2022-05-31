#include<iostream>
#include<windows.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdio>
#include <io.h>
using namespace std;

void nb()// ввод данных

{
	char pach[100];
	string g;
	//создаем путь
	cout << "\tВведите название:  \n";

	cin.get();
	cin.getline(pach, 100);

	g = pach;
	ofstream ost(g + ".txt");

	fstream rec;
	rec.open(g + ".txt", fstream::app);   // fstream::app - дозапись (записываем в конец)

	if (rec.is_open())
	{
		char c[1000], e[1000];
		int  d, f, g;

		cout << "\tВведите описание:  \n";
		cin.getline(c, 1000);
		rec << "\nОписание:  " << c;

		cout << "\tВведите день (число):  \n";
		cin >> d;
		rec << "\nДень:      " << d;

		cout << "\tВедите месяц (название): \n";
		cin.ignore();
		cin.getline(e, 1000);
		rec << "\nМесяц:     " << e;

		cout << "\tВведите час (в формате 24ч):  \n";
		cin >> f;
		rec << "\nЧас:       " << f;

		cout << "\tВедите минуты: \n";
		cin >> g;
		rec << "\nМинуты:    " << g << endl;

		rec << "_______________________";
		cout << "_______________________" << endl;
	}
	else
	{
		cout << "\tОшибка открытия!" << endl;
	}
	rec.close();
}

void dis()     // display to-do list - отобразить саисок дел
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	_finddata_t file;
	intptr_t done = _findfirst("*.txt", &file);
	if (done == -1)
	{
		cout << "Файл не найден!" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << file.name << endl;
		while (_findnext(done, &file) != -1)
		{
			cout << file.name << endl;
		}
	}


	system("pause");
	return;
}

void se()
{
	char pach[1000];
	string f; // = ".txt";
	cout << "Введите название для пойска: " << endl;
	//cin >> path;
	cin.get();
	cin.getline(pach, 1000);
	f = pach;
	fstream op;
	op.open(f + ".txt");

	if (!op.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		char fl;
		while (op.get(fl))
		{

			cout << fl;
		}
	}
	op.close();
	cout << endl;

	return;
}

void del()
{
	char fname[250];
	cout << "Введите название файла для удаления (название.txt):  " << endl;

	cin.get();
	cin.getline(fname, 250);

	if (remove(fname) != 0)             //  remove - функция удаление файла fname.txt
		cout << "Ошибка удаления файла\n";
	else
		cout << "Файл успешно удалён\n";




	return;
}

int m;
void Menu()
{
	cout << "\t*Выберите действие*" << endl
		<< "\t1 - Новое дело." << endl
		<< "\t2 - Удаление." << endl
		<< "\t3 - Редактировани." << endl
		<< "\t4 - Пойск." << endl
		<< "\t5 - Отобразить список дел." << endl
		<< "\t6 - Сортировать." << endl
		<< "\t0 - Выход." << endl;
	cin >> m;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// вызываем функции
	Menu();

	int a;
	string fileName;

	while (m != 0)
	{
		switch (m)
		{
		case 1:
			system("cls");    // очищаем консоль
			nb();
			system("pause");   // задержка
			system("cls");     // снова чистим консоль
			Menu();       // и вызываем меню
			break;
		case 2:
			system("cls");
			del();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			se();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			dis();
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "\tОшибка ввода!" << endl;
			break;
		}
	}
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return;
}