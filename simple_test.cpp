/* 
Mohammed Molla
Dakota Hernandez
CISC 2000
Lab #10: Employee Hieararchy 
*/

//Description: This program is the main program that prompts the user to enter employee information
//and then respectively creates objects of classes based on the input. The objects 
//get stored in two separate vectors and two different functions are used to print 
//the information that goes on employee's checks. All dynamically allocated memory
//gets deleted at the end


//DISPLAY 15.7 Using Derived Classes
#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
#include "CommissionEmployee.h"
#include <vector>
using namespace std;

// payday function - using vector of pointers
void paydayPtrs(const vector<Employee*>& employeePtrs);

// payday function - using vector of pointers
void paydaySlices(const vector<Employee>& employeeSlices);

int main( )
{
    vector<Employee*> employeePtrs;
    vector<Employee> employeeSlices;
	int numberEmployees;

	cout << "Welcome to ABC Corporation!!\n";
	cout << "Enter the number of employees: ";
	cin >> numberEmployees;
	
	// Enter the number of employees
	for (int i=0; i<numberEmployees; i++)
    {
		cout <<"Enter employee #"<<(i+1)<<":\n";
		string type; 
        cout <<"Enter the type of employee (hourly, salaried, admin, commission):";
        cin >> type;

		// Request an hourly employee
		if (type=="hourly")
		{
			// Construct an HourlyEmployee
			HourlyEmployee * hourly = new HourlyEmployee();

			// Prompt for input
			hourly->promptInput(cin, cout);

			// Store in the vectors
			employeePtrs.push_back(hourly);//push_back function is required to enter data in a vector
			employeeSlices.push_back(*hourly);
		} 
		else if (type=="salaried")
		{
			// Construct a SalariedEmployee
			SalariedEmployee * mgmt = new SalariedEmployee();

			// Prompt for input
			mgmt->promptInput(cin, cout);

			// Add to the lists
			employeePtrs.push_back(mgmt);
			employeeSlices.push_back(*mgmt);
		} 
		else if (type =="admin")
		//follow same format as above for admin and commission
		// Construct an Adminstrator
		{
   			//ToDo: Test your Administrator class here... 
			Administrator * admin = new Administrator();
			
			//ToDo: prompt for input
			admin->promptInput(cin,cout);

			//ToDo: Add to the lists as above
			employeePtrs.push_back(admin);
			employeeSlices.push_back(*admin);

		}
		else if (type == "commission")
		{
			//ToDo: Test your Commission class here... 
			CommissionEmployee * commissioned = new CommissionEmployee();

			//ToDo: prompt for input
			commissioned->promptInput(cin, cout);

			//ToDo: Add to the lists as above
			employeePtrs.push_back(commissioned);
			employeeSlices.push_back(*commissioned);

		}

   }

	// Print pointers
	paydayPtrs(employeePtrs);
	paydaySlices(employeeSlices);

    //ToDo: free up dynamically allocated memory through a for loop because it is a vector 
	for (int i = 0; i < employeePtrs.size(); i++) {
    	delete employeePtrs[i];
	}
	
}

//Payday!-- dont need to touch
void paydaySlices(const vector<Employee>& employeeSlices)
{ 
   cout <<"***********************************************\n";
   cout <<"Payday Slices! Print all checks in a batch!\n";
   for (int i=0;i<employeeSlices.size();i++)

   {
   		cout << "Slice Check for " << employeeSlices[i].get_name() << endl;
   		employeeSlices[i].print_check( );
   		cout << endl;
   }
}
//Payday!-- dont need to touch 
void paydayPtrs(const vector<Employee*>& employeePtrs)
{ 
   cout <<"***********************************************\n";
   cout <<"Payday Virtual! Print all checks in a batch!\n";
   for (int i=0;i<employeePtrs.size();i++)
   {
   		cout << "Virtual Check for " << employeePtrs[i]->get_name() << endl;
   		employeePtrs[i]->print_check( );
   		cout << endl;
   }
}