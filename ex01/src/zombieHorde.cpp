
#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	// allocate memory
	Zombie	*pZombie = static_cast<Zombie *>(operator new(sizeof(Zombie) * N, std::nothrow));
	if (!pZombie) {
		std::cerr << "allocation failed" << std::endl;
		return (nullptr);
	}

	// construct objects at specified mem addresses
	for (int i =0; i < N; ++i) {
		new (&pZombie[i]) Zombie(name);
	}
	return (pZombie);
}

