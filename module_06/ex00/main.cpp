#include <string>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

std::string define_av( const char *av)
{
	int count_dot = 0;
	int count_f = 0;
	std::string str_av = std::string(av);
	for (size_t i = 0 ; av[i] && (isdigit(av[i]) || av[i] == '.' || (i != 0 && av[i] == 'f')) ; i++)
	{
			
		if (av[i] == '.')
			count_dot++;
		if (count_dot > 1 || count_f > 1)
			return "other";
		if (i == (str_av.length() - 1))
		{
			if (count_f)
				return "float";
			if (count_dot)
				return "double";
			return "int";
		}
		if (av[i] == 'f')
		{
			if (i == 0 && av[i + 1])
				return "other";
			count_f++;
		}
	}
	if (isprint(av[0]) && !av[1] && !isdigit(av[0]))
		return "char";
	return "other";
}

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: Wrong number of arguments!" << std::endl;
		return (1);
	}
	std::string str_av = std::string(av[1]);
	std::string type = define_av(av[1]);

	std::cout << "The type is: " << type << std::endl;

	if (type != "char" && type != "other")
	{
		double	d_num = static_cast<double>(std::atof(av[1]));
		float	f_num = d_num;
		int		i_num = static_cast<int>(f_num);
		char	c_num = static_cast<char>(i_num);
		std::cout << "char: " << ((isprint(c_num)) ? c_num + "" : "Non diplayable") << std::endl;
		std::cout << "int: " << i_num << std::endl;
		std::cout << "float: " << f_num << ((str_av.find(".")) ? ".00" : "") << "f" << std::endl;
		std::cout << "double: " << d_num << ((str_av.find(".")) ? ".00" : "") << std::endl;
	}
	else if (type == "char")
	{
		double	d_num = static_cast<double>(av[1][0]);
		float	f_num = d_num;
		int		i_num = static_cast<int>(f_num);
		std::cout << "char: " << av[1] << std::endl;
		std::cout << "int: " << i_num << std::endl;
		std::cout << "float: " << f_num << "f" << std::endl;
		std::cout << "double: " << d_num << std::endl;
	}

	return (0);
}