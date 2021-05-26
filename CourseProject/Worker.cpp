#include"Worker.h"

Worker::Worker()
{
	drivingExperience = 0;;
	driverLicenseDate.setDate(0, 0, 0);
	namber = 0;
	this->workerFree = true;
	statusDriverOnline = false;
}

Worker::Worker(string firstname, string surname, int age, int drivingExperience, Data data, string password, int status)
{
	this->setFirstname(firstname);
	this->setSurname(surname);
	this->setAge(age);
	this->drivingExperience = drivingExperience;
	this->driverLicenseDate = data;
	this->password = password;
}

Worker::Worker(string firstname, string surname, int age, int drivingExperience, int day, int month, int year, string password, int status, string login, bool autorisation, int namber, bool workerFree)
{
	this->firstname = firstname;
	this->surname = surname;
	this->age = age;
	this->autorisation = autorisation;
	this->password = password;
	this->login = login;
	this->workerFree = workerFree;
	this->drivingExperience = drivingExperience;
	this->driverLicenseDate.setDate(day, month, year);

	this->status = status;
	this->namber = namber;
}

Worker::~Worker()
{
}

void Worker::writeDriverInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::app);
	if (!f) { cerr << "Невозможно открыть базовый файл\n"; exit(-1); }
	f.seekp(0, ios_base::end);
	f << endl << this->firstname << "\t" << this->surname << "\t" << this->age << "\t" << this->autorisation << "\t" << this->status << "\t" << this->login << "\t" << this->password << "\t" << this->namber << "\t" << this->drivingExperience << "\t" << this->driverLicenseDate.getDay() << "\t " << this->driverLicenseDate.getMonth() << "\t" << this->driverLicenseDate.getYear() << "\t" << this->workerFree;
	if (!f) { cerr << "Запись  в файл невозможна\n"; exit(-1); }
	f.close();
}

void Worker::setWorkerFree(bool workerFree)
{
	this->workerFree = workerFree;
}

void Worker::setDrivingExperience(int drivingExperience)
{
	this->drivingExperience = drivingExperience;
}

void Worker::setNumberDriver(int namber)
{
	this->namber = namber;
}

void Worker::setStatusDriver(bool status)
{
	this->statusDriverOnline = status;
}

void Worker::setDriverLicenseDate(int day, int month, int year)
{
	this->driverLicenseDate.setDate(day, month, year);
}

bool Worker::getStatusDriver()
{
	return this->statusDriverOnline;
}

int Worker::getNumberDriver()
{
	return this->namber;
}

int Worker::getDrivingExperience()
{
	return this->drivingExperience;
}

Data Worker::getDriverLicenseDate()
{
	return this->driverLicenseDate;
}

bool Worker::getWorkerFree()
{
	return this->workerFree;
}

ostream& operator<<(std::ostream& out, const Worker& point)
{
	cout << "Имя: ";
	out << point.firstname;
	cout << "\nФамилия: ";
	out << point.surname;
	cout << "\nВозраст: ";
	out << point.age;
	cout << "\nСтаж вождения: ";
	out << point.drivingExperience;
	cout << "\nДата выдачи водительских прав: ";
	out << point.driverLicenseDate;
	cout << "\nLogin: ";
	out << point.login;
	cout << "\nСтатус: ";
	if (point.status == 1)
		cout << "Admin";
	else if (point.status == 2)
		cout << "Client";
	else if (point.status == 3)
		cout << "Driver";

	return out;
}

istream& operator>>(istream& in, Worker& temp)
{
	//int n;
	cout << "Имя: ";
	in >> temp.firstname;
	cout << "Фамилия: ";
	in >> temp.surname;
	cout << "Возраст: ";
	in >> temp.age;
	cout << "Опыт вождения: ";
	in >> temp.drivingExperience;
	cout << "Дата выдачи водительских прав: ";
	in >> temp.driverLicenseDate;
	cout << "Login :";
	in >> temp.login;
	cout << "Пароль: ";
	passwordEnterWithStars(temp.password);
	temp.password = encryptPassword(temp.password);
	return in;
}
