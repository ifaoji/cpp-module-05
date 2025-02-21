#include "Form.hpp"

#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

Form::Form()
    : name_("Default Form"),
      is_signed_(false),
      required_signing_grade_(150),
      required_execution_grade_(150) {
}

Form::Form(const std::string &name, int required_signing_grade,
           int required_execution_grade) throw(Form::GradeTooHighException,
                                               Form::GradeTooLowException)
    : name_(name),
      is_signed_(false),
      required_signing_grade_(required_signing_grade),
      required_execution_grade_(required_execution_grade) {
    validateGrade(required_signing_grade);
    validateGrade(required_execution_grade);
}

Form::Form(const Form &other)
    : name_(other.name_),
      is_signed_(other.is_signed_),
      required_signing_grade_(other.required_signing_grade_),
      required_execution_grade_(other.required_execution_grade_) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &rhs) {
    if (this == &rhs) return (*this);

    // Since those are constant, they cannot be assigned to a new value
    // name_ = rhs.name_;
    // required_signing_grade_ = rhs.required_signing_grade_;
    // required_execution_grade_ = rhs.required_execution_grade_;

    is_signed_ = rhs.is_signed_;

    return (*this);
}

const std::string &Form::getName() const {
    return name_;
}

bool Form::getIsSigned() const {
    return is_signed_;
}

int Form::getRequiredSigningGrade() const {
    return required_signing_grade_;
}

int Form::getRequiredExecutionGrade() const {
    return required_execution_grade_;
}

void Form::validateGrade(int grade) const
    throw(Form::GradeTooHighException, Form::GradeTooLowException) {
    if (grade < kMaxGrade) {
        throw Form::GradeTooHighException();
    }

    if (grade > kMinGrade) {
        throw Form::GradeTooLowException();
    }
}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(
    Form::GradeTooLowException) {
    if (required_signing_grade_ < bureaucrat.getGrade()) {
        throw Form::GradeTooLowException();
    }

    is_signed_ = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form { name: \"" << form.getName()
       << "\", is_signed: " << form.getIsSigned()
       << ", required_signing_grade: " << form.getRequiredSigningGrade()
       << ", required_execution_grade: " << form.getRequiredExecutionGrade()
       << " }";

    return os;
}
