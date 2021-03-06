/**
* @file Source.cpp
*
* @brief This code tests Composition of Employee class.
* Employee class is composed from Date and Address classes.
*
* @author Saif Ullah Ijaz
*
*/
#include<iostream>
using namespace std;
#include "Employee.h"

// function main begins program execution
void main()
{
	cout << "Employee count: " << Employee::sGetTotalEmployee() << endl;
	Employee e1("Saif Ullah Ijaz", "AD1673333", Date(1, 1, 1986), Date(28, 1, 2014), Address(1857, "Some street", "Lahore", "Punjab", 4500), 0.40, 30000);
	cout << "Employee 1: " << endl;
	cout << e1;
	Employee e2 = e1;
	cout << "Employee 2: " << endl;
	cout << e2 << endl;
	e2.SetZIP(37460);
	cout << "Employee2 zipcode: " << e2.GetZIP() << endl;
	cout << "Employee2 net salary: " << e2.CalcSalary() << endl;
	cout << "Employee count: " << Employee::sGetTotalEmployee() << endl;
	system("pause");
}
// end main
