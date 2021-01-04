#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ex1()
{
	vector<double> numbers;
	double temp;
	int numbers_entered = 0;
	cout << "Enter 2 numbers\n";
	while (cin >> temp && numbers_entered < 3)
	{
		numbers.push_back(temp);
		++numbers_entered;
		if (numbers_entered == 2)
		{
			sort(numbers.begin(), numbers.end());
			cout << numbers[0] << " " << numbers[1] << "\nThe bigger value is: " 
				<< numbers[1] << "\nThe smaller value is: " << numbers[0] << "\n";

			if (numbers[0] == numbers[1])
			{
				cout << "The numbers are equal\n";
			}

			if (abs(numbers[0] - numbers[1]) < 0.01)
			{
				cout << "The numbers are approximately equal\n";
			}
			numbers_entered = 0;
			numbers.clear();
			cout << "\n";
		}
	}

}

void ex2()
{
	double temp;
	int number_max, number_min;
	int first_loop = 1;
	cout << "Keep entering numbers\n";
	while (cin >> temp)
	{
		cout << "You entered: " << temp << "\n";
		if (first_loop == 1)
		{
			cout << "It has been initialized as both the highest and lowest value so far\n";
			number_max = temp;
			number_min = temp;
			first_loop = 0;
		}

		if (number_max < temp)
		{
			number_max = temp;
			cout << "The number you entered was the highest so far\n";
		}

		if (number_min > temp)
		{
			number_min = temp;
			cout << "The number you entered was the lowest so far\n";
		}
	}
}

void ex3()
{
	const vector<string> accepted_units = {"cm", "m", "cal", "st"};
	vector<double> numbers;
	double temp_number;
	string temp_unit;
	int numbers_entered = 0;
	double sum_of_numbers = 0;
	cout << "Keep entering numbers with units (space inbetween)\n";
	while (cin >> temp_number >> temp_unit)
	{
		// case switch not applicable with temp_unit as string
		// check if unit is okay
		int unit_check = 0;
		for (int i = 0; i < accepted_units.size(); ++i)
		{
			if (temp_unit == accepted_units[i])
			{
				unit_check = 1;
			}
		}
		if (unit_check == 1)
		{
			cout << "You entered " << temp_number << " with " << temp_unit << " as unit\n";
			++numbers_entered;

			// changing the unit into meters
			if (temp_unit == "cm")
			{
				temp_number *= 0.01;
			}

			if (temp_unit == "cal")
			{
				temp_number *= 0.0254;
			}

			if (temp_unit == "st")
			{
				temp_number *= 0.3048;
			}

			sum_of_numbers += temp_number;
			numbers.push_back(temp_number);
			sort(numbers.begin(), numbers.end());
		}
		else
		{
			cout << "The unit you entered is invalid\n";
		}
	}
	cout << "Sum: " << sum_of_numbers << " m\nAmount of numbers given: " << numbers_entered << "\nHighest number: "
		<< numbers.back() << " m\nLowest number: " << numbers[0] << " m\nAll values entered [m]:\n";
	for (int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n";
}

int main()
{
	ex3();
}