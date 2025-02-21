#pragma once

#include "Bureaucrat.hpp"
#ifndef FORM_HPP_
#    define FORM_HPP_

#    include <iostream>
#    include <string>

class Form {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };

    Form();
    Form(const std::string &name, int required_signing_grade,
         int required_execution_grade) throw(Form::GradeTooHighException,
                                             Form::GradeTooLowException);
    Form(const Form &other);

    ~Form();

    Form &operator=(const Form &rhs);

    const std::string &getName() const;
    bool               getIsSigned() const;
    int                getRequiredSigningGrade() const;
    int                getRequiredExecutionGrade() const;

    void beSigned(const Bureaucrat &bureaucrat) throw(
        Form::GradeTooLowException);

   private:
    static const int kMaxGrade = 1;
    static const int kMinGrade = 150;

    const std::string name_;
    bool              is_signed_;
    const int         required_signing_grade_;
    const int         required_execution_grade_;

    void validateGrade(int grade) const
        throw(Form::GradeTooHighException, Form::GradeTooLowException);
};

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif
