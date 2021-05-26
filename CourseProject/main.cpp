#include <iostream>
#include<Windows.h>
#include "Company.h"
///�������� ������� ������� �


void LogIn(Company& company, char n);

void menuAdmin(Company& company);

const char driverFile[] = "Driver.txt";
const char AdminFile[] = "Admin.txt";
const char CargoFile[] = "Cargo.txt";
const char ClientFile[] = "Client.txt";

using namespace std;

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file;
	Company company;
	char n;
	bool flag = true;
	
	char driverFile[] = "Driver.txt";
	char AdminFile[] = "Admin.txt";
	char CargoFile[] = "Cargo.txt";
	char ClientFile[] = "Client.txt";
	char CarFile[] = "Car.txt";

	company.readAllCarsFromFile(CarFile);
	company.readAllAdminsFromFile(AdminFile);
	company.readAllDriversFromFile(driverFile);
	company.readALLClientsFromFile(ClientFile, CargoFile);
	while (flag)
	{
		
		do {
			system("cls");
			menuChooseToLogInOrRegistration();
			cin >> n;
		} while (n < '1' || n > '4');
		
		switch (n)
		{
		case '1':
			do {
				system("cls");
				menuLogInAndRegistration(true);
				cin >> n;
			} while (n < '1' || n > '3');

			system("cls");
			LogIn(company, n);
			Sleep(2000);
			//system("pause");
			system("cls");

			if (company.getStatusAutorisation()) {
				if (company.getWhoAmI() == 1) // 1 - ����� / 2 - ������ / 3 - ��������
					menuAdmin(company);
				else if (company.getWhoAmI() == 2)
					company.menuClient();
				else if (company.getWhoAmI() == 3)
					company.menuDriver();
			}
			break;
		case '2':
			do {
				system("cls");
				menuLogInAndRegistration(false);//------------------------
				cin >> n;
			} while (n < '1' || n > '5');
			
			if(n < '4')
				company.registration(n);
			break;
		case '3': 
			flag = false;
		}
	}
	company.writeAllCarsInFile(CarFile);
	company.writeAllAdminsInFile(AdminFile);
	company.writeAllDriversInFile(driverFile);
	company.writeAllClientsInFile(ClientFile, CargoFile);
	system("pause");
	return 0;
}

void LogIn(Company& company, char n) {
	string log, password;
	cout << "\t�����������" << endl;
	cout << "�����: ";
	cin >> log;
	cout << "������: ";
	passwordEnterWithStars(password);
	if (company.Autorisation(n, log, encryptPassword(password)))
		cout << "����������� ������ �������!" << endl;
	else
		cout << "�������� ����� ��� ������!" << endl;
}

void menuAdmin(Company& company) {
	Client clientTemp;
	Person person;
	Worker driver;
	Car car;
	int n;
	bool flag = true;

	while (flag) {
		do {
			system("cls");
			menuAdmin();
			cin >> n;
		} while (n < 1 || n > 15);

		switch (n) {
		case 1: company.showAllClients();//�������� ���� ��������.
			break;
		case 2: company.showAllDrivers();//�������� ���� ���������.
			break;
		case 3: company.showAllAdmins();//�������� ���� ���������������
			break;
		case 4: 
			cin >> driver;
			driver.setStatusDriver(true);
			driver.setStatus(3);
			driver.setNumberDriver(company.getSizeVectorDrivers());
			company.addDriverAdmin(driver); //�������� ��������
			break;
		case 5: 
			cin >> person;
			company.addAdmin(person); //�������� ��������������
			break;
		case 6: 
			cin >> clientTemp;
			company.addClient(clientTemp); //�������� �������
			break;
		case 7: company.delDriver(); //������� ��������
			break;
		case 8: company.delClient(); //y������ �������
			break;
		case 9: company.delAdmin(); //������� �������������
			break;
		case 10: //����� ��������
			company.findDriverAndShowAllInf();
			break;
		case 11: //����� ��������������
			company.findAdminAndShowAllInf();
			break;
		case 12: //������������� �������� �� ��������
			company.sortClientsAge();
			break;
		case 13: cin >> car;
			company.addCar(car);
			break;
		case 14: company.showALLCar();
			break;
		case 15: flag = false;
			company.setStatusAutorisation(false);
		}
	}

}