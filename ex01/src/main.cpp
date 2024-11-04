
#include "../inc/ex01.hpp"
#include <exception>
#include <new>

int	main(int argc, char *argv[])
{
	Zombie	*pZombie;
	int		num;

	if (argc != 3) {
		std::cerr << "Usage: ./zombies <num> <name>" << std::endl;
		return (0);
	}

	// get num
	try {
		num = std::stoi(argv[1]);
		if (num < 0) 
			throw std::exception();
	} catch (...) {
		std::cerr << "Num argument wrong or too big" << std::endl;
		return (0);
	}

	// test
	try {
		pZombie = zombieHorde(num, argv[2]);
	}
	catch (std::bad_alloc) {
		std::cerr << "Allocation failed" << std::endl;
		return (1);
	}


	for (int i = 0; i < num; ++i) {
		pZombie[i].announce();
	}

	// deallocate objects
	delete [] pZombie;
	return (0);
}
