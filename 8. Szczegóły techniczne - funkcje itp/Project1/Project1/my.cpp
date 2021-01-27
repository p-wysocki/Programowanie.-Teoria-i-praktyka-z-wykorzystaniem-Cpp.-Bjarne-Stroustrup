#include "..\..\..\std_lib_facilities.h"
#include "my.h"

// ex1
void print_foo()
{
	cout << foo << endl;
}

void print(int i)
{
	cout << i << endl;
}

// ex2
void ex2_swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void ex2_swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//void ex2_swap_cr(const int& a, const int& b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}

// ex3
void X::print() { cout << "Var from X namespace: " << X::var << endl; }

void Y::print() { cout << "Var from Y namespace: " << Y::var << endl; }

void Z::print() { cout << "Var from Z namespace: " << Z::var << endl; }