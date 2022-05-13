#include <iostream>
#include <string>
#include <fstream>
#include <ios>

int main(int ac, char *av[])
{
	if (ac != 4)
		return (1);
	std::string filename = av[1];
	std::string outfile = filename + ".replace";
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string::size_type found;
	std::string line;

	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "Can't open " << s1 << std::endl;
		return (2);
	}

	std::ofstream ofs (outfile.c_str());
	if (!ofs.is_open())
	{
		std::cout << "Can't open " << s2 << std::endl;
		ifs.close();
		return (3);
	}

	while (!ifs.eof())
	{
		std::getline(ifs, line);
		found = line.find(s1);
		while (s1.length() && found != std::string::basic_string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
			found += s2.length();
			found = line.find(s1, found);
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}