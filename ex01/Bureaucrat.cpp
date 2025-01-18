#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name_("Default Bureaucrat"), grade_(kMinGrade) {}

Bureaucrat::Bureaucrat(const std::string &name,
                       int grade) throw(Bureaucrat::GradeTooHighException,
                                        Bureaucrat::GradeTooLowException)
    : name_(name) {
  validateGrade(grade);

  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this == &rhs)
    return *this;

  // Since the name is a constant, it cannot be assigned to a new value
  // name_ = rhs.name_;

  grade_ = rhs.grade_;

  return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

const std::string &Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade() throw(Bureaucrat::GradeTooHighException) {
  int new_grade = grade_ - 1;
  validateGrade(new_grade);

  grade_ = new_grade;
}

void Bureaucrat::decrementGrade() throw(Bureaucrat::GradeTooLowException) {
  int new_grade = grade_ + 1;
  validateGrade(new_grade);

  grade_ = new_grade;
}

void Bureaucrat::validateGrade(int grade) const
    throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) {
  if (grade < kMaxGrade) {
    throw Bureaucrat::GradeTooHighException();
  }

  if (grade > kMinGrade) {
    throw Bureaucrat::GradeTooLowException();
  }
}

void Bureaucrat::signForm(Form &form) const {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << std::endl;
  } catch (Form::GradeTooLowException &e) {
    std::cout << name_ << " couldn't sign " << form.getName() << " because "
              << e.what() << "." << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs) {
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;

  return os;
}
