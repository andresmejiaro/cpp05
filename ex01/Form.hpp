class Form
{
	private:
		std:string	_name;
		bool			_isSigned;
		int				_gradeToSign;
		int				_gradeToExecute;
	public:
		Form();
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		Form(const std::string name,int gradeToSign, int gradeToExecute);
		std:string getName() const:
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void				beSigned(const Bureocrat officer);
};
std::ostream operator<<(std::ostream os, const Form form);
