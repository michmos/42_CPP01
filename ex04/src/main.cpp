
#include "../inc/colors.hpp"
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>

static std::fstream	openFile(const std::string &fileName)
{
	std::fstream	file;

	file.open(fileName);
	if (!file.is_open())
	{
		throw std::ios_base::failure("Error when opening / creating file \"" + fileName + "\"");
	}
	return (file);
}

static std::fstream	openFile(const std::string &fileName, std::ios_base::openmode openmode)
{
	std::fstream	file;

	file.open(fileName, openmode);
	if (!file.is_open())
	{
		throw std::ios_base::failure("Error when opening / creating file \"" + fileName + "\"");
	}
	return (file);
}

static std::string	readFile(std::fstream &inFile)
{
	std::ostringstream	fileContent;

	// check for empty file
	inFile.seekg(0, std::ios_base::end);
	if (inFile.tellg() == 0)
	{
		return "";
	}
	inFile.seekg(0, std::ios_base::beg);

	fileContent << inFile.rdbuf();
	if (inFile.fail())
		throw std::ios_base::failure("Error when reading from file");
	if (fileContent.fail())
		throw std::ios_base::failure("Error when writing to filestream");
	return (fileContent.str());
}

static void	replaceStrings(std::string &fileContent, const std::string &s1, const std::string &s2)
{
	size_t	idx = 0;
	size_t	strLen = s1.length();

	while (true)
	{
		idx = fileContent.find(s1, idx);
		if (idx == std::string::npos)
			break ;
		fileContent.erase(idx, strLen);
		fileContent.insert(idx, s2);
		idx += s2.length();
	}
}

int	main(int argc, char *argv[])
{
	std::string		inFileName;
	std::string		outFileName;
	std::fstream	inFile;
	std::fstream	outFile;
	std::string		fileContent;
	std::string		s1, s2;

	if (argc != 4) {
		std::cerr << RED << "Usage: ./cheapSed <filename> <s1> <s2>" << RESET << std::endl;
		return (0);
	}

	inFileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	outFileName = inFileName + ".replace";
	try
	{
		inFile = openFile(inFileName);
		outFile = openFile(outFileName, std::ios_base::out | std::ios_base::trunc);
		fileContent = readFile(inFile);
	}
	catch (std::ios_base::failure &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
	if (!s1.empty() && s1 != s2)
		replaceStrings(fileContent, s1, s2);
	outFile << fileContent;
	if (outFile.fail())
	{
		std::cerr << RED << "Error writing to file \"" << outFileName << RESET << std::endl;
		return (1);
	}
	return (0);
}

