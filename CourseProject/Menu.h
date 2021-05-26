#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

namespace menu {

	static string encryptPassword(const string password) 
	{
		string EnPassword = "";
		char pass;
		// считаем ключ для шифрования
		int key = password.length();
		if (key <= 12)
			key *= 3;
		else
			key /= 3;

		// шифрование
		for (size_t i = 0; i < password.length(); i++)
		{
			pass = password[i] - key;
			EnPassword.push_back(pass);
		}
		return EnPassword;
	}

	// расшифровка пароля
	static string decryptPassword(const string& EnPassword) {
		string Password;
		char pass;
		// считаем ключ для расшифровки
		int key = EnPassword.length();
		if (key <= 12)
			key *= 3;
		else
			key /= 3;

		// расшифровка пароля
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
			cout << "Ошибка! Попробуйте снова!";
		}
	}

	static void menuChooseToLogInOrRegistration() {
		cout << "\tАвторизация" << endl;
		cout << "1. Войти." << endl;
		cout << "2. Зарегистрироваться." << endl;
		cout << "3. Завершить программу" << endl;
		cout << "Выберите пункт: " << endl;
	}

	static void menuLogInAndRegistration(bool temp) { //------------------------
		if (temp)
			cout << "\tАвторизация" << endl;
		else
			cout << "\tРегистрация" << endl;

		cout << "1. Администрация" << endl;
		cout << "2. Клиент" << endl;
		cout << "3. Водитель" << endl;
		if (!temp)
			cout << "4. Назад" << endl;
		
		cout << "Выберите пункт: " << endl;
		
	}
	static void menuAdmin()
	{
		cout << "\tAdmin" << endl;
		cout << "1. Показать всех клиентов." << endl;
		cout << "2. Показать всех водителей." << endl;
		cout << "3. Показать всех администраторов." << endl;

		cout << "4. Добавить водителя." << endl;
		cout << "5. Добавить администратора." << endl;
		cout << "6. Добавить клиента." << endl;

		cout << "7. Удалить водителя." << endl;
		cout << "8. Удалить клиента." << endl;
		cout << "9. Удалить администрация." << endl;

		cout << "10. Поиск водителя" << endl;
		cout << "11. Поиск администратора." << endl;
		cout << "12. Отсортировать клиентов по возрасту" << endl;
		cout << "13. Добавить машину" << endl;
		cout << "14. Показать все машины." << endl;
		cout << "15. Выход." << endl;

		cout << "Выберите пункт: " << endl;
	}

	static void menuClient()
	{
		cout << "\tClient" << endl;
		cout << "1. Посмотреть свои заказы." << endl;
		cout << "2. Сделать заказ." << endl;
		cout << "3. Удалить заказ." << endl;
		cout << "4. Посмотреть свободных водителей." << endl;
		cout << "5. Сортировать заказы по весу." << endl;
		cout << "6. Изменения личных данных." << endl;
		cout << "6. Выход." << endl;

		cout << "Выберите пункт: " << endl;
	}

	static void menuDriver()
	{
		cout << "\tDriver" << endl;
		cout << "1. Посмотреть грузы." << endl;
		cout << "2. Посмотреть машину." << endl;
		cout << "3. Отметить груз." << endl;
		cout << "4. Просмотреть личные данные." << endl;
		cout << "5. Выход." << endl;

		cout << "Выберите пункт: " << endl;
	}

	static void menuFindFIOLogin()
	{
		system("cls");
		cout << "1. Поиск по Имени и Фамилии." << endl;
		cout << "2. Поиск по Логину." << endl;
		cout << "Выберите пункт: " << endl;
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
					cout << "Пароль слишком короткий! Попробуйте снова!" << endl;
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
		cout << "1. Имя." << endl;
		cout << "2. Фамилия." << endl;
		cout << "3. Возраст." << endl;
		cout << "4. Пароль." << endl;
		cout << "Введите пункт: ";
	}


}

