
#include <iostream>
#include <string>

int	main() {
	std::string string("HI THIS IS BRAIN");
	std::string	&stringREF = string;
	std::string	*stringPTR;

	stringPTR = &string;

	// print mem addresses
	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	// print values
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}
