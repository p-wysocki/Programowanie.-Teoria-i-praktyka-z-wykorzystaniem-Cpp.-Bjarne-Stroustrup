#include <iostream>
using namespace std;

string first_name;
double age = -1;

int main()
{
	cout << "Podaj imie i wiek\n";
	cin >> first_name >> age;
	age = age * 12;		// age in months
	cout << "Witaj " << first_name << " (" << age << " miesiecy)";
}