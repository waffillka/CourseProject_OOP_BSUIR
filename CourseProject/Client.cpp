#include "Client.h"

Client::Client()
{
	this->age = 0;
	this->autorisation = false;
	this->firstname = "";
	this->login = "";
	this->password = "";
	this->status = 2;
	this->surname = "";
}

Client::Client(string firstname, string surname, int age, string password, string login, bool autorisation, int status)
{
	this->age = age;
	this->firstname = firstname;
	this->surname = surname;
	this->password = password;
	this->login = login;
	this->autorisation = autorisation;
	this->status = status;
}

Client::Client(const Client& client)
{
	this->age = client.age;
	this->autorisation = client.autorisation;
	this->firstname = client.firstname;
	this->login = client.login;
	this->password = client.password;
	this->status = client.status;
	this->surname = client.surname;
}

Client::~Client()
{
}

void Client::writeClientInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::app);
	if (!f) { cerr << "Невозможно открыть базовый файл\n"; exit(-1); }
	f.seekp(0, ios_base::end);
	f << endl << this->firstname << "\t" << this->surname << "\t" << this->age << "\t" << this->autorisation << "\t" << this->status << "\t" << this->login << "\t" << this->password << "\t" << this->shipments.size();
	if (!f) { cerr << "Запись  в файл невозможна\n"; exit(-1); }
	f.close();
}

vector<Cargo> Client::getShipments()
{
	return this->shipments;
}

void Client::addCargo(Cargo temp)
{
	shipments.push_back(temp);
}

void Client::addCargo(vector<Worker>& drivers)
{
	Cargo temp;
	temp.inCargo(drivers);
	shipments.push_back(temp);
}

void Client::delCargo(vector<Worker>& drivers)
{
	int i;
	for (i = 0; i < shipments.size(); i++)
		cout << "#" << i << endl << shipments[i] << endl;
	do {
		cout << "Ведите номер: ";
		cin >> i;
	} while (i < 0 || i >= shipments.size());
	drivers[shipments[i].getCar()].setWorkerFree(true);
	shipments.erase(shipments.begin() + i);
}

void Client::showAllCargo(vector<Car> cars,vector<Worker> drivers)
{
	if (!shipments.empty())
	{
		for (int i = 0; i < shipments.size(); i++)
		{
			cout << "#" << i << endl;
			shipments[i].outCargo(drivers, cars);
		}
	}
	else
		cout << "Список плиентов пуст!" << endl;
	system("pause");
}

void Client::sortCargoWeight()
{
	sort(shipments.begin(), shipments.end(), [](Cargo a, Cargo b) { return a.getWeight() > b.getWeight();});
}

int Client::coutAllCargos()
{
	return this->shipments.size();
}

ostream& operator<<(std::ostream& out, const Client& point)
{
	cout << "Имя: "; out << point.firstname;
	cout << endl << "Фамилия: "; out << point.surname;
	cout << endl << "Возраст: "; out << point.age;
	cout << endl << "Логин: "; out << point.login;
	cout << endl << "Статус: ";
	if (point.status == 1)
		cout << "Admin" << endl;
	else if (point.status == 2)
		cout << "Client" << endl;
	else if (point.status == 3)
		cout << "Driver" << endl;
	return out;
}

istream& operator>>(istream& in, Client& temp)
{
	cout << "Имя: ";
	in >> temp.firstname;
	cout << "Фамилия: ";
	in >> temp.surname;
	cout << "Возраст: ";
	in >> temp.age;
	cout << "Логин: ";
	in >> temp.login;
	cout << "Password: ";
	passwordEnterWithStars(temp.password);
	temp.password = encryptPassword(temp.password);
	return in;
}
