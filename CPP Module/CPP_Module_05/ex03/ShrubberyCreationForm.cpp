#include "ShrubberyCreationForm.hpp"

/* Orthodox Canonical Form(private part) */
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhv)
{
	(void)rhv;
	return (*this);
}

/* Orthodox Canonical Form(public part) */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp) \
	throw(GradeTooHighException, GradeTooLowException) : AForm(cp) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {};

/* Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const string &target) \
	: AForm("ShrubberyCreationForm", target, 145, 137) {}

/* virtual function overriding */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException)
{
	if (isExecutable(executor.getGrade()) == false)
		return ;

	std::ofstream	fout;

	fout.open((getTarget() + "_shrubbery").c_str(), std::ios_base::out);
	if (!fout.is_open())
	{
		cout << "Error : File open failed." << endl;
		exit(1);
	}

	fout << "       _-_" << endl;
	fout << "    /~~   ~~\\" << endl;
	fout << " /~~         ~~\\" << endl;
	fout << "{               }" << endl;
	fout << " \\  _-     -_  /" << endl;
	fout << "   ~  \\\\ //  ~" << endl;
	fout << "_- -   | | _- _" << endl;
	fout << "  _ -  | |   -_" << endl;
	fout << "      // \\\\" << endl;
}
