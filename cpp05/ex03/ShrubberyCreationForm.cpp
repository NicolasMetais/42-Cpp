#include <ShrubberyCreationForm.hpp>
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	executable(executor);
	std::ofstream newfile((target + "_shrubbery").c_str());
	if (!newfile)
		throw std::ios_base::failure(" File opening failed\n");
	newfile << "\n"
		 << "      /\\\n"
		 << "     /**\\\n"
		 << "    /****\\\n"
		 << "   /******\\\n"
		 << "      ||\n";
	newfile.close();
}

