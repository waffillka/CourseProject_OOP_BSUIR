#pragma once
#include"Person.h"
#include"Data.h"
#include"Car.h"

class Worker : public Person
{
	int drivingExperience;
	Data driverLicenseDate;
	int namber;
	bool statusDriverOnline;
	bool workerFree;// добавить в файл

public:
	Worker();
	Worker(string firstname, string surname, int age, int drivingExperience, Data data, string password, int status);
	Worker(string firstname, string surname, int age, int drivingExperience, int day, int month, int year, string password, int status, string login, bool autorisation, int namber, bool workerFree);
	~Worker();

	void writeDriverInFile(char* file_name);

	void setWorkerFree(bool);
	void setDrivingExperience(int);
	void setNumberDriver(int);
	void setStatusDriver(bool);
	void setDriverLicenseDate(int, int, int);

	bool getStatusDriver();
	int getNumberDriver();
	int getDrivingExperience();
	Data getDriverLicenseDate();
	bool getWorkerFree();

	friend ostream& operator<< (std::ostream& out, const Worker& point);
	friend istream& operator>> (istream& in, Worker& temp);
};