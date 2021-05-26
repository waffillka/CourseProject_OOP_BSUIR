#pragma once
#include<iostream>

using namespace std;

class Data
{
	int day;
	int month;
	int year;
public:
	Data();
	Data(const Data& data);
	Data(int day, int month, int year);
	~Data();

	void setDate(int day, int month, int year);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay();
	int getMonth();
	int getYear();

	friend ostream& operator<< (ostream& out, const Data& temp);
	friend istream& operator>> (istream& in, Data& temp);
};
