#include <iostream>
using namespace std;

int main()
{
	string operation;
	double first_number, second_number;
	cout << "Podaj operator i dwie liczby\n";
	cin >> operation >> first_number >> second_number;

	if (operation == "+" || operation == "plus")
	{
		cout << first_number + second_number;
	}

		else if (operation == "-" || operation == "minus")
		{
			cout << first_number - second_number;
		}

			else if (operation == "*" || operation == "mnozenie")
			{
				cout << first_number * second_number;
			}

				else if (operation == "/" || operation == "dzielenie")
				{
					cout << first_number / second_number;
				}

					else
					{
						cout << "Nieprawidlowy operand";
					}
}