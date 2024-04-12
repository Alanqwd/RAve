#include <iostream>
#include <string>
#include <limits>

void Start();

int main()
{
	setlocale(LC_ALL, "ru");
	Start();


	return 0;
}
void Start()
{
	std::cout << "\t\tДобро пожаловать в Магазин < RAVE > " << "\n" << "\n";

	std::string adminLogin = "admin";
	std::string adminPassword = "admin";
	std::string login, password;
	int choose;
	bool exit = false;
	do
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login);
		std::cout << "Введите пароль: ";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин или пароль\n";
			std::cout << "Попробовать еще раз?\n1 - Да\n - Выход из программы\n";
			std::cin >> choose;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (choose == 2)
			{
				exit = true;
			}
		}
		else 
		{
			exit = true;
			int chooseStorageType;
			do
			{
				std::cout << "Введите формат скалада: \n1 - готовый склад\n 2 - создать склад вручную ";
				std::cin >> chooseStorageType;
			} 
			while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (chooseStorageType == 1)
			{
				//созд склада и запуск магазина
			}
			else if (chooseStorageType == 2)
			{
				std::cout << "В РАЗРАБОТКЕ \n";
			}
			else
			{
				std::cerr << "Error chooseStorageType";
			}
		}

	} while (!exit);
	


}