#include <string>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <limits>

std::string define_av( const char *av)
{
	int count_dot = 0;
	int count_f = 0;
	std::string str_av = std::string(av);
	for (size_t i = 0 ; av[i] && (isdigit(av[i]) || av[i] == '.' || (i != 0 && av[i] == 'f') || av[0] == '+' || av[0] == '-') ; i++)
	{
			
		if (av[i] == '.')
			count_dot++;
		if (av[i] == 'f')
		{
			if (i == 0)
			{
				if (av[i + 1])
					return "other";
				return "float";
			}
			count_f++;
		}
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
	}
	if (isprint(av[0]) && !av[1] && !isdigit(av[0]))
		return "char";
	return "other";
}

size_t	findPrecision(const char *av)
{
	std::string str_av = std::string(av);
	std::string dot(".");

	std::size_t found = str_av.find(dot);
	if (found == std::string::npos)
		return (0);
	return (str_av.length() - found - 1);
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
	size_t		p = findPrecision(av[1]);
	if (str_av == "nan" || str_av == "nanf")
	{
		type = "not a number";
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
	else if (str_av == "+inf" || str_av == "+inff" || str_av == "-inf" || str_av == "-inff")
	{
		type = "limit";
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << ((av[1][0] == '-') ? "-" : "+" ) << std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << ((av[1][0] == '-') ? "-" : "+" ) << std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (type == "other")
	{
		std::cerr << "Error: this is not a double, a float, an int nor a char" << std::endl;
		return (2);
	}
	else if (type != "char" && type != "other")
	{
		double	d_num = static_cast<double>(std::atof(av[1]));
		float	f_num = d_num;
		int		i_num = static_cast<int>(f_num);
		char	c_num = static_cast<char>(i_num);
		
		if (isprint(c_num))
			std::cout << "char: " << "'" << c_num << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (d_num > std::numeric_limits<int>::max() || d_num < std::numeric_limits<int>::min())
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << i_num << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(p) << f_num << ((p == 0) ? ".0f" : "f") << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(p) << d_num << ((p == 0) ? ".0" : "") << std::endl;
		// std::cout << "float: " << f_num << ((str_av.find('.') == std::string::npos) ? ".00f" : "f") << std::endl;
		// std::cout << "double: " << d_num << ((str_av.find(".") == std::string::npos) ? ".00" : "") << std::endl;
	}
	else if (type == "char")
	{
		double	d_num = static_cast<double>(av[1][0]);
		float	f_num = d_num;
		int		i_num = static_cast<int>(f_num);
		std::cout << "char: " << av[1] << std::endl;
		std::cout << "int: " << i_num << std::endl;
		std::cout << "float: " << f_num << ".0f" << std::endl;
		std::cout << "double: " << d_num << ".0" << std::endl;
	}
	std::cout << "type: " << type << std::endl;
	return (0);
}