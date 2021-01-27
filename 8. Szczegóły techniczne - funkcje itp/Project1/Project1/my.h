#pragma once
// ex1
extern int foo;
void print_foo();
//void print(int);

// ex2
void ex2_swap_v(int, int);
void ex2_swap_r(int&, int&);
//void ex2_swap_cr(const int&, const int&);

// ex3
namespace X
{
	extern int var;
	void print();
}

namespace Y
{
	extern int var;
	void print();
}

namespace Z
{
	extern int var;
	void print();
}