#include <iostream>
using namespace std;

int main()
{
	constexpr int euro_per_pln = 4;
	constexpr int yens_per_pln = 10;
	constexpr int dollars_per_pln = 3;

	double money_amount;
	char currency = ' ';
	cout << "Wprowadz walute na ktora chcesz przeliczyc i kwote\n";
	cin >> currency >> money_amount;
	cout << "Kwota to: ";
	switch(currency)
	{
	case 'e':
		cout << money_amount * euro_per_pln << "\n";
		break;
	case 'y':
		cout << money_amount * yens_per_pln << "\n";
		break;
	case 'd':
		cout << money_amount * dollars_per_pln << "\n";
		break;
	default:
		cout << "Nieprawidlowa waluta\n";
		break;
	}
}