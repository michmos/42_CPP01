
#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	static void debug();
	static void info();
	static void warning();
	static void error();


public:
	Harl();
	~Harl();

	static void complain(std::string level);
};

#endif // !HARL_HPP
