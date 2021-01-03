#include <iostream>
using namespace std;

int main()
{
	string previous = " ";
	string current;
	int word_number = 0;
	while (cin >> current)
	{
		++word_number;
		if (previous == current)
		{
			cout << "Powtorzone slowo: " << current << "\nna miejscu: " << word_number << "\n";
		}
		previous = current;
	}
}