#pragma once

#ifndef BUREAUCRAT_HPP_
#    define BUREAUCRAT_HPP_

#    include <iostream>
#    include <string>

class Form;

// TODO: check whether this Bureaucrat has a typo or not
class Bureaucrat {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string &name,
               int grade) throw(Bureaucrat::GradeTooHighException,
                                Bureaucrat::GradeTooLowException);
    Bureaucrat(const Bureaucrat &other);

    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &rhs);

    const std::string &getName() const;
    int                getGrade() const;

    void incrementGrade() throw(Bureaucrat::GradeTooHighException);
    void decrementGrade() throw(Bureaucrat::GradeTooLowException);

    void signForm(Form &form) const;

   private:
    static const int kMaxGrade = 1;
    static const int kMinGrade = 150;

    const std::string name_;
    int               grade_;

    void validateGrade(int grade) const throw(Bureaucrat::GradeTooHighException,
                                              Bureaucrat::GradeTooLowException);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif
