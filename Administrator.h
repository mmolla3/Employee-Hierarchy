/* 
Mohammed Molla
Dakota Hernandez
CISC 2000
Lab #10: Employee Hieararchy 
*/

/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the title (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start with the version from 
 *  SalariedEmployee
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator:public SalariedEmployee
{
  public:
	// ToDo: declare default constructor for Administrator
	//Precondition: the base class default constructor is called with initalized variables of the job name and bonus
	//Postcondition: an object of administrator class is intialized with created member variables
	Administrator();


	// ToDo: declare constructor for Administrator that takes a name, SSN, salary, title, bonus
	//Precondtion: the SalariedEmployee constructor is called with all previous variables in addition to the two new ones(jobTitle and bonus)
	//Postcondition: an object of admin class is initialized with jobTitle and bonus and the other parameters are also then created
	Administrator(string name, string ssn, double salary, string jobTitle, double bonus);

	// ToDo: declare Accessor/Mutator functions
	
	//Accessors
	double get_bonus()const;//returns value of bonus member variable
	string get_title()const;//returns the string of jobTitle member variable
	//Mutators
	void set_bonus(double newBonus);//sets bonus variable to a a new variable
	void set_title(string newJobTtl);//sets jobTitle string to a new string

	// ToDo: declare vitual functions to override

	//Postcondition: the job title and bonus amount is printed on the check
	void print_check() const;

	//Postcondition: the user is prompted to enter the bonus and job title which is then set to the variables.
	istream& promptInput(istream& in, ostream& out);//same functions in instructions

	//Postcondition: Returns pay amount for the administrator that gets printed on check
	double get_net_pay() const;


  private: 
	// ToDo: declare a job title, bonus member
	string jobTitle;
	double bonus;
};
#endif