#include <iostream>
#include <vector>
#include "my.h"

using namespace std;

// for testing purposes
int foo = 7;
int x = 7;
int y = 9;

void ex1()
{
	print_foo();
	print(99);
}

void ex2()
{
	//ex2_swap_v(7, 9);
	ex2_swap_r(x, y);
	//ex2_swap_cr(x, y);

	cout << "swap x: " << x << " y: " << y << endl;
}

void ex3()
{
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	print();
	X::print();
}

void ex4(const vector<int> numbers)
// simple vector console output
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << endl;
	}
	return;
}

void ex5(int x, int y, vector<int>& v, int n, int iter_number = 1)
// fibonacci sequence
{
	try
	{
		if (iter_number == 1)																				// if 1st iteration only
		{
			if (n < 3)
			{
				throw invalid_argument("Length of sequence <= 2");
			}
			// add first 2 elements in correct order
			v.push_back(min(x, y));
			v.push_back(max(x, y));
		}
		// calculate next element of the sequence as sum of 2 previous ones and add to v
		int next_element = x + y;
		v.push_back(next_element);
		if (iter_number == n - 2)																			// if final iteration, n reduced by 2 to compensate for initial x, y
		{
			for (int i = 0; i < v.size(); ++i)																// display results
			{
				cout << v[i] << endl;
			}
			return;
		}
		else
		{
			ex5(max(x, y), next_element, v, n, ++iter_number);
		}
	}
	catch (const invalid_argument& e)
	{
		cout << e.what() << endl;
		return;
	}
	catch (...) 
	{
		cout << "Unknown error" << endl;
		return;
	}
}

vector<int> ex6(const vector<string> texts)
{
	vector<int> text_size;
	for (int i = 0; i < texts.size(); ++i)
	{
		text_size.push_back(texts[i].length());
	}
	return text_size;
}

int main()
{
	//ex1();
	//ex2();
	//ex3();

	//vector<int> numbers_for_ex4{ 10, 12, 23, 4123, 412, 4 };
	//ex4(numbers_for_ex4);

	//int x = 1;
	//int y = 2;
	//vector<int> fibonacci_sequence;
	//int n = 5; // amount of numbers to display
	//ex5(x, y, fibonacci_sequence, n);

	vector<string> texts{ "rwaz", "dwa", "trzy", "dfawfdaw" };
	vector<int> ex6_output = ex6(texts);
	for (int i = 0; i < ex6_output.size(); ++i)
	{
		cout << ex6_output[i] << endl;
	}

	// to keep the window open
	char cc;
	cin >> cc;
}