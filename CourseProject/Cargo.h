#pragma once
#include<vector>
#include"Worker.h"
#include "Direction.h"
#include "Car.h"

class Cargo
{
	float weight;
	bool overallDimensions; //габаритный/негабаритный
	int orderFulfillmentDriver;
	int car;
	Direction direction;

public:
	Cargo();
	Cargo(float weight, bool overallDimensions, int orderFulfillmentDriver, int car, Direction direction);
	Cargo(float weight, bool overallDimensions, int orderFulfillmentDriver, int car, int dateOfUnloadingDay, 
		int dateOfUnloadingMonth, int dateOfUnloadingYear, int shippingDateDay, int shippingDateMonth, int shippingDateYear,
		string placeOfShipmentCountry, string placeOfShipmentCity, string placeOfShipmentStreet, string placeOfShipmentHouse,
		string placeOfUnloadinCountry, string placeOfUnloadinCity, string placeOfUnloadinStreet, string placeOfUnloadinHouse);
	~Cargo();
	void setWeight(float);
	void setOverallDimensions(bool);
	void setCar(int);
	void setorderFulfillmentDriver(int);

	void writeCargoInFile(char* file_cargo);
	float getWeight();
	bool getOverallDimensions();
	int getCar();
	int setorderFulfillmentDriver();

	void getDriversTrueOrFalse(bool, vector<Worker>);
	void outCargo(vector<Worker>& driverTemp, vector<Car>& carTemp);
	void inCargo(vector<Worker>& drivers);

	friend ostream& operator<< (std::ostream& out, const Cargo& point);
};
