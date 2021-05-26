#pragma once

//#include<vector>
#include "Cargo.h"
#include"Person.h"
#include"Worker.h"
#include"Car.h"

class Client: public Person
{
	vector<Cargo> shipments;
public:
	Client();
	Client(string firstname, string surname, int age, string password, string login, bool autorisation, int status);
	Client(const Client& client);
	~Client();

	friend ostream& operator<< (std::ostream& out, const Client& point);
	friend istream& operator>> (istream& in, Client& temp);

	void writeClientInFile(char* file_name);
	
	vector<Cargo> getShipments();
	void addCargo(vector<Worker>& drivers);
	void addCargo(Cargo m);
	void delCargo(vector<Worker>& drivers);
	void showAllCargo(vector<Car> cars, vector<Worker> drivers);
	void sortCargoWeight();
	int coutAllCargos();
	//void 
};