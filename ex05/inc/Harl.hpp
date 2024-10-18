
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

	void complain(std::string level);

public:
	Harl();
	~Harl();
};

#endif // !HARL_HPP
