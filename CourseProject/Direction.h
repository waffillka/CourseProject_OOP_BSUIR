#pragma once
#include"Data.h"
#include"Place.h"

class Direction
{
	Place placeOfShipment;
	Data shippingDate;

	Place placeOfUnloading;
	Data dateOfUnloading;
public:
	Direction();
	Direction(const Direction& temp);
	Direction(Place placeOfShipment, Data shippingDate, Place placeOfUnloading, Data dateOfUnloading);

	void setPlaceOfShipment(Place placeOfShipment);
	void setPlaceOfShipment(string country, string city, string street, string house);
	void setShippingDate(Data shippingDate);
	void setShippingDate(int day, int month, int year);
	void setPlaceOfUnloading(Place placeOfUnloading);
	void setPlaceOfUnloading(string country, string city, string street, string house);
	void setDateOfUnloading(Data dateOfUnloading);
	void setDateOfUnloading(int day, int month, int year);

	Place getPlaceOfShipment();
	Place getPlaceOfUnloading();
	Data getShippingDate();
	Data getDateOfUnloading();

	friend ostream& operator<< (ostream& out, const Direction& temp);
	friend istream& operator>> (istream& in, Direction& temp);
};