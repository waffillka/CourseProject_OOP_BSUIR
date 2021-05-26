#include "Company.h"

Company::Company()
{
	statusAutorisation = false;
	who = 0;
}

Company::~Company()
{
}

bool Company::getStatusAutorisation()
{
	return this->statusAutorisation;
}

void Company::setStatusAutorisation(bool temp)
{
	this->statusAutorisation = temp;
}

int Company::getWhoAmI()
{
	return this->who;
}

void Company::addClient(Client& temp)
{
	for (Client w : clients)
		if (w.getFirstname() == temp.getFirstname() && w.getLogin() == temp.getLogin() && temp.getSurname() == w.getSurname())
		{
			cout << "Даннный аккаунт уже существует!" << endl;
			return;
		}
	temp.setStatus(2);
	clients.push_back(temp);
}

void Company::addAdmin(Person& temp)
{
	for(Person w : admins)
		if (w.getFirstname() == temp.getFirstname() && w.getLogin() == temp.getLogin() && temp.getSurname() == w.getSurname())
		{
			cout << "Даннный аккаунт уже существует!" << endl;
			return;
		}
	temp.setStatus(1);
	admins.push_back(temp);
}

void Company::addCar(Car& temp)
{
	cars.push_back(temp);
}

void Company::addDriver(Worker& temp)
{
		drivers.push_back(temp);
}

void Company::addDriverAdmin(Worker& temp)
{
	drivers.push_back(temp);
}

bool Company::Autorisation(char status, string login, string password) // 1 - админ / 2 - клиент / 3 - водитель
{
	
	if (status == '1')//Admin
	{
		for (int i = 0; i < this->admins.size(); i++)
			if (this->admins[i].getLogin() == login && this->admins[i].getPassword() == password)
			{
				this->who = 1;
				return statusAutorisation = true;
			}
	}
	else if(status == '2')//Client
	{
		for (int i = 0; i < this->clients.size(); i++)
			if (this->clients[i].getLogin() == login && this->clients[i].getPassword() == password)
			{
				this->who = 2;
				this->clients[i].setAutorisation(true);
				return statusAutorisation = true;
			}
	}
	else if (status == '3')//Driver
	{
		for (int i = 0; i < drivers.size(); i++)
			if (drivers[i].getLogin() == login && drivers[i].getPassword() == password)
			{
				drivers[i].setAutorisation(true);
				this->who = 3;
				return statusAutorisation = true;
			}
	}

	return false;
}

bool Company::registration(char status) // 1 - админ / 2 - клиент / 3 - водитель
{	
	system("cls");
	if (status == '1')
	{	
		Person t;
		cin >> t;
		addAdmin(t);
		
	}
	else if (status == '2')
	{
		Client t;
		cin >> t;
		addClient(t);
	}
	else if (status == '3')
	{	
		cout << "1. Регистрация с маштной\n2. Регистрация без машины.\nВведите номер пункта: ";
		cin >> status;
		system("cls");
		if (status == '1') {
			cout << "\tВодитель" << endl;
			Worker driver;
			driver.setStatusDriver(true);
			driver.setStatus(3);
			driver.setNumberDriver(drivers.size());
			cin >> driver;
			addDriver(driver);
			cout << "\tМашина" << endl;
			Car car;
			cin >> car;
			addCar(car);
		}
		else
		{
			cout << "Водитель" << endl;
			Worker driver;
			cin >> driver;
			driver.setStatusDriver(true);
			driver.setStatus(3);
			driver.setNumberDriver(drivers.size());
			addDriver(driver);
		}
		
	}
	return false;
}

void Company::showAllClients()
{
	if (!clients.empty())
	{
		for (int i = 0; i < clients.size(); i++)
		{
			cout << "#" << i << endl << clients[i];
		}
	}
	else
		cout << "Список плиентов пуст!" << endl;
	system("pause");
}

void Company::showAllDrivers()
{
	if (!drivers.empty())
	{
		for (int i = 0; i < drivers.size(); i++)
			cout << "#" << i << endl << drivers[i] << endl;
	}
	else
		cout << "Список плиентов пуст!" << endl;
	system("pause");
}

void Company::showAllAdmins()
{
	if (!admins.empty())
	{
		for (int i = 0; i < admins.size(); i++)
			cout << "#" << i << endl << admins[i];
	}
	else
		cout << "Список плиентов пуст!" << endl;
	system("pause");
}

