#include<iostream>
#include<windows.h> 
#include <list>
using namespace std;

enum Specialty {
	CompScience,
	Informatics,
	MathematicsAndEconomics,
	Works
};

struct Student
{

	string surname;
	int course;
	Specialty specialty;
	int firstScore;
	int secondScore;
	int thirdScore;

	string GetSpecialtyName()
	{
		string result;
		switch (specialty)
		{
		case CompScience:
		{
			result = "Компютернi науки";
			break;
		}
		case Informatics:
		{
			result = "Iнформатика";
			break;
		}
		case  MathematicsAndEconomics:
		{
			result = "Математика та Економiка";
			break;
		}
		case Works:
		{
			result = "Трудове";
			break;
		}
		}
		return  result;

	}
};
void showData(Student Obj[], int amount);
Student binarySearch(Student arr[], int last, int first, Student searchStudent);
bool operator<(const Student& a, const Student& b) {
	return (a.thirdScore < b.thirdScore) || ((a.thirdScore == b.thirdScore) && (a.specialty < b.specialty))
		|| ((a.thirdScore == b.thirdScore) && (a.specialty == b.specialty) && (a.surname > b.surname));
}
bool operator>(const Student& a, const Student& b) {
	return (a.thirdScore > b.thirdScore) || ((a.thirdScore == b.thirdScore) && (a.specialty > b.specialty))
		|| ((a.thirdScore == b.thirdScore) && (a.specialty == b.specialty) && (a.surname < b.surname));
}
bool operator==(const Student& a, const Student& b) {
	return (a.thirdScore == b.thirdScore) && (a.specialty == b.specialty)
		&& (a.surname == b.surname);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int amountOfStudent = 3;
	Student Students[amountOfStudent] = {};

	for (int i = 0; i < amountOfStudent; i++)
	{
		cout << "Прiзвище: ";
		cin >> Students[i].surname;
		cout << "Курс: ";
		cin >> Students[i].course;
		cout << "Специальнисть 1- Компютернi науки 2- Iнформатика 3- Математика та Економiка 4- Трудове" << endl;

		int cr;
		cin >> cr;
		switch (cr) {
		case 1:
		{
			Students[i].specialty = CompScience;
			break;
		}
		case 2: {
			Students[i].specialty = Informatics;
			break;
		}
		case 3: {
			Students[i].specialty = MathematicsAndEconomics;
			break;
		}
		case 4: {
			Students[i].specialty = Works;
			break;
		}
		default: {
			break;
		}
		}
		cout << "Оцiнка з першого предмету: ";
		cin >> Students[i].firstScore;
		cout << "Оцiнка з другого предмету: ";
		cin >> Students[i].secondScore;
		cout << "Оцiнка з третього предмету: ";
		cin >> Students[i].thirdScore;

		cin.get(); // считывает из потока Enter который пользователь нажимает после ввода возраста
		cout << endl;
	}

	showData(Students, amountOfStudent);

	Student temp;
	Student searchStudent;
	string sName;
	char ch;
	do {
		cout << "Головне меню " << endl;
		cout << "1. Сортування " << endl;
		cout << "2. Пошук" << endl;
		cout << "Виберiть меню :" << endl;
		cin >> ch;
		switch (ch)
		{
		case '1':
			for (int i = 0; i < amountOfStudent - 1; i++)
			{
				for (int j = 0; j < amountOfStudent - i - 1; j++)
				{
					if (Students[j] < Students[j + 1])
					{
						temp = Students[j];
						Students[j] = Students[j + 1];
						Students[j + 1] = temp;
					}
				}
			}
			showData(Students, amountOfStudent);
			break;
		case '2':
			cout << "Введiть прiзвище" << endl;
			cin >> sName;
			searchStudent.surname = sName;
			cout << "Виберiть спецiальнiсть 1- Компютернi науки 2- Iнформатика 3- Математика та Економiка 4- Трудове " << endl;
			int cr2;
			cin >> cr2;
			switch (cr2) {
			case 1:
			{
				searchStudent.specialty = CompScience;
				break;
			}
			case 2: {
				searchStudent.specialty = Informatics;
				break;
			}
			case 3: {
				searchStudent.specialty = MathematicsAndEconomics;
				break;
			}
			case 4: {
				searchStudent.specialty = Works;
				break;
			}
			default: {
				break;
			}
			}
			cout << "Введiть бал по третьому предмету" << endl;
			int sScore;
			cin >> sScore;
			searchStudent.thirdScore = sScore;
			try
			{
				Student sStudent = binarySearch(Students, 0, amountOfStudent - 1, searchStudent);
				cout << "Знайдено: " << sStudent.surname << endl;
			}
			catch (const exception& err)
			{
				cout << "Not found!!!" << endl;
			}

			break;
		default:
			return 0;
			break;
		}


	} while (ch != 0);


	return 0;
}
Student binarySearch(Student arr[], int first, int last, Student searchStudent)
{
	if (first <= last) {
		int mid = (first + last) / 2;
		if (arr[mid] == searchStudent)
			return arr[mid];
		if (arr[mid] < searchStudent)
			return binarySearch(arr, first, mid - 1, searchStudent);
		if (arr[mid] > searchStudent)
			return binarySearch(arr, mid + 1, last, searchStudent);
	}
	throw  exception();

}
void showData(Student Obj[], int amount)
{

	cout << "№\t" << "Surname\t" << "Course\t" << "Speciality\t" << "First\t" << "Second\t\t" << "Third" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1 << '\t' << Obj[i].surname << '\t' << Obj[i].course << '\t' << Obj[i].GetSpecialtyName()
			<< '\t' << Obj[i].firstScore << '\t' << Obj[i].secondScore << '\t'
			<< Obj[i].thirdScore << endl;
	}
}
