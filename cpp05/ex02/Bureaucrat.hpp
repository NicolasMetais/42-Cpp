#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string		getName() const;
		int	getGrade() const;
		void			upGrade();
		void			downGrade();
		void			signForm(AForm& form);
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
		void	executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);