
#include "../inc/colors.hpp"
#include <ios>
#include <iostream>
#include <fstream>


void	replaceStrings(std::string &line, const std::string &s1, const std::string &s2)
{
	size_t	idx = 0;
	while ((idx = line.find(s1, idx)) != line.npos) {
		line.erase(idx, s1.length());
		line.insert(idx, s2);
		idx += s2.length();
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (EXIT_FAILURE);

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	// open infile
	std::ifstream	infile;
	infile.open(filename);
	if (infile.fail()) {
		return (EXIT_FAILURE);
	}

	// open outfile
	std::ofstream	outfile;
	outfile.open(filename + ".replace");
	if (outfile.fail()) {
		return (EXIT_FAILURE);
	}

	std::string	line;
	while (std::getline(infile, line)) {
		if (s1 != s2 && !s1.empty())
		{
			replaceStrings(line, s1, s2);
		}
		outfile << line;
		if (!infile.eof())
			outfile << "\n";
	}

	infile.close();
	outfile.close();
	return (0);
}
