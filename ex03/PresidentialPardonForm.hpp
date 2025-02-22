#pragma once

#ifndef PRESIDENTIAL_PARDON_FORM_HPP_
#    define PRESIDENTIAL_PARDON_FORM_HPP_

#    include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);

    ~PresidentialPardonForm();

    const std::string &getTarget() const;

   private:
    PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    void executeUnchecked(const Bureaucrat &) const;

    const std::string target_;
};

#endif
