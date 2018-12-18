#ifndef Address_HEADER 
#define Address_HEADER

#include <iostream>

using namespace std;
// Address class definition 
class Address {
	int HouseNo;
	string  Street;
	string City;
	string Province;
	int PostCode;
	static Address defaultAddress;

public:
	Address(int = 0, string = "", string = "", string = "", int = 0);	// default + overloaded constructor
	Address(const Address &);		//copy constructor

	friend ostream & operator <<(ostream &, const Address &);	// Stream Insertion
	friend istream & operator >>(istream &, Address &);			// Stream Extraction

																// setters
	void setHouseNo(int = 0);
	void setStreet(string = "");
	void setCity(string = "");
	void setProvince(string = "");
	void setPostCode(int = 0);
	void setAddress(int = 0, string = "", string = "", string = "", int = 0);
	void setAddress(const Address &);

	// getters
	int getHouseNo()const;
	string getStreet()const;
	string getCity()const;
	string getProvince()const;
	int getPostCode()const;
	Address getAddress()const;

	void PrintAddress()const;	// prints the complete address 

	static void setDefaultAddress(int = 0, string = "", string = "", string = "", int = 0);
	static void setDefaultAddress(const Address &);
	static Address getDefaultAddress();
	static void printDefaultAddress(); // static member function 
}; // end class Address

#endif
