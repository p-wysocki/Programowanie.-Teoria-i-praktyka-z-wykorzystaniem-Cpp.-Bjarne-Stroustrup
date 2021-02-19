#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class name_pairs {
friend bool operator==(const name_pairs& a, const name_pairs& b);
private:
	vector<string> name;
	vector<int> age;
public:
	void read_names();												// read a series of names into vector name
	void read_ages();												// read an age for every name
	void print();													// print names and respective ages
	void sort();													// sort names alphabetically
	string get_name(int i) const { return name[i]; };
	int get_age(int i) const { return age[i]; };
	int get_size() const { return name.size(); };
};

ostream& operator<<(ostream&, const name_pairs&);
bool operator!=(const name_pairs& a, const name_pairs& b);
