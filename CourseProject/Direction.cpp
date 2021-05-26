#include "Direction.h"

Direction::Direction()
{
}

Direction::Direction(const Direction& temp)
{
	this->dateOfUnloading = temp.dateOfUnloading;
	this->placeOfShipment = temp.placeOfShipment;
	this->placeOfUnloading = temp.placeOfUnloading;
	this->shippingDate = temp.shippingDate;
}

Direction::Direction(Place placeOfShipment, Data shippingDate, Place placeOfUnloading, Data dateOfUnloading)
{
	this->dateOfUnloading = dateOfUnloading;
	this->placeOfShipment = placeOfShipment;
	this->placeOfUnloading = placeOfUnloading;
	this->shippingDate = shippingDate;
}

void Direction::setPlaceOfShipment(Place placeOfShipment)
{
	this->placeOfShipment = placeOfShipment;
}

void Direction::setPlaceOfShipment(string country, string city, string street, string house)
{
	this->placeOfShipment.setPlace(country, city, street, house);
}

void Direction::setShippingDate(Data shippingDate)
{
	this->shippingDate = shippingDate;
}

void Direction::setShippingDate(int day, int month, int year)
{
	this->shippingDate.setDate(day, month, year);
}

void Direction::setPlaceOfUnloading(Place placeOfUnloading)
{
	this->placeOfUnloading = placeOfUnloading;
}

void Direction::setPlaceOfUnloading(string country, string city, string street, string house)
{
	this->placeOfUnloading.setPlace(country, city, street, house);
}

void Direction::setDateOfUnloading(Data dateOfUnloading)
{
	this->dateOfUnloading = dateOfUnloading;
}

void Direction::setDateOfUnloading(int day, int month, int year)
{
	this->dateOfUnloading.setDate(day, month, year);
}

ostream& operator<<(ostream& out, const Direction& temp)
{
	out << "Место загрузки: " << temp.placeOfUnloading << "\nДата загрузки: " << temp.dateOfUnloading;
	out << "\nМесто выгрузки: " << temp.placeOfShipment << "\nДата выгрузки: " << temp.shippingDate << endl;
	return out;
}

istream& operator>>(istream& in, Direction& temp)
{	
	cout << "Место загрузки: ";
	in >> temp.placeOfUnloading;
	cout  << "Дата загрузки: ";
	in >> temp.dateOfUnloading;
	cout << "Место выгрузки: ";
	in >> temp.placeOfShipment;
	cout  << "Дата выгрузки: ";
	in >> temp.shippingDate;
	return in;
}

Place Direction::getPlaceOfShipment()
{
	return this->placeOfShipment;
}

Place Direction::getPlaceOfUnloading()
{
	return this->placeOfUnloading;
}

Data Direction::getShippingDate()
{
	return this->shippingDate;
}

Data Direction::getDateOfUnloading()
{
	return this->dateOfUnloading;
}
