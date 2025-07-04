#include <iostream>
#include <string.h>
#include <fstream>

std::string extract_file(std::string content, std::ifstream& file)
{
	std::string line;
	int			nb_line = 0;
	int			i = 0;

	while (std::getline(file, line))
		nb_line++;
	file.clear();
	file.seekg(0);
	while (std::getline(file, line))
	{
		if (i == nb_line - 1)
			content = content + line;
		else
			content = content + line + "\n";
		i++;
	}
	file.close();
	return (content);
}

std::string replace_content(std::string content, char *s1, char *s2) 
{
	size_t	pos = 0;
	size_t found;
	std::string	new_content;
	std::string	find = s1;
	std::string	replace = s2;

	while ((found = content.find(find, pos)) != std::string::npos)
	{
		new_content += content.substr(pos, found - pos);
		new_content += replace;
		pos = found + find.length();
	}
	new_content += content.substr(pos);
	return new_content;
}

int main (int ac, char **av) 
{
	std::string content;
	std::ifstream file;
	
	if (ac == 4)
	{
		std::string filename = av[1];
		file.open(av[1]);
		if(!file.is_open())
		{
			std::cout << "Error \n open failed" << std::endl;
			return 1;
		}
		content = extract_file(content, file);
		content = replace_content(content, av[2], av[3]);
		filename += ".replace";
		std::ofstream newfile(filename.c_str());
		if (newfile.is_open())
		{
			newfile << content;
			newfile.close();
		}
		else
		{
			std::cout << "Error \n open failed" << std::endl;
			return 1;
		}
	}
	else
		std::cout << "Error \n wrong args" << std::endl;
}
