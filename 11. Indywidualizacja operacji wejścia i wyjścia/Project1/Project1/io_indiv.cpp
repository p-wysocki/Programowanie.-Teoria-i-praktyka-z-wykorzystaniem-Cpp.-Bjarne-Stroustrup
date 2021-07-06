#include "io_indiv.h"
#include <vector>
#include <cctype>
#include <sstream>

io_indiv::ex1_stream& io_indiv::ex1_stream::operator>>(std::string& line) {

	std::getline(source, line);
	buffer.clear();

	for (char& c : line) {
		if (lowercase) {
			c = std::tolower(c);
		}
		else {
			c = std::toupper(c);
		}
	}

	buffer.str(line);
	return *this;
}

io_indiv::ex1_stream::operator bool() {
	return !(source.fail() || source.bad()) && source.good();
}