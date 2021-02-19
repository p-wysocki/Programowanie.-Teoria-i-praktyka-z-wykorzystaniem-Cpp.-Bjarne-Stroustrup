#include "name_pairs.h"
#include <iostream>
using namespace std;

int main() {
	// ex1 - name_pairs.h
	name_pairs names = name_pairs();
	names.read_names();
	names.read_ages();
	names.print();
	names.sort();
	names.print();

	// ex2 - overload <<, == and !=
	cout << endl << "ex2: " << endl << names << endl;
	name_pairs names2 = name_pairs();
	names2.read_names();
	names2.read_ages();
	names2.sort();
	cout << (names == names2) << endl << (names != names2);
}