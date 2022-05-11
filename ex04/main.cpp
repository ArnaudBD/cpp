#include <iostream>
#include <string>
#include <fstream>
#include <ios>

int main(int ac, char *av[])
{
	if (ac != 4)
		return 1;
	std::string filename = av[1];
	std::string outfile = filename + ".replace";
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string::size_type found;
	std::string line;

	std::ifstream ifs(av[1]);
	std::ofstream ofs (outfile.c_str());
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		found = line.find(s1);
		while (found != std::string::basic_string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
			found = line.find(s1);
		}
		ofs << line;
	}





}