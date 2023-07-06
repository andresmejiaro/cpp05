/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:56:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 10:31:55 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string	ShubberyCreationForm::_getTree() const{
	 std::string tree2 = 
  "              _{\\ _{\\{\\/}/}/}__\n"
    "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
    "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
    "         {\\{/(/\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
    "        {/{/(_)/}{\\{/)/\\}{\\(_){/}/}/}/}\n"
    "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
    "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
    "      _{\\{/{\\{\\/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
    "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
    "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
    "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
    "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
    "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
    "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
    "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
    "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
    "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
    "              {){/ {\\/}{\\/} \\}\\}\n"
    "              (_)  \\.-'.-/\n"
    "          __...--- |'-.-'| --...__\n"
    "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
    "-\"    ' .  . '    |.'-._| '  . .  '   jro\n"
    ".  '-  '    .--'  | '-.'|    .  '  . '\n"
    "          ' ..     |'-_.-|\n"
    "  .  '  .       _.-|-._ -|-._  .  '  .\n"
    "              .'   |'- .-|   '.\n"
    "..-'   ' .  '.   `-._.-�   .'  '  - .\n"
    "   .-' '        '-._______.-'     '  .\n"
    "        .      ~,\n"
    "    .       .   |\\   .    ' '-.\n";

	 std::string tree1 = 
"                       ___\n\
                _,-'\"\"   \"\"\"`--.\n\
             ,-'          __,,-- \\\n\
           ,'    __,--\"\"\"dF      )\n\
          /   .-\"Hb_,--\"\"dF      /\n\
        ,'       _Hb ___dF\"-._,-'\n\
      ,'      _,-\"\"\"\"   \"\"--..__\n\
     (     ,-'                  `.\n\
      `._,'     _   _             ;\n\
       ,'     ,' `-'Hb-.___..._,-'\n\
       \\    ,\"Hb.-'HH`-.dHF\"\n\
        `--'   \"Hb  HH  dF\"\n\
                \"Hb HH dF\n\
                 \"HbHHdF\n\
                  |HHHF\n\
                  |HHH|\n\
                  |HHH|\n\
                  |HHH|\n\
                  |HHH|\n\
                  dHHHb\n\
                .dFd|bHb.               o\n\
      o       .dHFdH|HbTHb.          o /\n\
\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n\
##########################################\n";

if (std::time(0) & 1)
	return tree1;
else
	return tree2;
}

ShubberyCreationForm::ShubberyCreationForm(): 
	AForm("Shubbery Creation Form", 145, 137),_target("No one"){
	
}

ShubberyCreationForm::ShubberyCreationForm(std::string target): 
	AForm("Shubbery Creation Form", 145, 137),_target(target){
	
}

ShubberyCreationForm::ShubberyCreationForm(const ShubberyCreationForm &other):
	AForm(other),_target(other.getTarget()){
		
}

ShubberyCreationForm &ShubberyCreationForm::operator=(const ShubberyCreationForm &other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);
}

ShubberyCreationForm::~ShubberyCreationForm(){
	
}

std::string	ShubberyCreationForm::getTarget() const{
	return (this->_target);
}

bool ShubberyCreationForm::execute(Bureaucrat const &executor) const{
	if (this->gradeCheckerExecute(executor) && this->getSigned() == true){
		std::ofstream file;
		file.open((this->getTarget() + "_shubbery").c_str(), std::ios_base::out);
		if (file.is_open()){
			file << this->_getTree();
			file.close();
			return (true);
		}
		else {
			std::cerr << "Open Error!";
		}
	}
	else if (!this->getSigned()){
		throw (AForm::UnsignedException());
	}
	else 
		throw (AForm::GradeTooLowException());
	return (false);
}

