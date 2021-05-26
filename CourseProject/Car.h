#pragma once

#include<iostream>
#include <fstream>

using namespace std;

class Car
{
	int wheelbase;
	string mark;
	string model;
	string machineNumber;
	int number;
	bool status;
public:
	Car();
	Car(const Car& car);
	Car(int wheelbase, string mark,	string model, string machineNumber, int number = 0,	bool status = true);
	~Car();

	void setNumberCar(int);
	void setWheelbase(int);
	void setMark(string);
	void setModel(string);
	void setMachineNumber(string);
	void setStatus(bool);

	bool getStatus();
	int getWheelbase();
	string getMark();
	string getModel();
	string getMachineNumber();
	int getNumberCar();

	friend ostream& operator<< (std::ostream& out, const Car& point);
	friend istream& operator>> (istream& in, Car& point);

	void writeCarInFile(char*);
};