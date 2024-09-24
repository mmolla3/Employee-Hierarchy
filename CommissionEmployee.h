/* 
Mohammed Molla
Dakota Hernandez
CISC 2000
Lab #10: Employee Hieararchy 
*/

//#pragma once: don't need if we have ifndef and define

#include <iostream>
#include "Employee.h"

#ifndef _COMMISSION_H
#define _COMMISSION_H

//Postcondition: CommissionEmployee inherits from the Employee base class and is an extension of it 
class CommissionEmployee : public Employee

{
public:
	// ToDo: declare default constructor for CommissionEmployee
	CommissionEmployee();


	// ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
	// Postcondition: Constructor for CommissionEmployee that takes name, SSN, sales, and commission percent is declared
	CommissionEmployee(string name, string ssn, double sales, double commissionVal);


	// ToDo: declare Accessor/Mutator functions

	//Accessor Functions
	double get_commission()const;//returns commission percent
	double get_sales()const;//returns total sales
	//Mutator Functions
	void set_commission(double newcommissionVal);//sets commission percent to a new variable
	void set_sales(double newsalesAmt);//sets the sales to a new variable


	// ToDo: declare vitual functions to override

	//Postcondition: Virtual function to print check has been declared and will be overridden a
	// will print the check with appropriate necessities such as the commission amoutn and sales
	void print_check() const;

	//Postcondition: prompts user to input commission amount and sales. Returns the input stream
	istream& promptInput(istream& in, ostream& out);//follow same format as previous classes

	//Postcondition: will calculate net pay, refer to base class
	double get_net_pay() const;
	
private:
	// ToDo: declare a sales, commission percent member
	double sales;
	double commission;

};
#endif 