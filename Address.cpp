#include "Address.h"
#include<iostream>
#include<string>

using namespace std;

// File scope starts here 

/*private static member cannot be accessed outside the class except for initialization*/
//Address Address::defaultAddress(0, "Milford Road", "Leicester", "Leicestershire", 1234);	// intitalize class variable 
Address Address::defaultAddress(1, "Mailsi Road Off Multan Road", "Vehari", "Punjab", 61100);	// intitalize class variable 

																								// Address default + overloaded constructor initializes all data members to user supplied values 
Address::Address(int aHouseNo, string aStreet, string aCity, string aProvince, int aPostCode) : HouseNo(aHouseNo), Street(aStreet), City(aCity), Province(aProvince), PostCode(aPostCode) {
	// initialization using member intializing list 
	setAddress(aHouseNo, aStreet, aCity, aProvince, aPostCode);
} // end overloaded constructor Address 

  /* Copy constructor with deep copy for pointer members*/
Address::Address(const Address &obj) : HouseNo(obj.getHouseNo()), Street(obj.getStreet()), City(obj.getCity()), Province(obj.getProvince()), PostCode(obj.getPostCode()) { }

// Stream Insertion
ostream & operator <<(ostream & os, const Address & a)
{
	os << a.getHouseNo() << ", " << a.getStreet() << "," << endl << a.getCity() << ", " << a.getProvince() << "," << endl << a.getPostCode();
	return os;
}

// Stream Extraction
istream & operator >>(istream & is, Address & a)
{
	int hNo, pCode;
	string St, Cty, Prov;

	cout << "Enter House no: ";
	is >> hNo;
	cout << "Enter Street: ";
	is.ignore(100, '\n');
	getline(is, St);
	cout << "Enter City: ";
	getline(is, Cty);
	cout << "Enter Province: ";
	getline(is, Prov);
	cout << "Enter Post Code: ";
	is >> pCode;
	a.setAddress(hNo, St, Cty, Prov, pCode);

	return is;
}


void Address::setHouseNo(int aHouseNo) {
	if (aHouseNo < 1) {
		cout << "ERROR: House no is invalid. Setting it to default value." << endl;
		HouseNo = defaultAddress.HouseNo;
	}
	else
		HouseNo = aHouseNo;
}
void Address::setStreet(string aStreet) {
	if (aStreet == "") {
		cout << "ERROR: No street info provided. Setting it to default value." << endl;
		Street = defaultAddress.Street;
	}
	else
		Street = aStreet;
}
void Address::setCity(string aCity) {
	if (aCity == "") {
		cout << "ERROR: No city name provided. Setting it to default value." << endl;
		City = defaultAddress.City;
	}
	else
		City = aCity;
}
void Address::setProvince(string aProvince) {
	if (aProvince == "") {
		cout << "ERROR: No city name provided. Setting it to default value." << endl;
		Province = defaultAddress.Province;
	}
	else
		Province = aProvince;
}
void Address::setPostCode(int aPostCode) {
	if (aPostCode < 1) {
		cout << "ERROR: Post code no is invalid. Setting it to default value." << endl;
		PostCode = defaultAddress.PostCode;
	}
	else
		PostCode = aPostCode;
}

void Address::setAddress(int aHouseNo, string aStreet, string aCity, string aProvince, int aPostCode) {
	setHouseNo(aHouseNo);
	setStreet(aStreet);
	setCity(aCity);
	setProvince(aProvince);
	setPostCode(aPostCode);
}
void Address::setAddress(const Address &obj) {
	setAddress(obj.getHouseNo(), obj.getStreet(), obj.getCity(), obj.getProvince(), obj.getPostCode());
}
int Address::getHouseNo()const {
	return HouseNo;
}
string Address::getStreet()const {
	return Street;
}
string Address::getCity()const {
	return City;
}
string Address::getProvince()const {
	return Province;
}
int Address::getPostCode()const {
	return PostCode;
}
Address Address::getAddress()const {
	return *this;
}
// print complete address 
void Address::PrintAddress()const {
	cout << getHouseNo() << ", " << getStreet() << "," << endl << getCity() << ", " << getProvince() << "," << endl << getPostCode() << endl;
} // end function PrintAddress 

  // set default Address
void Address::setDefaultAddress(int aHouseNo, string aStreet, string aCity, string aProvince, int aPostCode) {
	defaultAddress.setAddress(aHouseNo, aStreet, aCity, aProvince, aPostCode);
}

void Address::setDefaultAddress(const Address &obj) {
	defaultAddress.setDefaultAddress(obj.getHouseNo(), obj.getStreet(), obj.getCity(), obj.getProvince(), obj.getPostCode());
}

Address  Address::getDefaultAddress() {
	return defaultAddress;
}
void Address::printDefaultAddress() {
	defaultAddress.PrintAddress();
}
