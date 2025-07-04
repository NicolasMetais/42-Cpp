#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
	private:
		std::string const	name;
		unsigned int		grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			upGrade();
		void			downGrade();
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
	
};