#include "io_indiv.h"
#include <fstream>

int main() {

	std::ifstream ex1_source{ "ex1_source.txt", std::ios::in };
	io_indiv::ex1_stream ex1_stream{ ex1_source };
	

	ex1_source.close();
}