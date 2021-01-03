#include <iostream>
using namespace std;

int main()
{
	cout << "Podaj liczbe zmiennoprzecinkowa: ";
	double n;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nTrzy razy n == " << n * 3
		<< "\nn do kwadratu == " << n * n
		<< "\nPolowa n == " << n / 2
		<< "\nsqrt(n) == " << sqrt(n) << "\n";
}