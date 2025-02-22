#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), target_("default_target") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5), target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &rhs) {
    if (this == &rhs) return *this;

    AForm::operator=(rhs);

    // Since `target_` is constant, it cannot be assigned to a new value
    // target_ = rhs.target_;

    return *this;
}

const std::string &PresidentialPardonForm::getTarget() const {
    return target_;
}

void PresidentialPardonForm::executeUnchecked(const Bureaucrat &) const {
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}
