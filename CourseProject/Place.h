#pragma once
#include<iostream>

using namespace std;

class Place
{
protected:
	string country;
	string city;
	string street;
	string house;

public:
	void setCountry(string);
	void setCity(string);
	void setStreet(string);
	void setHouse(string);
	void setPlace(string country, string city, string street, string house);

	string getCountry();
	string getCity();
	string getStreet();
	string getHouse();

	Place();
	Place(string country, string city, string street, string house);
	//Place(const Place& place);
	~Place();

	friend ostream& operator<< (ostream& out, const Place& temp);
	friend istream& operator>> (istream& in, Place& temp);
};
