#pragma once
#include<iostream>
#include <fstream>
#include<algorithm>
#include<string>
#include<cctype>
#include <map>
#include <string>
#include "Menu.h"

using namespace std;
using namespace menu;

class Person
{
protected:
	string firstname;
	string surname;
	int age;
	string password;
	int status;
	string login;
	bool autorisation;

public:

	void setFirstname(string);
	void setSurname(string);
	void setAge(int);
	void setPassword(string);
	void setStatus(int);
	void setLogin(string);
	void setAutorisation(bool);

	bool getAutorisation();
	string getLogin();
	string getFirstname();
	string getSurname();
	int getAge();
	string getPassword();
	int getStatus();
	string getStatusString();


	Person();
	Person(string firstname, string surname, int age, string password, string login, bool autorisation, int status);
	~Person();

	friend ostream& operator<< (std::ostream& out, const Person& point );
	friend istream& operator>> (istream& in, Person& temp);

	void writeAdminInFile(char* file_name);
};