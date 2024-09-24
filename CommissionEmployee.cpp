/* 
Mohammed Molla
Dakota Hernandez
CISC 2000
Lab #10: Employee Hieararchy 
*/

#include "CommissionEmployee.h"

// ToDo: implement the default constructor, remember to call base class constructor
// base class constructor = Employee
CommissionEmployee::CommissionEmployee(): Employee(), sales(0), commission(0){
	// deliberately empty
}


// ToDo: implement the constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(string name, string ssn, double sales, double commissionVal)

{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n"; ??
}

// ToDo: implement accessor/mutators

//Accessor Functions
double CommissionEmployee:: get_commission() const{
	return commission;
}
double CommissionEmployee:: get_sales()const{
	return sales;
}
//Mutator Functions
void CommissionEmployee:: set_commission(double newcommissionVal) {
	commission = newcommissionVal;
}
void CommissionEmployee:: set_sales(double newsalesAmt){
	sales = newsalesAmt;
}

// ToDo: implement virtual get_net_pay function
// Hint: compensation is commission/100 * sales
double CommissionEmployee:: get_net_pay()const{
	return commission/100 * sales;
}

// ToDo: implement the virtual print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void CommissionEmployee::print_check() const
{
	Employee::print_check();
	cout << "Commission Employee." << endl;
    cout << "Gross sales: " << sales << " Commission: " << commission << " Pay: " << get_net_pay() << endl;
    cout << "_________________________________________________\n";
}


// ToDo: implement the virtual promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream& CommissionEmployee::promptInput(istream& in, ostream& out)
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee

	Employee::promptInput(in, out);
	out << "Enter sales and commission: ";
	in >> sales >> commission;
	return in;
	// ToDo: read the sales and commission.
}