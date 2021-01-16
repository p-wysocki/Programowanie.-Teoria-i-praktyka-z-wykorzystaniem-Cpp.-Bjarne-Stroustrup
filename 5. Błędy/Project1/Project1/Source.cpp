#include <iostream>
#include <exception>
#include <math.h>
using namespace std;

class input_error{};

void cw1()
// converts celsius to kelvin and back
{
	try
	{
		char unit;
		cout << "What is your unit? c or k\n";
		cin >> unit;
		if (cin.fail()) throw input_error();
		switch(unit)
		{
			case 'c':
			{
				double c;
				cin >> c;
				if (cin.fail()) throw input_error();
				if (c < -273.15) throw runtime_error("The temperature given is less than absolute zero.");
				double k = c + 273.15;
				cout << "\n" << k << " C\n";
				break;
			}
			case 'k':
			{
				double c;
				cin >> c;
				if (cin.fail()) throw input_error();
				if (c < 0) throw runtime_error("The temperature given is less than absolute zero.");
				double k = c - 273.15;
				cout << "\n" << k << " K\n";
				break;
			}
			default:
			{
				throw input_error();
				break;
			}
		}
		return;
	}
	catch (const runtime_error& error)
	{
		cout << error.what();
		return;
	}
	catch (const input_error& error)
	{
		cout << "Invalid input.";
		return;
	}
	catch (...)
	{
		cout << "Unidentified error has occured.\n";
		return;
	}
}

void cw2()
// solves a quadratic equation (doesn't handle complex numbers)
{
	try
	{
		double a, b, c, x1, x2, delta;
		cout << "Input A B C parameters (Ax^2 + Bx + C)\n";
		cin >> a >> b >> c;
		if (cin.fail()) throw runtime_error("Invalid input\n");
		delta = pow(b, 2.0) - 4 * a * c;
		if (delta > 0)
		{
			x1 = (-1 * b + sqrt(delta)) / (2 * a);
			x2 = (-1 * b - sqrt(delta)) / (2 * a);
			cout << "\nx1 is " << x1 << "\nx2 is " << x2 << endl;
			return;
		}
		else if (delta == 0)
		{
			x1 = -1 * (b / (2 * a));
			cout << "\n x1 is " << x1 << endl;
			return;
		}
		else
		{
			cout << "This equation only has complex roots.";
			return;
		}
		cout << delta;
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error occured\n";
	}
}

int main()
{
	cw2();
}