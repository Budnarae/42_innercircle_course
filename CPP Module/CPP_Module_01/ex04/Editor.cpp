#include "Editor.hpp"
#include <string>

Editor::Editor(const string &s1, const string &s2) : s1(s1), s2(s2)
{
}

string	Editor::editLine(const string &line)
{
	string	modified_line;
	size_t	pos = 0;
	size_t	n;

	while (pos < std::strlen(line.c_str()))
	{
		n = (size_t)line.find(s1, pos);
		
		if (n == (size_t)string::npos)
		{
			modified_line += line.substr(pos, n);
			break ;
		}
		else
		{
			if (n > pos)
				modified_line += line.substr(pos, n - pos);
			modified_line += s2;
			pos = n + std::strlen(s1.c_str());
		}
	}

	return (modified_line);
}