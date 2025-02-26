#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "ref.hpp"

class Editor
{
	private :
		string	s1;
		string	s2;
	public :
		Editor(const string &s1, const string &s2);
		string	editLine(const string &line);
};

#endif