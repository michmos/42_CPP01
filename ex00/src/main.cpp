
#include "../inc/ex00.hpp"

int	main(void)
{
	Zombie	*pZombie;
	randomChump("peter");

	pZombie = new Zombie("heaper");
	pZombie->announce();
	delete pZombie;

	return (0);
}
