#ifndef Employee_HEADER 
#define Employee_HEADER
#include <iostream>
#include"Date.h"
#include"Address.h"
using namespace std;
// Employee class definition 
class Employee {
	string Name;
	string NIC;
	const Date BIRTH_DATE;
	const Date HIRE_DATE;
	Address eAddress;
	double taxRate;
	double basicSalary;

	static int noOfEmployees;		// class variable to count total no. of employees
	bool checkName(string)const;		// utility function to check valid name
	bool checkNIC(string)const;		// utility function to check valid NIC
public:
	Employee(string = "", string = "", const Date & = Date::getDefaultDate(), const Date & = Date::getDefaultDate(), Address & = Address::getDefaultAddress(), double = 0.0, double = 0.0); // overloaded constructor
	Employee(const Employee &);		//copy constructor
	~Employee(); // destructor

	friend ostream & operator <<(ostream &, const Employee &);		// Stream Insertion
	friend istream & operator >>(istream &, Employee &);			// Stream Extraction

	// setters
	void setName(string);
	void setNIC(string);
	void setAddress(int = 0, string = "", string = "", string = "", int = 0);
	void setAddress(const Address &);
	void setTaxRate(double = 0.0);
	void setBasicSalary(double = 0.0);
	void setEmployee(string, string, const Address &, double, double);
	void setEmployee(const Employee &);
	void setZIP(int = 0); // Setter function for Postal(ZIP) Code
	
	// getters
	string getName()const;
	string getNIC()const;
	const Date & getDOB()const;
	const Date & getDOJ()const;
	const Address & getAddress()const;
	double getTaxRate()const;
	double getBasicSalary()const;
	int getZIP()const; // Getter function for Postal(ZIP) Code 
	void PrintEmployee()const; // prints all the details of the employee 

	static int getTotalEmployee(); // static member function 
		
	double calcSalary();
}; // end class Employee

#endif