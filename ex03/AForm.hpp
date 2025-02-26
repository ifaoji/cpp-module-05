#pragma once

#include "Bureaucrat.hpp"
#ifndef FORM_HPP_
#    define FORM_HPP_

#    include <iostream>
#    include <string>

class AForm {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };

    class NotSignedException : public std::exception {
       public:
        const char *what() const throw();
    };

    AForm(const std::string &name, int required_signing_grade,
          int required_execution_grade) throw(AForm::GradeTooHighException,
                                              AForm::GradeTooLowException);
    AForm(const AForm &other);

    virtual ~AForm();

    const std::string &getName() const;
    bool               getIsSigned() const;
    int                getRequiredSigningGrade() const;
    int                getRequiredExecutionGrade() const;

    void beSigned(const Bureaucrat &bureaucrat) throw(
        AForm::GradeTooLowException);

    void execute(const Bureaucrat &bureaucrat) const
        throw(AForm::GradeTooLowException, AForm::NotSignedException);

   private:
    static const int kMaxGrade = 1;
    static const int kMinGrade = 150;

    AForm();
    AForm &operator=(const AForm &rhs);

    const std::string name_;
    bool              is_signed_;
    const int         required_signing_grade_;
    const int         required_execution_grade_;

    virtual void executeUnchecked(const Bureaucrat &bureaucrat) const = 0;

    void validateGrade(int grade) const
        throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif
