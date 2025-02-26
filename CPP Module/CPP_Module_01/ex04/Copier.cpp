#include "Copier.hpp"

Copier::Copier(const string &file_name, const string &s1, const string &s2) \
 : fin(file_name.c_str(), ios_base::in), ed(s1, s2)
{
	if (fin.fail())
	{
		cout<<"Error : Can not open file."<<endl;
		exit(1);
	}
	else
		fout.open((file_name + ".replace").c_str(), ios_base::out);
}

Copier::~Copier()
{
	fin.close();
	fout.close();        
}

void	Copier::copyFile()
{
	string	buf;

	while (getline(fin, buf))
		fout << ed.editLine(buf) << endl;

}