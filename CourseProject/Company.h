#pragma once
#include<iostream>
#include<vector>
#include <fstream>
#include<algorithm>
#include<string>
#include<cctype>
#include "Client.h"
#include "Menu.h"

#include"Worker.h"
#include"Car.h"

using namespace std;
using namespace menu;

class Company {
	vector<Client> clients;
	vector<Person> admins;

	vector<Car> cars;
	vector<Worker> drivers;

	bool statusAutorisation;
	int who;

public:

	Company();
	~Company();
	bool getStatusAutorisation();
	void setStatusAutorisation(bool temp);
	int getWhoAmI();

	void addClient(Client& temp);
	void addAdmin(Person& temp);
	void addDriver(Worker& temp);
	void addDriverAdmin(Worker& temp);
	void addCar(Car&);
	//--addAmin
	bool Autorisation(char, string, string);
	bool registration(char);

	void showAllClients();
	void showAllDrivers();
	void showAllAdmins();
	void showALLCar();

	void delDriver();
	void delDriver(string, string);
	void delDriver(string);

	void delClient();
	void delClient(string, string);
	void delClient(string);

	void delAdmin();
	void delAdmin(string);
	void delAdmin(string, string);

	void findDriverAndShowAllInf();
	void findDriverAndShowAllInf(string, string);
	void findDriverAndShowAllInf(string);

	void findAdminAndShowAllInf();
	void findAdminAndShowAllInf(string, string);
	void findAdminAndShowAllInf(string);

	void findClientrAndShowAllInf();
	void findClientrAndShowAllInf(string, string);
	void findClientrAndShowAllInf(string);

	//void showALLCargoClient(Client& temp);
	void sortClientsAge();
	//void DellCargoClient();

	void menuClient();
	void menuDriver();

	void showCargoForDriver(int);
	void writeAllDriversInFile(char* file_name);
	void writeAllCarsInFile(char* file_name);
	void writeAllAdminsInFile(char* file_name);
	void writeAllClientsInFile(char*, char*);
	
	void readAllCarsFromFile(char*);
	void readAllDriversFromFile(char*);
	void readAllAdminsFromFile(char*);
	void readALLClientsFromFile(char*, char*);

	int getSizeVectorDrivers();

	static void getCarsTrueOrFalse(bool, vector<Car>);
	static void getDriversTrueOrFalse(bool, vector<Worker>);
};