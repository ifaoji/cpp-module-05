/*
              _________
             /~~~~~~~~~\
            (===========) ______________
            |  ||  ||   ||~~~~~~~~~~~~~~|
            |  ||  ||   ||        (@)   |
            |  ||  ||   ||        //    |
            |  ||  ||   ||       //     |
            |  ||  ||   ||(@)===(o)     |
            |  ||  ||   ||        \\    |
            |           ||         \\   |
            |~~~~~~~~~~~||         (@)  |
            |___________||              |
            (___________)|              |
             (_________) |    @--(o)    |
               |     |   (              (
               |     |    \      (o)     \
               |     |     \     /        \
               |     |      \   @          \
               |_____|       \              \
               |_____|        \              \
               \_____/         \              \
                 |/|            \              \
              )  |/|             \              \
             (  ,|/|  / '         \              \
              \  |/| ( '           \              \
        _____  ) |/|' )         _   \              \
  |    |     |___|/|___________| |   \              \
  |====|     |_________________| |    \              \
 =|   _|      |_______________|  |     \              \
     |                           |      \              \
_____|___________________________|_______)______________)
|                                                        |
|                                                        |
|________________________________________________________|
*/

#pragma once

#ifndef ROBOTOMY_REQUEST_FORM_HPP_
#    define ROBOTOMY_REQUEST_FORM_HPP_

#    include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);

    ~RobotomyRequestForm();

    const std::string &getTarget() const;

   private:
    RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    void executeUnchecked(const Bureaucrat &) const;

    const std::string target_;
};

#endif
