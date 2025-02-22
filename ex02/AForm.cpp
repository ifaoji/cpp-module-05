#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::NotSignedException::what() const throw() {
    return "Not signed";
}

AForm::AForm()
    : name_("Default AForm"),
      is_signed_(false),
      required_signing_grade_(150),
      required_execution_grade_(150) {
}

AForm::AForm(const std::string &name, int required_signing_grade,
             int required_execution_grade) throw(AForm::GradeTooHighException,
                                                 AForm::GradeTooLowException)
    : name_(name),
      is_signed_(false),
      required_signing_grade_(required_signing_grade),
      required_execution_grade_(required_execution_grade) {
    validateGrade(required_signing_grade);
    validateGrade(required_execution_grade);
}

AForm::AForm(const AForm &other)
    : name_(other.name_),
      is_signed_(other.is_signed_),
      required_signing_grade_(other.required_signing_grade_),
      required_execution_grade_(other.required_execution_grade_) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &rhs) {
    if (this == &rhs) return (*this);

    // Since those are constant, they cannot be assigned to a new value
    // name_ = rhs.name_;
    // required_signing_grade_ = rhs.required_signing_grade_;
    // required_execution_grade_ = rhs.required_execution_grade_;

    is_signed_ = rhs.is_signed_;

    return (*this);
}

const std::string &AForm::getName() const {
    return name_;
}

bool AForm::getIsSigned() const {
    return is_signed_;
}

int AForm::getRequiredSigningGrade() const {
    return required_signing_grade_;
}

int AForm::getRequiredExecutionGrade() const {
    return required_execution_grade_;
}

void AForm::validateGrade(int grade) const
    throw(AForm::GradeTooHighException, AForm::GradeTooLowException) {
    if (grade < kMaxGrade) {
        throw AForm::GradeTooHighException();
    }

    if (grade > kMinGrade) {
        throw AForm::GradeTooLowException();
    }
}

void AForm::beSigned(const Bureaucrat &bureaucrat) throw(
    AForm::GradeTooLowException) {
    if (required_signing_grade_ < bureaucrat.getGrade()) {
        throw AForm::GradeTooLowException();
    }

    is_signed_ = true;
}

void AForm::execute(const Bureaucrat &bureaucrat) const
    throw(AForm::GradeTooLowException, AForm::NotSignedException) {
    bool bureaucrat_powerful_enough =
        bureaucrat.getGrade() <= required_execution_grade_;
    if (!bureaucrat_powerful_enough) {
        throw AForm::GradeTooLowException();
    }

    if (!is_signed_) {
        throw AForm::NotSignedException();
    }

    executeUnchecked(bureaucrat);
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form { name: \"" << form.getName()
       << "\", is_signed: " << form.getIsSigned()
       << ", required_signing_grade: " << form.getRequiredSigningGrade()
       << ", required_execution_grade: " << form.getRequiredExecutionGrade()
       << " }";

    return os;
}
