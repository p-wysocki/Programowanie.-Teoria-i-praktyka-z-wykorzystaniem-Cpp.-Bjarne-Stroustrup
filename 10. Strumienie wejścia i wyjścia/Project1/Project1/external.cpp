#include "external.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

// ex1
struct Point {
	int x, y;
};

void ex1() {
	// read x y points from file, write to another file
	std::string input_filename = "ex1_input.txt";
	std::ifstream ist{ input_filename };
	ist.exceptions(ist.exceptions() | std::ios::badbit);
	std::vector<Point> points;

	for (Point p; ist >> p;) {
		if (ist.fail()) { std::cout << "Reading failed" << std::endl; }
		points.push_back(p);
	}
	if (!ist.eof()) { std::cout << "Something went wrong with reading the file (case 2)" << std::endl; }

	std::string output_filename = "ex1_output.txt";
	std::ofstream ost{ output_filename };
	for (int i = 0; i < points.size(); ++i) {
		ost << points[i].x << " " << points[i].y << "\n";
	}
}

std::istream& operator>>(std::istream& is, Point& P) {
	int x, y;
	is >> x >> y;
	if (!is) return is;
	P.x = x;
	P.y = y;
	return is;
}

// ex2
void ex2() {
	// read a series of ints from file, print sum
	int sum = 0;
	std::string input_filename = "ex2_input.txt";
	std::ifstream ist{ input_filename };
	ist.exceptions(ist.exceptions() | std::ios::badbit);
	if (!ist) std::cout << "Sth's wrong with file" << std::endl;
	for (int t; ist >> t;) {
		if (ist.fail()) { std::cout << "Case 1" << std::endl; }
		sum += t;
	}
	if (!ist.eof()) { std::cout << "Case 2" << std::endl; }
	std::cout << sum << std::endl;
}

// ex3
struct Reading {
	int hour;
	double temperature;
};

std::istream& operator>>(std::istream& is, Reading& R) {
	// supposed to be in "(time, temp)" format
	int time;
	double temp;
	char ch1, ch2, ch3;
	is >> ch1 >> time >> ch2 >> temp >> ch3;
	if (is.eof()) { std::cout << "Reading done" << std::endl; return is; }
	if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
		is.unget();
		is.clear(std::ios_base::failbit);
		std::cout << "Invalid format, raising fail flag" << std::endl;
		return is;
	}
	R.hour = time;
	R.temperature = temp;
	return is;
};

std::ostream& operator<<(std::ostream& os, Reading& R) {
	os << '(' << R.hour << ',' << R.temperature << ')';
	return os;
};

bool is_valid(const Reading& r) {
	return (r.hour >= 0 && r.hour <= 24 &&
		r.temperature > -30 && r.temperature < 150);
}

double get_median(const std::vector<double>& vec) {
	if (vec.size() % 2) { return vec[(vec.size() / 2) + 1]; };
	return vec[vec.size() / 2];
}

void ex3() {
	// input file
	std::string filename = "ex3_input.txt";
	std::ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | std::ios::badbit);
	if (!ist) { std::cout << "Issue case 1" << std::endl; }

	// holding readings
	std::vector<Reading> readings;
	std::vector<double> readings_temps;

	// get readings
	for (Reading r; ist >> r;) {
		if (ist.fail()) { std::cout << "Fail flag raised" << std::endl; break; }
		std::cout << r << std::endl;
		if (!is_valid(r)) {
			std::cout << "Invalid reading, skipping" << std::endl;
			break;
		}
		readings.push_back(r);
	}

	// get temperatures vector
	for (Reading r : readings) {
		readings_temps.push_back(r.temperature);
	}
	
	// get avg and median temperature
	double avg_temperature = (std::accumulate(readings_temps.begin(), readings_temps.end(), 0.0))/ readings_temps.size();
	std::sort(readings_temps.begin(), readings_temps.end());
	double median = get_median(readings_temps);
	std::cout << "Median: " << median << " Avg: " << avg_temperature << std::endl;

	// output file
	std::string output_filename = "ex3_output.txt";
	std::ofstream ost{ output_filename };
	if (!ost) { std::cout << "output issue case 1" << std::endl; }

	// save readings to file
	for (Reading r : readings) {
		ost << r;
	}
}