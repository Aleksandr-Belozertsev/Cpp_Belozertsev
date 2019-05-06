#include "markov.h"

int main(int argc, char* argv[])
{
	/*if (argc != 3)
	{
		std::cout << "usage:\n " << argv[0] << " rulefile text\n";
		return EXIT_FAILURE;
	}*/

	std::ifstream rulefile("rulefile.txt");
	std::vector<rule> rules = read_rules(rulefile);

	std::string input("I bought a B of As from T S.");
	std::string output = markov(rules, input);

	std::cout << output << "\n";
}