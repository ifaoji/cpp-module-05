#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

#include <cstring>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), target_("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  if (this == &rhs) {
    return *this;
  }

  AForm::operator=(rhs);

  // Since `target_` is constant, it cannot be assigned to a new value
  // target_ = rhs.target_;

  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
    throw(AForm::GradeTooLowException, AForm::NotSignedException) {
  ensureCanExecute(executor);

  std::string filename = target_ + "_shrubbery";

  // TODO: should it error if the file already exists?
  // like should creation be mandatory
  std::ofstream outfile(filename.c_str());
  if (!outfile.is_open()) {
    std::cerr << "Failed to execute shrubbery form " << getName()
              << ", could not create file " << filename << ": "
              << strerror(errno) << std::endl;

    return;
  }

  outfile << ASCII_TREES;
  outfile.close();
  if (outfile.fail()) {
    std::cerr << "Failed to execute shrubbery form " << getName()
              << ", could not write trees to the file " << filename << ": "
              << strerror(errno) << std::endl;

    return;
  }
}
