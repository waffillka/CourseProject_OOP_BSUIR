#include "Place.h"

void Place::setCountry(string country)
{
	this->country = country;
}

void Place::setCity(string city)
{
	this->city = city;
}

void Place::setStreet(string street)
{
	this->street = street;
}

void Place::setHouse(string house)
{
	this->house = house;
}

void Place::setPlace(string country, string city, string street, string house)
{
	this->country = country;
	this->city = city;
	this->street = street;
	this->house = house;
}

string Place::getCountry()
{
	return this->country;
}

string Place::getCity()
{
	return this->city;
}

string Place::getStreet()
{
	return this->street;
}

string Place::getHouse()
{
	return this->house;
}

Place::Place()
{
}

Place::Place(string country, string city, string street, string house)
{
	this->city = city;
	this->country = country;
	this->house = house;
	this->street = street;
}

Place::~Place()
{
}

ostream& operator<<(ostream& out, const Place& temp)
{
	//out << "Страна: " << temp.country << "\nГород/населенный пункт: " << temp.city << "\nУлица: " << temp.street << "\nДом: " << temp.house << endl;
	out << temp.country << ", гр." << temp.city << ", ул." << temp.street << " д." << temp.house;
	return out;
}

istream& operator>>(istream& in, Place& temp)
{
	cout << "Страна: ";
	in >> temp.country;
	cout << "Город/населенный пункт: ";
	in >> temp.city;
	cout << "Улица: ";
	in >> temp.street;
	cout << "Дом: ";
	in >> temp.house;
	return in;
}
