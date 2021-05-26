#include "Car.h"

Car::Car()
{
	this->machineNumber = "";
	this->mark = "";
	this->model = "";
	this->number = 0;
	this->status = false;
	this->wheelbase = 0;
}

Car::Car(const Car& car) :
	wheelbase(car.wheelbase), mark(car.mark), model(car.model), machineNumber(car.machineNumber), number(car.number), status(car.status)
{
}


Car::Car(int wheelbase, string mark, string model, string machineNumber, int number, bool status)
{
	this->machineNumber = machineNumber;
	this->mark = mark;
	this->model = model;
	this->wheelbase = wheelbase;
	this->number = number;
	this->status = status;
}

Car::~Car()
{
}

void Car::setNumberCar(int number)
{
	this->number = number;
}

void Car::setWheelbase(int wheelbase)
{
	this->wheelbase = wheelbase;
}

void Car::setMark(string mark)
{
	this->mark = mark;
}

void Car::setModel(string model)
{
	this->model = model;
}

void Car::setMachineNumber(string machineNumber)
{
	this->machineNumber = machineNumber;
}

void Car::setStatus(bool status)
{
	this->status = status;
}

bool Car::getStatus()
{
	return this->status;
}

int Car::getWheelbase()
{
	return this->wheelbase;
}

string Car::getMark()
{
	return this->mark;
}

string Car::getModel()
{
	return this->model;
}

string Car::getMachineNumber()
{
	return this->machineNumber;
}

int Car::getNumberCar()
{
	return this->number;
}

void Car::writeCarInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::app);
	if (!f) { cerr << "Невозможно открыть базовый файл\n"; exit(-1); }
	f.seekp(0, ios_base::end);
	f << endl << this->wheelbase << "\t" << this->mark << "\t" << this->model << "\t" << this->machineNumber << "\t" << this->number << "\t" << this->status;
	if (!f) { cerr << "Запись  в файл невозможна\n"; exit(-1); }
	f.close();
}

ostream& operator<<(std::ostream& out, const Car& point)
{
	out << "Производитель машины: " << point.mark << "\nМодель машины: " << point.model;
	out << "\nКолесная база: " << point.wheelbase << "\nРегистрационный номер: " << point.machineNumber << endl;
	return out;
}

istream& operator>>(istream& in, Car& point)
{
	cout << "Производитель машины: ";
	in >> point.mark; 
	cout << "Модель машины: ";
	in >> point.model;
	cout << "Колесная база: ";
	in >> point.wheelbase;
	cout << "Регистрационный номер: ";
	in >> point.machineNumber;
	return in;
}
