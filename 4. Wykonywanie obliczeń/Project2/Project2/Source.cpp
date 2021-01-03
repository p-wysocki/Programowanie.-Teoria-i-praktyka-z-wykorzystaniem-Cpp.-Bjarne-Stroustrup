#include <iostream>
using namespace std;

int main()
{
	constexpr char limit = 'z';
	char iter = 'A';

	// v1
	while (iter <= limit)
	{
		cout << iter << "\t" << int(iter) << "\n";
		++iter;
	}

	cout << "\n\nv2\n";

	// v2
	for (int i = 'A'; i <= 'Z'; ++i)		// big letters
	{
		cout << char(i) << "\t" << i << "\n";
	}
	for (int i = '0'; i <= '9'; ++i)
	{
		cout << char(i) << "\t" << i << "\n";
	}
}