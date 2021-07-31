#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <span>
#include <cstddef>
#include <iomanip>

void ex1() {
	// make all chars in a text file lowercase
	std::ifstream ifs{ "ex1_source.txt" };
	std::ofstream ofs{ "ex1_destination.txt" };

	std::string line;
	while (ifs) {
		std::getline(ifs, line);
		for (char& ch : line) {
			if (!isspace(ch))
				ch = tolower(ch);
			ofs << ch;
		}
		ofs << '\n';
	}
}

void ex2() {
	// find lines with a specific word in them
	std::string searched_word, file_name;
	std::cout << "Searched word, file name:" << std::endl;
	std::cin >> searched_word >> file_name;

	std::ifstream ifs{ file_name };
	std::string line;
	int line_counter{ 1 };
	while (ifs) {
		std::getline(ifs, line);
		if (line.find(searched_word) != std::string::npos) {
			std::cout << "Line no. " << line_counter << ": " << line << std::endl;
		}
		++line_counter;
	}
}

void ex9() {
	// convert files binary->string and string->binary and compare results
	std::ifstream string_source{ "ex2_source.txt", std::ios_base::in };
	std::ofstream binary_dest{ "ex9_dest.txt", std::ios_base::binary | std::ios_base::out };

	std::vector<int> binary_contents;
	std::vector<std::string> string_contents;

	std::string line;
	// read the string file
	while (string_source) {
		string_contents.emplace_back(std::getline(string_source, line));
	}
	// string->binary
	for (const std::string& k : string_contents) {
		binary_dest.write(std::as_bytes(k), sizeof(k));
	}
}

int main() {
	//ex1();
	//ex2();
	ex9();

}