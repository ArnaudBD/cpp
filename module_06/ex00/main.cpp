#include <string>
#include <cstdlib>
#include <iostream>

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: Wrong number of arguments!" << std::endl;
		return (1);
	}
	double	d_num = static_cast<double>(std::atof(av[1]));
	float	f_num = std::atof(av[1]);
	int		i_num = static_cast<int>(f_num);
	char	c_num = static_cast<char>(i_num);


	return (0);
}