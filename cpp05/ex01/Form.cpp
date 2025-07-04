#include <Form.hpp>

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

Form::Form() : name("default"), sign(false), grade_sign(150), grade_exec(150) {}

Form::Form(std::string name, int const grade_sign, int const grade_exec) : name(name), sign(false) , grade_sign(grade_sign), grade_exec(grade_exec){
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), sign(other.sign) , grade_sign(other.grade_sign), grade_exec(other.grade_exec) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

Form::~Form() {}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	sign = true;
}

std::string	Form::getName() const {
	return name;
}

bool	Form::getSign() const {
	return sign;
}

int	Form::getGradeSign() const {
	return grade_sign;
}

int	Form::getGradeExec() const {
	return grade_exec;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getSign() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeSign()
       << ", Grade to Execute: " << form.getGradeExec();
    return os;
}
