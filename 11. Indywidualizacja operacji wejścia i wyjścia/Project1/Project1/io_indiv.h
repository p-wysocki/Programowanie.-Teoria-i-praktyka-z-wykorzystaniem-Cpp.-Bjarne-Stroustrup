#pragma once
#include <iostream>

namespace io_indiv {
	class ex1_stream {
	// read a file, change all contents to lowercase, write to another file
	public:
		ex1_stream(std::istream& is)
			: source{ is }, lowercase{ true } {}

		void to_lowercase(bool b) { lowercase = b; };
		bool is_lowercase() { return lowercase; };

		operator bool();
		ex1_stream& operator>>(std::string& s);

	private:
		std::istream& source;
		bool lowercase;
		std::istringstream buffer;

	};


}