void Company::showALLCar()
{
	if (!cars.empty())
	{
		int i = 0;
		for (auto w : cars)
		{
			cout << "#" << i << endl << w << endl;
			i++;
		}
	}
	else
		cout << "Список плиентов пуст!" << endl;
	system("pause");
}

void Company::delDriver()
{
	int n;
	string surname, name, login;

	do {
		menuFindFIOLogin();
		cin >> n;
	} while (n < 1 || n > 2);

	switch (n)
	{
	case 1:
		system("cls");
		cout << "Имя: ";
		cin >> name;
		cout << "Фамилия: ";
		cin >> surname;
		delDriver(name, surname);
		break;
	case 2:
		system("cls");
		cout << "Логин: ";
		cin >> login;
		delDriver(login);
		break;
	}
	system("pause");
}

void Company::delDriver(string name, string surname)
{
	for (int i = 0; i < drivers.size(); i++)
		if (drivers[i].getFirstname() == name && drivers[i].getSurname() == surname)
		{
			cout << "Водитель " << drivers[i].getFirstname() << "" << drivers[i].getSurname() << "(" << drivers[i].getLogin() << ") удален!" << endl;
			drivers.erase(drivers.begin() + i);
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::delDriver(string login)
{
	for (int i = 0; i < drivers.size(); i++)
		if (drivers[i].getLogin() == login)
		{
			cout << "Водитель " << drivers[i].getFirstname() << "" << drivers[i].getSurname() << "(" << drivers[i].getLogin() << ") удален!" << endl;
			drivers.erase(drivers.begin() + i);
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::delClient()
{
	int n;
	string surname, name, login;

	do {
		menuFindFIOLogin();
		cin >> n;
	} while (n < 1 || n > 2);

	switch (n)
	{
	case 1:
		system("cls");
		cout << "Имя: ";
		cin >> name;
		cout << "Фамилия: ";
		cin >> surname;
		delClient(name, surname);
		break;
	case 2:
		system("cls");
		cout << "Логин: ";
		cin >> login;
		delClient(login);
		break;
	}
	system("pause");
}

void Company::delClient(string name, string surname)
{
	for (int i = 0; i < clients.size(); i++)
		if (clients[i].getFirstname() == name && clients[i].getSurname() == surname)
		{
			cout << "Клиент " << clients[i].getFirstname() << "" << clients[i].getSurname() << "(" << clients[i].getLogin() << ") удален!" << endl;
			clients.erase(clients.begin() + i);
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::delClient(string login)
{
	for (int i = 0; i < clients.size(); i++)
		if (clients[i].getLogin() == login)
		{
			cout << "Клиент " << clients[i].getFirstname() << "" << clients[i].getSurname() << "(" << clients[i].getLogin() << ") удален!" << endl;
			clients.erase(clients.begin() + i);
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::delAdmin()
{
	int n;
	string surname, name, login;

	do {
		menuFindFIOLogin();
		cin >> n;
	} while (n < 1 || n > 2);

	switch (n)
	{
	case 1:
		system("cls");
		cout << "Имя: ";
		cin >> name;
		cout << "Фамилия: ";
		cin >> surname;
		delAdmin(name, surname);
		break;
	case 2:
		system("cls");
		cout << "Логин: ";
		cin >> login;
		delAdmin(login);
		break;
	}
	system("pause");
}

void Company::delAdmin(string login)
{
	for (int i = 0; i < admins.size(); i++)
		if (admins[i].getLogin() == login)
		{
			cout << "Администратор " << admins[i].getFirstname() << "" << admins[i].getSurname() << "(" << admins[i].getLogin() << ") удален!" << endl;
			admins.erase(admins.begin() + i);
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::delAdmin(string name, string surname)
{
	for (int i = 0; i < admins.size(); i++)
		if (admins[i].getFirstname() == name && admins[i].getSurname() == surname)
		{
			cout << "Администратор " << admins[i].getFirstname() << "" << admins[i].getSurname() << "(" << admins[i].getLogin() << ") удален!" << endl;
			admins.erase(admins.begin() + i);
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::findDriverAndShowAllInf()
{
	int n;
	string surname, name, login;

	do {
		menuFindFIOLogin();
		cin >> n;
	} while (n < 1 || n > 2);

	switch (n)
	{
	case 1:
		system("cls");
		cout << "Имя: ";
		cin >> name;
		cout << "Фамилия: ";
		cin >> surname;
		findDriverAndShowAllInf(name, surname);
		break;
	case 2:
		system("cls");
		cout << "Логин: ";
		cin >> login;
		findDriverAndShowAllInf(login);
		break;
	}
}

void Company::findDriverAndShowAllInf(string name, string surname)//--------------------------------
{
	int i = 0;
	for (i = 0; i < drivers.size(); i++)
		if (drivers[i].getFirstname() == name && drivers[i].getSurname() == surname)
		{
			cout << drivers[i];
			cout << cars[i];
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
}

void Company::findDriverAndShowAllInf(string login)//--------------------------
{
	int i = 0;
	for (i = 0; i < drivers.size(); i++)
		if (drivers[i].getLogin() == login)
		{
			cout << drivers[i];
			cout << cars[i];
			system("pause");
			return;
		}
	cout << "Данного водителя нет или данные неверные!" << endl;
	
}

void Company::findAdminAndShowAllInf()
{
	int n;
	string surname, name, login;

	do {
		menuFindFIOLogin();
		cin >> n;
	} while (n < 1 || n > 2);

	switch (n)
	{
	case 1:
		system("cls");
		cout << "Имя: ";
		cin >> name;
		cout << "Фамилия: ";
		cin >> surname;
		findAdminAndShowAllInf(name, surname);
		break;
	case 2:
		system("cls");
		cout << "Логин: ";
		cin >> login;
		findAdminAndShowAllInf(login);
		break;
	}
}

void Company::findAdminAndShowAllInf(string name, string surname)
{
	int i = 0;
	for (i = 0; i < admins.size(); i++)
		if (admins[i].getFirstname() == name && admins[i].getSurname() == surname)
		{
			cout << admins[i];
			system("pause");
			return;
		}
	cout << "Данного администратора нет или данные неверные!" << endl;
}

void Company::findAdminAndShowAllInf(string login)
{
	int i = 0;
	for (i = 0; i < admins.size(); i++)
		if (admins[i].getLogin() == login)
		{
			cout << admins[i];
			system("pause");
			return;
		}
	cout << "Данного администратора нет или данные неверные!" << endl;
}

void Company::findClientrAndShowAllInf()
{
	int n;
	string surname, name, login;

	do {
		menuFindFIOLogin();
		cin >> n;
	} while (n < 1 || n > 2);

	switch (n)
	{
	case 1:
		system("cls");
		cout << "Имя: ";
		cin >> name;
		cout << "Фамилия: ";
		cin >> surname;
		findClientrAndShowAllInf(name, surname);
		break;
	case 2:
		system("cls");
		cout << "Логин: ";
		cin >> login;
		findClientrAndShowAllInf(login);
		break;
	}
}

void Company::findClientrAndShowAllInf(string name, string surname)
{
	int i = 0;
	for (i = 0; i < clients.size(); i++)
		if (clients[i].getFirstname() == name && clients[i].getSurname() == surname)
		{
			cout << clients[i];
			system("pause");
			return;
		}
	cout << "Данного клиента нет или данные неверные!" << endl;
}

void Company::findClientrAndShowAllInf(string login)
{
	int i = 0;
	for (i = 0; i < clients.size(); i++)
		if (clients[i].getLogin() == login)
		{
			cout << clients[i];

			system("pause");
			return;
		}
	cout << "Данного клиента нет или данные неверные!" << endl;
}

//void Company::showALLCargoClient(Client& temp)
//{
//	int i = 0;
//	for (Cargo w : temp.getShipments())
//	{
//		cout << "#" << i << endl << w.outCargo() << endl;
//		i++;
//	}
//}

void Company::sortClientsAge()
{
	sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getAge() > b.getAge();});
}

void Company::menuClient() {
	char n;
	bool flag = true;
	Cargo cargo;
	string temp;
	int m;
	for (int i = 0; i < clients.size(); i++)
	{
		if (clients[i].getAutorisation())
		{
			while (flag) {
				do {
					system("cls");
					menu::menuClient();
					cin >> n;
				} while (n < '1' || n > '7');

				switch (n) {
				case '1': clients[i].showAllCargo(cars, this->drivers);	//Посмотреть свои заказы.----------------------------------------------
					break;
				case '2':
					cargo.inCargo(drivers);
					clients[i].addCargo(cargo);	//"2. Сделать заказ."
					break;
				case '3': clients[i].delCargo(this->drivers);	//Удалить заказ
					break;
				case '4': getDriversTrueOrFalse(true, this->drivers);	// Посмотреть свободных водителей------------------------------------------
					break;
				case '5': clients[i].sortCargoWeight();
					break;
				case '6':
					
						do {
							menu::changePersonalData();
							cin >> n;
						} while (n < '1' || n > '4');
						switch (n)
						{
						case '1': //Имя
							cout << "Введите имя: "; 
							cin >> temp;
							clients[i].setFirstname(temp);
							break;
						case '2': //Фамилия
							cout << "Введите фамилию: ";
							cin >> temp;
							clients[i].setSurname(temp);
							break;
						case '3': //Возраст
							cout << "Введите возраст: ";
							cin >> m;
							clients[i].setAge(m);
							break;
						case '4': //Пароль
							cout << "Введите новый пароль:";
							temp = "";
							passwordEnterWithStars(temp);
							temp = encryptPassword(temp);
							break;
						}
					break;
				case '7': flag = false;
				}
			}
			clients[i].setAutorisation(false);
			setStatusAutorisation(false);//при выходе сделать функцую удаляющую флаг указывающий на конкретного человека
			return;
			
		}
	}
	cout << "Не работает статус авторизации" << endl;
}

void Company::menuDriver()
{
	char n;
	bool flag = true;
	for (int i = 0; i < drivers.size(); i++)
	{
		if (drivers[i].getAutorisation())
		{
			while (flag) {
				do {
					system("cls");
					menu::menuDriver();
					cin >> n;
				} while (n < '1' || n > '5');

				switch (n) {
				case '1': showCargoForDriver(i);
					system("pause");
					break;
				case '2': cout << cars[i];
					system("pause");
					break;
				case '3': //Отметить груз."
					break;
				case '4': 
					system("cls");
					cout << "\tDriver" << endl << drivers[i] << endl;
					system("pause");
					break;
				case '5': flag = false;
				}
			}
			drivers[i].setAutorisation(false);
			setStatusAutorisation(false);//при выходе сделать функцую удаляющую флаг указывающий на конкретного человека
			return;

		}
	}
	cout << "Не работает статус авторизации" << endl;
}

void Company::showCargoForDriver(int temp)
{
	for (auto w : clients)
		for (auto t : w.getShipments())
			if (t.getCar() == temp)
				t.outCargo(drivers, cars), cout << endl;
}

void Company::writeAllDriversInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::trunc | ios::binary);
	f.close();
	for (auto& driver : drivers)//------------чекнуть auto& drive
		driver.writeDriverInFile(file_name);
}

void Company::writeAllCarsInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::trunc | ios::binary);
	f.close();
	for (Car w : cars)
		w.writeCarInFile(file_name);
	
}

void Company::writeAllAdminsInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::trunc);
	f.close();
	for (auto admin : admins)
		admin.writeAdminInFile(file_name);
}

void Company::writeAllClientsInFile(char* file_client, char* file_cargo)
{
	ofstream f;
	f.open(file_client, ios::trunc);
	f.close();
	f.open(file_cargo, ios::trunc);
	f.close();
	for (int y = 0; y < clients.size(); y++)
	{
		clients[y].writeClientInFile(file_client);
		
		for (int i = 0; i < clients[y].getShipments().size(); i++)
		{
			clients[y].getShipments()[i].writeCargoInFile(file_cargo);
		}
	}
}

void Company::readAllCarsFromFile(char* file_name)
{
	fstream f;
	int wheelbase, number;
	string mark, model, machineNumber;
	bool status;

	f.open(file_name);
	if (!f) {
		cerr << "Невозможно открыть базовый файл\n";
		exit(-1);
	}
	f.seekg(0);
	while (!f.eof())
	{
		
		f >> wheelbase >> mark >> model >> machineNumber >> number >> status;
		if (mark != "")
		{
			cars.push_back(Car(wheelbase, mark, model, machineNumber, number, status));
		}
	}
	f.close();
}

void Company::readAllDriversFromFile(char* file_name)
{
	fstream f;
	string firstname, surname, password, login;
	int age, status, drivingExperience, namber, day, month, year;
	Data driverLicenseDate;
	bool statusDriver, autorisation, workerFree;
	
	f.open(file_name);
	if (!f) {
		cerr << "Невозможно открыть базовый файл\n";
		exit(-1);
	}
	f.seekg(0);
	while (!f.eof())
	{
		
		f >> firstname >> surname >> age >> autorisation >> status >> login >> password >> namber >> drivingExperience >> day >> month >> year >> workerFree;
		if (firstname != "")
		{
			drivers.push_back(Worker(firstname, surname, age, drivingExperience, day, month, year, password, status, login, autorisation, namber, workerFree));
		}
	}
	f.close();
}

void Company::readAllAdminsFromFile(char* file_name)
{
	fstream f;
	string firstname, surname, password, login;
	int age, status;
	bool autorisation;

	f.open(file_name);
	if (!f) {
		cerr << "Невозможно открыть базовый файл\n";
		exit(-1);
	}
	f.seekg(0);
	while (!f.eof())
	{
		f >> firstname >> surname >> age >> autorisation >> status >> login >> password;
		if(firstname != "")
			admins.push_back(Person(firstname, surname, age, password, login, autorisation, status));
	}
	f.close();
	
}

void Company::readALLClientsFromFile(char* file_client, char* file_cargo)
{
	fstream client, cargo;
	string firstname, surname, password, login, placeOfUnloadinCountry, placeOfUnloadinCity, placeOfUnloadinStreet, placeOfUnloadinHouse;
	string placeOfShipmentCountry, placeOfShipmentCity, placeOfShipmentStreet, placeOfShipmentHouse;
	int age, status, countCargo, orderFulfillmentDriver, car, dateOfUnloadingDay, dateOfUnloadingMonth, dateOfUnloadingYear, shippingDateDay, shippingDateMonth, shippingDateYear;
	bool autorisation, overallDimensions;
	float weight;


	client.open(file_client);
	cargo.open(file_cargo);
	if (!client) {
		cerr << "Невозможно открыть базовый файл\n";
		exit(-1);
	}
	if (!cargo) {
		cerr << "Невозможно открыть базовый файл\n";
		exit(-1);
	}
	client.seekg(0);
	cargo.seekg(0);
	int n = 0;
	while (!client.eof())
	{
		client >> firstname >> surname >> age >> autorisation >> status >> login >> password >> countCargo;
		
		if (firstname != "")
		{
			clients.push_back(Client(firstname, surname, age, password, login, autorisation, status));
			for (int i = 0; i < countCargo; i++)
			{
				cargo >> weight >> overallDimensions >> orderFulfillmentDriver >> car >> dateOfUnloadingDay >> dateOfUnloadingMonth >> dateOfUnloadingYear >> shippingDateDay >> shippingDateMonth >> shippingDateYear >> placeOfShipmentCountry >> placeOfShipmentCity >> placeOfShipmentStreet >> placeOfShipmentHouse >> placeOfUnloadinCountry >> placeOfUnloadinCity >> placeOfUnloadinStreet >> placeOfUnloadinHouse;
				clients[n].addCargo(Cargo(weight, overallDimensions, orderFulfillmentDriver, car, dateOfUnloadingDay, dateOfUnloadingMonth, dateOfUnloadingYear, shippingDateDay, shippingDateMonth, shippingDateYear,
					placeOfShipmentCountry, placeOfShipmentCity, placeOfShipmentStreet, placeOfShipmentHouse, placeOfUnloadinCountry, placeOfUnloadinCity, placeOfUnloadinStreet, placeOfUnloadinHouse));
				
			}
			n++;
		}
	}
	client.close();
	cargo.close();
}

int Company::getSizeVectorDrivers()
{
	return drivers.size();
}

void Company::getCarsTrueOrFalse(bool status, vector<Car> car)
{
	if (!car.empty())
	{
		for (int i = 0; i < car.size(); i++) {
			if (car[i].getStatus() == status)
				cout << "#" << car[i].getNumberCar() << endl << car[i];
		}
	}
	else
		cout << "Список машин пуст!" << endl;
	system("pause");

}

void Company::getDriversTrueOrFalse(bool status, vector<Worker> driver)
{
	if (!driver.empty())
	{
		for (int i = 0; i < driver.size(); i++) {
			if (driver[i].getWorkerFree() == status)
				cout << "#" << driver[i].getNumberDriver() << endl << driver[i] << endl;
		}
	}
	else
		cout << "Список пуст!" << endl;
	system("pause");
}







