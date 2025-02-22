#pragma once

#ifndef INTERN_HPP_
#    define INTERN_HPP_

#    include "AForm.hpp"

class Intern {
   public:
    Intern();
    Intern(const Intern &other);

    ~Intern();

    Intern &operator=(const Intern &rhs);

    AForm *makeForm(const std::string &form_name,
                    const std::string &form_target) const;

   private:
    AForm *createShrubberyCreationForm(const std::string &form_target) const;
    AForm *createRobotomyRequestForm(const std::string &form_target) const;
    AForm *createPresidentialPardonForm(const std::string &form_target) const;

    typedef AForm *(Intern::*AFormFactoryPtr)(const std::string &) const;

    struct NameToForm {
        std::string     name;
        AFormFactoryPtr factory;
    };

    static NameToForm kNameToForms[3];
};

#endif
