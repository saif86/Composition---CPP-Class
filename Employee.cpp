#include "Employee.h"
#include<string>

// File scope starts here 

/*private static member cannot be accessed outside the class except for initialization*/
int Employee::noOfEmployees = 0;	// intitalize class variable 

									// Employee overloaded constructor initializes all data members to user supplied values 
Employee::Employee(string aName, string aNIC, const Date & dateOfBirth, const Date & dateOfHire, Address & aAddress, double aTaxRate, double aBasicSalary) : Name(aName), NIC(aNIC), BIRTH_DATE(dateOfBirth), HIRE_DATE(dateOfHire), eAddress(aAddress), taxRate(aTaxRate), basicSalary(aBasicSalary) {
	// initialization using member intializing list 
	
	noOfEmployees++; // increment no. of employees within constructor 
}// end overloaded constructor Employee

Employee::Employee(const Employee &obj) : Name(obj.getName()), NIC(obj.getNIC()), BIRTH_DATE(obj.getDOB()), HIRE_DATE(obj.getDOJ()), eAddress(obj.getAddress()), taxRate(obj.getTaxRate()), basicSalary(obj.getBasicSalary()){ 
	noOfEmployees++; // increment no. of employees within constructor 
}

 // Emplopyee destructor 
Employee::~Employee() {
	noOfEmployees--; // decrement no. of employees each time destructor is called 
}// end ~Employee destructor 

 // Stream Insertion
ostream & operator <<(ostream & os, const Employee & e) {
	os << "Name: " << e.getName() << endl;
	os << "NIC: " << e.getNIC() << endl;
	os << "DOB: " << e.getDOB() << endl;
	os << "DOJ: " << e.getDOJ() << endl;
	os << "Address: " << e.getAddress() << endl;
	os << "Tax Rate: " << e.getTaxRate() << endl;
	os << "Basic Salary: " << e.getBasicSalary() << endl;
	return os;
}

// Stream Extraction
istream & operator >>(istream & is, Employee & e) {
	string aName, aNIC;
	Address aAddress;
	double aTaxrate, aSalary;
	cout << "Enter name of Employee: ";
	getline(is, aName);
	cout << "Enter NIC of Employee: ";
	getline(is, aNIC);
	is >> aAddress;
	cout << "Enter tax rate: ";
	is >> aTaxrate;
	cout << "Enter basic salary: ";
	is >> aSalary;
	e.setEmployee(aName, aNIC, aAddress, aTaxrate, aSalary);
	return is;
}

 // static member function to access class variable 
int Employee::getTotalEmployee() {
	return noOfEmployees;
}// end static member function 

void Employee::setName(string aName) {
	if (!checkName(aName))
		cout << "Invalid name entered. Cannot set name." << endl;
	else
		Name = aName;
}
void Employee::setNIC(string aNIC) {
	if (!checkNIC(aNIC))
		cout << "Invalid NIC entered. Cannot set NIC." << endl;
	else
		NIC = aNIC;
}

void Employee::setAddress(int aHouseNo, string aStreet, string aCity, string aProvince, int aPostCode) {
	eAddress.setAddress(aHouseNo, aStreet, aCity, aProvince, aPostCode);
}
void Employee::setAddress(const Address & add) {
	eAddress.setAddress(add);
}
void Employee::setTaxRate(double aTaxRate) {
	if (aTaxRate < 0.0)
		cout << "Tax rate cannot be negative.";
	else
		taxRate = aTaxRate;
}
void Employee::setBasicSalary(double aBasicSalary) {
	if (aBasicSalary < 0.0)
		cout << "Basic salary cannot be negative.";
	else
		basicSalary = aBasicSalary;
}
void Employee::setEmployee(string aName, string aNIC, const Address & aAddress, double aTaxRate, double aBasicSalary) {
	setName(aName);
	setNIC(aNIC);
	setAddress(aAddress);
	setTaxRate(aTaxRate);
	setBasicSalary(aBasicSalary);
}
void Employee::setEmployee(const Employee &obj) {
	setEmployee(obj.getName(), obj.getNIC(), obj.getAddress(), obj.getTaxRate(), obj.getBasicSalary());
}

// set ZIP Code value 
void Employee::setZIP(int aZIP) {
	eAddress.setPostCode(aZIP);
}// end function setZIP 

string Employee::getName()const {
	return Name;
}
string Employee::getNIC()const {
	return NIC;
}
const Date & Employee::getDOB()const {
	return BIRTH_DATE;
}
const Date & Employee::getDOJ()const {
	return HIRE_DATE;
}
const Address & Employee::getAddress()const {
	return eAddress;
}
 // get Tax Rate
double Employee::getTaxRate()const {
	return taxRate;
}// end function getTaxRate

 // get Basic Salary
double Employee::getBasicSalary()const {
	return basicSalary;
}// end function getBasicSalary
 // get ZIP Code value 
int Employee::getZIP()const {
	return eAddress.getPostCode();
}// end function getZIP

 // print employee detail 
void Employee::PrintEmployee()const {
	cout << "Name: " << Name << endl;
	cout << "NIC: " << NIC << endl;
	cout << "DOB: " << BIRTH_DATE << endl;
	cout << "DOJ: " << HIRE_DATE << endl;
	cout << "Address: " << eAddress << endl;
	cout << "Tax Rate: " << taxRate << endl;
	cout << "Basic Salary: " << basicSalary << endl;
}// end function print

double Employee::calcSalary() {
	double tax, netSalary;
	tax = getTaxRate() * getBasicSalary();
	netSalary = getBasicSalary() - tax;

	return netSalary;
}
bool Employee::checkName(string aName)const {
	// first letter must be capital
	if (islower(aName[0]))
		return false;
	
	for (int i = 0; i < aName.length(); i++) {
		if (!isalpha(aName[i]) && aName[i] != ' ' && aName[i] != '.')
			return false;
		if (aName[i] == ' ' && islower(aName[i + 1]))
			return false;
		if (aName[i] == '.' && islower(aName[i + 1]))
			return false;
	}
	return true;
}

bool Employee::checkNIC(string aNIC)const {
	if (aNIC.length() > 15)
		return false;
	for (int i = 0; i < aNIC.length(); i++) {
		if (islower(aNIC[i]))
			return false;
		if (!isalnum(aNIC[i]) && aNIC[i] != '-')
			return false;
	}
	return true;
}
