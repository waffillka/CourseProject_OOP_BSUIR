#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

namespace menu {

	static string encryptPassword(const string password) 
	{
		string EnPassword = "";
		char pass;
		// ������� ���� ��� ����������
		int key = password.length();
		if (key <= 12)
			key *= 3;
		else
			key /= 3;

		// ����������
		for (size_t i = 0; i < password.length(); i++)
		{
			pass = password[i] - key;
			EnPassword.push_back(pass);
		}
		return EnPassword;
	}

	// ����������� ������
	static string decryptPassword(const string& EnPassword) {
		string Password;
		char pass;
		// ������� ���� ��� �����������
		int key = EnPassword.length();
		if (key <= 12)
			key *= 3;
		else
			key /= 3;

		// ����������� ������
		for (size_t i = 0; i < EnPassword.length(); i++) {
			pass = EnPassword[i] + key;
			Password.push_back(pass);
		}
		return Password;
	}

	template<typename T>
	static void Check(T* inf)
	{
		while (!(cin >> *inf) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������! ���������� �����!";
		}
	}

	static void menuChooseToLogInOrRegistration() {
		cout << "\t�����������" << endl;
		cout << "1. �����." << endl;
		cout << "2. ������������������." << endl;
		cout << "3. ��������� ���������" << endl;
		cout << "�������� �����: " << endl;
	}

	static void menuLogInAndRegistration(bool temp) { //------------------------
		if (temp)
			cout << "\t�����������" << endl;
		else
			cout << "\t�����������" << endl;

		cout << "1. �������������" << endl;
		cout << "2. ������" << endl;
		cout << "3. ��������" << endl;
		if (!temp)
			cout << "4. �����" << endl;
		
		cout << "�������� �����: " << endl;
		
	}
	static void menuAdmin()
	{
		cout << "\tAdmin" << endl;
		cout << "1. �������� ���� ��������." << endl;
		cout << "2. �������� ���� ���������." << endl;
		cout << "3. �������� ���� ���������������." << endl;

		cout << "4. �������� ��������." << endl;
		cout << "5. �������� ��������������." << endl;
		cout << "6. �������� �������." << endl;

		cout << "7. ������� ��������." << endl;
		cout << "8. ������� �������." << endl;
		cout << "9. ������� �������������." << endl;

		cout << "10. ����� ��������" << endl;
		cout << "11. ����� ��������������." << endl;
		cout << "12. ������������� �������� �� ��������" << endl;
		cout << "13. �������� ������" << endl;
		cout << "14. �������� ��� ������." << endl;
		cout << "15. �����." << endl;

		cout << "�������� �����: " << endl;
	}

	static void menuClient()
	{
		cout << "\tClient" << endl;
		cout << "1. ���������� ���� ������." << endl;
		cout << "2. ������� �����." << endl;
		cout << "3. ������� �����." << endl;
		cout << "4. ���������� ��������� ���������." << endl;
		cout << "5. ����������� ������ �� ����." << endl;
		cout << "6. ��������� ������ ������." << endl;
		cout << "6. �����." << endl;

		cout << "�������� �����: " << endl;
	}

	static void menuDriver()
	{
		cout << "\tDriver" << endl;
		cout << "1. ���������� �����." << endl;
		cout << "2. ���������� ������." << endl;
		cout << "3. �������� ����." << endl;
		cout << "4. ����������� ������ ������." << endl;
		cout << "5. �����." << endl;

		cout << "�������� �����: " << endl;
	}

	static void menuFindFIOLogin()
	{
		system("cls");
		cout << "1. ����� �� ����� � �������." << endl;
		cout << "2. ����� �� ������." << endl;
		cout << "�������� �����: " << endl;
	}

	//static void passwordEnterWithStars(string& str) {
	//	char c;
	//	while ((c = _getwch()) != '\r') {
	//		str += char(c);
	//		_putwch('*');
	//	}
	//	cout << endl;
	//}

	static void passwordEnterWithStars(string& pass) {
		//string pass;
		int i = 0;
		char a;
		while (true)
		{
			a = _getwch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
			{
				pass.push_back(a);
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1)
			{
				cout << "\b \b";
				pass.pop_back();
				--i;
			}
			if (a == '\r')
			{
				cout << endl;
				if (pass.length() <= 8) {
					cout << "������ ������� ��������! ���������� �����!" << endl;
					pass = "";
				}
				else
					break;
			}
		}
		//return pass;
	}


	static void changePersonalData()
	{
		system("cls");
		cout << "1. ���." << endl;
		cout << "2. �������." << endl;
		cout << "3. �������." << endl;
		cout << "4. ������." << endl;
		cout << "������� �����: ";
	}


}

