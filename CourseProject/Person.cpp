#include "Person.h"

using namespace std;
void Person::setFirstname(string firstname)
{
	this->firstname = firstname;
}

void Person::setSurname(string surname)
{
	this->surname = surname;
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::setPassword(string password)
{
	this->password = password;
}

void Person::setStatus(int status)
{
	this->status = status;
}

void Person::setLogin(string login)
{
	this->login = login;
}

void Person::setAutorisation(bool autorisation)
{
	this->autorisation = autorisation;
}

bool Person::getAutorisation()
{
	return this->autorisation;
}

string Person::getLogin()
{
	return this->login;
}

string Person::getFirstname()
{
	return this->firstname;
}

string Person::getSurname()
{
	return this->surname;
}

int Person::getAge()
{
	return this->age;
}

string Person::getPassword()
{
	return this->password;
}

int Person::getStatus()
{
	return this->status;
}

string Person::getStatusString()
{
	if (this->status == 1)
		return "Admin";
	else if(this->status == 2)
		return "Client";
	else if(this->status == 3)
		return "Driver";
}

Person::Person()
{
	this->age = 0;
	this->firstname = "";
	this->surname = "";
	this->password = "";
	this->autorisation = false;
}

Person::Person(string firstname, string surname, int age, string password, string login, bool autorisation, int status)
{
	this->age = age;
	this->firstname = firstname;
	this->surname = surname;
	this->password = password;
	this->login = login;
	this->autorisation = autorisation;
	this->status = status;
}

Person::~Person()
{
}

void Person::writeAdminInFile(char* file_name)
{
	ofstream f;
	f.open(file_name, ios::app);
	if (!f) { cerr << "���������� ������� ������� ����\n"; exit(-1); }
	f.seekp(0, ios_base::end);
	f << endl << this->firstname << "\t" << this->surname << "\t" << this->age << "\t" << this->autorisation << "\t" << this->status << "\t" << this->login << "\t" << this->password;
	if (!f) { cerr << "������  � ���� ����������\n"; exit(-1); }
	f.close();
}

ostream& operator<<(std::ostream& out, const Person& point)
{
	cout << "���: ";
	out << point.firstname;
	cout << endl << "�������: ";
	out << point.surname;
	cout << endl << "�������: ";
	out << point.age;
	cout << endl << "�����: ";
	out << point.login << endl;
	return out;
	// TODO: �������� ����� �������� return
}

istream& operator>>(istream& in, Person& temp)
{
	cout << "���: ";
	in >> temp.firstname;
	cout << "�������: ";
	in >> temp.surname;
	cout << "�������: ";
	in >> temp.age;
	cout << "�����: ";
	in >> temp.login;
	cout << "Password: ";
	passwordEnterWithStars(temp.password);
	temp.password = encryptPassword(temp.password);

	return in;
}
