#include <AForm.hpp>

const char* AForm::GradeTooHighException::what() const throw() {
	return " The form grade is too high !\n";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return " The form grade too low !\n";
}

const char* AForm::IsSignable::what() const throw() {
	return " The form isn't usable, sign it !\n";
}

AForm::AForm() : name("default"), sign(false), grade_sign(150), grade_exec(150) {}

AForm::AForm(std::string name, int const grade_sign, int const grade_exec) : name(name), sign(false) , grade_sign(grade_sign), grade_exec(grade_exec){
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), sign(other.sign) , grade_sign(other.grade_sign), grade_exec(other.grade_exec) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

AForm::~AForm() {}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > grade_sign)
		throw AForm::GradeTooLowException();
	sign = true;
}

std::string	AForm::getName() const {
	return name;
}

bool	AForm::getSign() const {
	return sign;
}

int	AForm::getGradeSign() const {
	return grade_sign;
}

int	AForm::getGradeExec() const {
	return grade_exec;
}

void AForm::executable(Bureaucrat const& executor) const {
	if (!getSign())
		throw IsSignable();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getSign() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeSign()
       << ", Grade to Execute: " << form.getGradeExec();
    return os;
}
