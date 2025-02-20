/*
                                                         .
                                              .         ;
                 .              .              ;%     ;;
                   ,           ,                :;%  %;
                    :         ;                   :;%;'     .,
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%;        ,     %;    ;%;    ,%'
              %;       %;%;      ,  ;       %;  ;%;   ,%;'
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'
                        `@%.  `;@%.      ;@@%;
                          `@%%. `@%%    ;@@%;
                            ;@%. :@%%  %@@%;
                              %@bd%%%bd%%:;
                                #@%%%%%:;;
     ccee88oo                   %@@%%%::;
  C8O8O8Q8PoOb o8oo             %@@@%(o);  . '
 dOB69QO8PdUOpugoO9bD           %@@@o%;:(.,'         %%%,%%%%%%%
CgggbU8OU qOp qOdoUOdcb     `.. %@@@o%::;             ,'%% \\-*%%%%%%%
    6OuU  /p u gcoUodpP        `)@@@o%::;       ;%%%%%*%   _%%%%'
      \\\//  /douUP             %@@(o)::;        ,%%%       \(_.*%%%%.
        \\\////                .%@@@@%::;        % *%%, ,%%%%*(    '
         |||/\                 ;%@@@@%::;.     %^     ,*%%% )\|,%%*%,_
         |||\/                ;%@@@@%%:;;;.         *%    \/ #).-"*%%*
         |||||            ...;%@@@@@%%:;;;;,..           _.) ,/ *%,
   .....//||||\....                                ______/)#(______
*/

#pragma once

#ifndef SHRUBBERY_CREATION_FORM_HPP_
#define SHRUBBERY_CREATION_FORM_HPP_

#include <string>

#include "AForm.hpp"

#define ASCII_TREES                                                            \
  "                                                         .\n              " \
  "                                .         ;\n                 .           " \
  "   .              ;%     ;;\n                   ,           ,             " \
  "   :;%  %;\n                    :         ;                   :;%;'     "   \
  ".,\n           ,.        %;     %;            ;        %;'    ,;\n        " \
  "     ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;     " \
  "  %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        "  \
  ";%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         "      \
  "`;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n          " \
  "          `:%;.  :;bd%;          %;@%;'\n                      `@%:.  "     \
  ":;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n     " \
  "                     `@%%. `@%%    ;@@%;\n                            "     \
  ";@%. :@%%  %@@%;\n                              %@bd%%%bd%%:;\n           " \
  "                     #@%%%%%:;;\n     ccee88oo                   "          \
  "%@@%%%::;\n  C8O8O8Q8PoOb o8oo             %@@@%(o);  . '\n "               \
  "dOB69QO8PdUOpugoO9bD           %@@@o%;:(.,'         "                       \
  "%%%,%%%%%%%\nCgggbU8OU qOp qOdoUOdcb     `.. %@@@o%::;             ,'%% "   \
  "\\\\-*%%%%%%%\n    6OuU  /p u gcoUodpP        `)@@@o%::;       ;%%%%%*%   " \
  "_%%%%'\n      \\\\\\//  /douUP             %@@(o)::;        ,%%%       "    \
  "\\(_.*%%%%.\n        \\\\\\////                .%@@@@%::;        % *%%, "   \
  ",%%%%*(    '\n         |||/\\                 ;%@@@@%::;.     %^     "      \
  ",*%%% )\\|,%%*%,_\n         |||\\/                ;%@@@@%%:;;;.         "   \
  "*%    \\/ #).-\"*%%*\n         |||||            ...;%@@@@@%%:;;;;,..      " \
  "     _.) ,/ *%,\n   .....//||||\\....                                "      \
  "______/)#(______\n"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);

  ~ShrubberyCreationForm();

  const std::string &getTarget() const;

  void execute(const Bureaucrat &bureaucrat) const
      throw(AForm::GradeTooLowException, AForm::NotSignedException);

private:
  ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  const std::string target_;
};

#endif
