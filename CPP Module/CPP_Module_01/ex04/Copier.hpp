#ifndef COPIER_HPP
#define COPIER_HPP

#include "Editor.hpp"

class Copier
{
	private :
		ifstream	fin;
		ofstream	fout;
		Editor		ed;
	public :
		Copier(const string &file_name, const string &s1, const string &s2);
		~Copier();
		void	copyFile();
};

#endif