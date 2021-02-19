#include "name_pairs.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void name_pairs::read_names() {
	// read a series of names into vector name
	cout << "Input the names. Type \"X\" to finish." << endl;
	string temp_name;																		// for names input
	while (true) {
		cin >> temp_name;
		if (temp_name == "X") {
			return;
		}
		else {
			name_pairs::name.push_back(temp_name);
		}
	}
}

void name_pairs::read_ages() {
	// read an age for every name - display names one by one and ask for age
	int temp_age;
	cout << "Input ages for respective names" << endl;
	for (int i = 0; i < name_pairs::name.size(); ++i) {
		cout << "What's the age of " << name_pairs::name[i] << "?" << endl;
		cin >> temp_age;
		name_pairs::age.push_back(temp_age);
	}
	cout << "Done." << endl;
}

void name_pairs::print() {
	// print names and respective ages
	for (int i = 0; i < name_pairs::name.size(); ++i) {
		cout << "Name: " << name_pairs::name[i] << " Age: " << name_pairs::age[i] << endl;
	}
	cout << "Done." << endl;
}

void name_pairs::sort() {
	// sort names alphabetically
	vector<string> name_sorted = name_pairs::name;
	vector<int> age_sorted = name_pairs::age;
	std::sort(name_sorted.begin(), name_sorted.end());										// sort the names
	// change ages accordingly
	for (int i = 0; i < name_sorted.size(); ++i) {
		for (int j = 0; j < name_pairs::name.size(); ++j) {
			if (name_sorted[i] == name_pairs::name[j]) {
				age_sorted[i] = name_pairs::age[j];
			}
		}
	}
	// implement changes
	name_pairs::age = age_sorted;
	name_pairs::name = name_sorted;
}

ostream& operator<<(ostream& os, const name_pairs& dd) {
	for (int i = 0; i < dd.get_size(); ++i) {
		os << to_string(i + 1) + ". Name: " + dd.get_name(i) + " Age: " + to_string(dd.get_age(i)) << endl;
	}
	return os;
}

bool operator==(const name_pairs& a, const name_pairs& b) {
	return ((a.name == b.name) && (a.age == b.age));
}

bool operator!=(const name_pairs& a, const name_pairs& b) {
	return !(a == b);
}