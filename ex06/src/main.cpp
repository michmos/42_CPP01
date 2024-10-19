
#include "../inc/Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: harlFilter <level>\n";
		return (0);
	}

	Harl::complain(argv[1]);
	return 0;
}
