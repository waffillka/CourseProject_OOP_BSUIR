#include"Cargo.h"

Cargo::Cargo()
{
	this->weight = 0.0;
	this->orderFulfillmentDriver = 0;
	this->overallDimensions = false;
	this->car = 0;
}

Cargo::Cargo(float weight, bool overallDimensions, int orderFulfillmentDriver, int car, Direction direction)
{
	this->weight = weight;
	this->orderFulfillmentDriver = orderFulfillmentDriver;
	this->overallDimensions = overallDimensions;
	this->car = car;
	this->direction = direction;
}

Cargo::Cargo(float weight, bool overallDimensions, int orderFulfillmentDriver, int car, int dateOfUnloadingDay, int dateOfUnloadingMonth, int dateOfUnloadingYear, int shippingDateDay, int shippingDateMonth, int shippingDateYear, string placeOfShipmentCountry, string placeOfShipmentCity, string placeOfShipmentStreet, string placeOfShipmentHouse, string placeOfUnloadinCountry, string placeOfUnloadinCity, string placeOfUnloadinStreet, string placeOfUnloadinHouse)
{
	this->direction.setDateOfUnloading(dateOfUnloadingDay, dateOfUnloadingMonth, dateOfUnloadingYear);
	this->direction.setShippingDate(shippingDateDay, shippingDateMonth, shippingDateYear);
	this->direction.setPlaceOfShipment(placeOfShipmentCountry, placeOfShipmentCity, placeOfShipmentStreet, placeOfShipmentHouse);
	this->direction.setPlaceOfUnloading(placeOfUnloadinCountry, placeOfUnloadinCity, placeOfUnloadinStreet, placeOfUnloadinHouse);
	this->car = car;
	this->orderFulfillmentDriver = orderFulfillmentDriver;
	this->overallDimensions = overallDimensions;
	this->weight = weight;
}

Cargo::~Cargo()
{
}

void Cargo::setWeight(float weight)
{
	this->weight = weight;
}

void Cargo::setOverallDimensions(bool overallDimensions)
{
	this->overallDimensions = overallDimensions;
}

void Cargo::setCar(int car)
{
	this->car = car;
}

void Cargo::setorderFulfillmentDriver(int driver)
{
	this->orderFulfillmentDriver = driver;
}

void Cargo::writeCargoInFile(char* file_cargo)
{
	ofstream f;
	f.open(file_cargo, ios::app);
	if (!f) { cerr << "Невозможно открыть базовый файл\n"; exit(-1); }
	f.seekp(0, ios_base::end);
	f << endl << this->weight << "\t" << this->overallDimensions << "\t" << this->orderFulfillmentDriver << "\t" << this->car << "\t";
	f << this->direction.getDateOfUnloading().getDay() << "\t" << this->direction.getDateOfUnloading().getMonth() << "\t" << this->direction.getDateOfUnloading().getYear() << "\t";
	f << this->direction.getShippingDate().getDay() << "\t" << this->direction.getShippingDate().getMonth() << "\t" << this->direction.getShippingDate().getYear() << "\t";
	f << this->direction.getPlaceOfShipment().getCountry() << "\t" << this->direction.getPlaceOfShipment().getCity() << "\t" << this->direction.getPlaceOfShipment().getStreet() << "\t" << this->direction.getPlaceOfShipment().getHouse() << "\t";
	f << this->direction.getPlaceOfUnloading().getCountry() << "\t" << this->direction.getPlaceOfUnloading().getCity() << "\t" << this->direction.getPlaceOfUnloading().getStreet() << "\t" << this->direction.getPlaceOfUnloading().getHouse();

	if (!f) { cerr << "Запись  в файл невозможна\n"; exit(-1); }
	f.close();
}

float Cargo::getWeight()
{
	return this->weight;
}

bool Cargo::getOverallDimensions()
{
	return this->overallDimensions;
}

int Cargo::getCar()
{
	return this->car;
}

int Cargo::setorderFulfillmentDriver()
{
	return this->orderFulfillmentDriver;
}

void Cargo::getDriversTrueOrFalse(bool status, vector<Worker> driver)
{
	if (!driver.empty())
	{
		for (int i = 0; i < driver.size(); i++) {
			if (driver[i].getWorkerFree() == status)
				cout << "#" << driver[i].getNumberDriver() << endl << driver[i];
		}
	}
	else
		cout << "Список пуст!" << endl;
	system("pause");
}

void Cargo::outCargo(vector<Worker>& driverTemp, vector<Car>& carTemp)
{
	cout << "Вес груза: " << weight << endl;
	if(overallDimensions)
		cout << "Габаритный груз" << endl;
	else
		cout << "Негабаритный груз" << endl;
	cout << "Машина выполняющая работу: " << endl << carTemp[orderFulfillmentDriver];
	cout << "Водитель выполняющая работу: " << endl << driverTemp[orderFulfillmentDriver];
	cout << "Направление: " << endl;
	cout << this->direction;
}

void Cargo::inCargo(vector<Worker>& drivers)
{
	int n;
	cout << "Вес: ";
	cin >> weight;

	cout << "Водитель выполняющая работу: " << endl;
	getDriversTrueOrFalse(true, drivers);
	do {
		cout << "Введите номер водителя: ";
		cin >> n;
	} while (n < drivers.size() && !drivers[n].getStatus());
	this->orderFulfillmentDriver = n;
	drivers[n].setWorkerFree(false);

	cout << "Груз габоритный?(1 - да / else - нет)" << endl;
	cin >> n;
	if (n == 1)
		this->overallDimensions = true;
	else
		this->overallDimensions = false;

	cout << "Направление: " << endl;
	cin >> direction;
}

ostream& operator<<(std::ostream& out, const Cargo& point)
{
	out << "Вес груза: " << point.weight << endl;
	if (point.overallDimensions)
		out << "Размер: габоритный груз" << endl;
	else
		out << "Размер: негаборитны" << endl;
	out << point.direction;
	return out;
}


