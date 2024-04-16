#include <iostream>
#include <string>
#include <limits>

//���������� �������
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* CountArr = new int[size];
double* priceArr = new double[size];

template <typename Arr>
void FillArr(Arr staticArr, Arr dinArr, int size);
void ShowStorage();

//�������� �������

void Start();
void Shop();
void DeleteMainArr();
void CreateStorage();
int main()
{
	setlocale(LC_ALL, "ru");
	Start();
	CreateStorage();
	ShowStorage();
	DeleteMainArr();

	return 0;
}
void ShowStorage()
{
	std::cout << "ID\t�������� ������\t\t���-��\t����\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << " " << nameArr[i] << "" << CountArr[i] << "  " << "\t" << priceArr[i] << "\n";
	}
}
void Start()
{
	std::cout << "\t\t����� ���������� � ������� ��������������� ������� �������� < RAVE > " << "\n" << "\n";

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
				std::cout << "������� ������ ������: \n1 - ������� �����\n2 - ������� ����� �������: " << "\n";
				std::cin >> chooseStorageType;
			} 
			while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (chooseStorageType == 1)
			{
				
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

	}   while (!exit);
	


}

void Shop()
{
	while (true)
	{
		int choose;
		do
		{
			std::cout << "1 - �������� �����\n";
			std::cout << "2 - ������ �������\n";
			std::cout << "3 - �������� ����\n";
			std::cout << "4 - ������� �����\n";
			std::cout << "5 - ��������� �����\n";
			std::cout << "6 - ��������� ������\n";
			std::cout << "0 - ��������� �����\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 6);
		if (choose == 1)
		{
			CreateStorage();
			Shop();
		}
		else if (choose == 2)
		{

		}
		else if (choose == 3)
		{

		}
		else if (choose == 4)
		{

		}
		else if (choose == 5)
		{

		}
		else if (choose == 6)
		{

		}
		else if (choose == 0)
		{
			break;
		}
		else
		{
			std::cerr << "Error";
		}

	}
}

void DeleteMainArr()
{
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{"\tLunacy Loud\t\t" ,"\tLunacy Night\t\t","\tLunacy x Dark Project\t","\tLunacy DINI\t\t","\tLunacy x HyperX\t\t","\tLunacy x DIOR\t\t","\tLunacy x GUCCI\t\t","\tLunacy x Guess\t\t","\tLunacy Soni\t\t","\tLunacy RAVE\t\t"};
	int count[staticSize]{6,7,5,3,5,7,6,7,5,8};
	double price[staticSize]{ 18000.0, 29000.0, 12000.0, 23000.0, 18000.0, 34000.0, 28000.0, 49000.0, 34000.0, 45000.0};
	FillArr(id, idArr, staticSize);
	FillArr(name, nameArr, staticSize);
	FillArr(count, CountArr, staticSize);
	FillArr(price, priceArr, staticSize);
}

template<typename Arr>
void FillArr(Arr staticArr, Arr dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
