#include "Data.h"

Data::Data()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Data::Data(const Data& data):
	day(data.day), month(data.month), year(data.year)
{
}

Data::Data(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Data::~Data()
{
}

void Data::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Data::setDay(int day)
{
	this->day = day;
}

void Data::setMonth(int month)
{
	this->month = month;
}

void Data::setYear(int year)
{
	this->year = year;
}

int Data::getDay()
{
	return this->day;
}

int Data::getMonth()
{
	return this->month;
}

int Data::getYear()
{
	return this->year;
}

ostream& operator<<(ostream& out, const Data& temp)
{
	out << temp.day << "." << temp.month << "." << temp.year;
	return out;
}

istream& operator>>(istream& in, Data& temp)

{
	in >> temp.day;
	in >> temp.month;
	in >> temp.year;
	return in;
}
