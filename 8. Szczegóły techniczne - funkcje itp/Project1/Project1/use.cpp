#include <iostream>
#include "my.h"

using namespace std;

int foo = 7;
int x = 7;
int y = 9;

int main()
{
	/*
	// ex1
	print_foo();
	print(99);
	*/

	/*
	// ex2
	//ex2_swap_v(7, 9);
	ex2_swap_r(x, y);
	//ex2_swap_cr(x, y);

	cout << "swap x: " << x << " y: " << y << endl;
	*/

	// ex3
	X::var = 7;
	X::print();
	/*
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
	*/
	// to keep the window open
	char cc;
	cin >> cc;
}