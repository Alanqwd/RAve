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
	std::cout << "\t\t����� ���������� � ������� < RAVE > " << "\n" << "\n";

	std::string adminLogin = "admin";
	std::string adminPassword = "admin";
	std::string login, password;
	int choose;
	bool exit = false;
	do
	{
		std::cout << "������� �����: ";
		std::getline(std::cin, login);
		std::cout << "������� ������: ";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "�������� ����� ��� ������\n";
			std::cout << "����������� ��� ���?\n1 - ��\n - ����� �� ���������\n";
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
				std::cout << "������� ������ �������: \n1 - ������� �����\n 2 - ������� ����� ������� ";
				std::cin >> chooseStorageType;
			} 
			while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (chooseStorageType == 1)
			{
				//���� ������ � ������ ��������
			}
			else if (chooseStorageType == 2)
			{
				std::cout << "� ���������� \n";
			}
			else
			{
				std::cerr << "Error chooseStorageType";
			}
		}

	} while (!exit);
	


}