/* 
Mohammed Molla
Dakota Hernandez
CISC 2000
Lab #10: Employee Hieararchy 
*/

/* Implement Administrator class */
#include <iostream>
using namespace std;
#include "Administrator.h"

using namespace std;

// ToDo: implement the default constructor, remember to call base class constructor
// this calls the default constructured of the SalareidEmployee which is Administrator's base class
Administrator::Administrator():SalariedEmployee(), jobTitle("NULL"), bonus(0){
	//because one parameter is a string, it has to be initialized to a string, not a zero. 

}

// ToDo: implement the constructor, remember to call base class constructor
Administrator::Administrator(string name, string ssn, double salary, string jobTitle, double bonus)

{
	// deliberately empty
	// cout << "Adminstrator(" << name << "," << SSN << "," << salary << "," << title << ")\n"; 
}


// ToDo: implement accessor/mutators

// Accessor Functions
// The following accessor functions are used to simply retrieve the job title and bonus value. 
// At any point in the program, whichever value is stored in the variables "bonus" and "jobTitle", are not changed.
double Administrator :: get_bonus() const{
	return bonus;
}
string Administrator:: get_title()const{
	return jobTitle;
}
// Mutator Functions
// The following mutator functions are setting the string and value into a new variable.
void Administrator :: set_bonus(double newBonus){
	bonus = newBonus;
}
void Administrator:: set_title(string newJobTtl){
	jobTitle = newJobTtl;
}


// ToDo: implement virtual functions
// ToDo: implement virtual get_net_pay function
// Hint: compensation is salary + bonus
// Plug above formula into return value!

double Administrator:: get_net_pay()const{
	return SalariedEmployee::get_salary() + bonus;
}

// ToDo: implement the print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
// copy and paste from base class but change the formatting!
void Administrator::print_check()const
{
	SalariedEmployee::print_check();
	cout << "Administrator Title:" << jobTitle << endl;
    cout << "Bonus: " << bonus << " Pay: " << get_net_pay() << endl;
	cout << "_________________________________________________\n";
}

// ToDo: implement the promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream & Administrator::promptInput(istream & in, ostream & out) 
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
	SalariedEmployee::promptInput(in, out);
	out << "Enter bonus and title: ";
	in >> bonus;
	ignorespace(in);
	getline(in, jobTitle);
	return in;

	// ToDo: read the bonus. Use ignorespace() to skip newline.
	// ToDo: read the rest of the line for the title
}

