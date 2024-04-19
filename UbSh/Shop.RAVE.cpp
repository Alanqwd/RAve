#include <iostream>
#include <string>
#include <limits>

//Глобальные массивы
int size = 10;
int receiptSize = 1;
int* idArr = new int[size];

std::string* nameArr = new std::string[size];

int* CountArr = new int[size];

double* priceArr = new double[size];

template <typename Arr>
void FillArr(Arr staticArr, Arr dinArr, int size);

void ShowStorage();

//Массивы для чека


std::string* nameReceiptArr = new std::string[receiptSize];

int* CountReceiptArr = new int[receiptSize];

double* priceReceiptArr = new double[receiptSize];


//основные функции

void Start();
void Selling();

void AddElementToReceipt( int id, int count);
void Shop();


void DeleteMainArr();

void CreateStorage();

void PrintReceipt();
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
	std::cout << "ID\tНазвание товара\t\tКол-во\tЦена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << " " << nameArr[i] << "" << CountArr[i] << "  " << "\t" << priceArr[i] << "\n";
	}
}

void Start()
{
	std::cout << "\t\tДобро пожаловать в Магазин профессионалных игровых гарнитур < RAVE > " << "\n" << "\n";

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
				std::cout << "Введите формат склада: \n1 - готовый склад\n2 - создать склад вручную: " << "\n";
				std::cin >> chooseStorageType;
			} 
			while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (chooseStorageType == 1)
			{
				CreateStorage();
				Shop();
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

	}   while (!exit);
	


}   
void AddElementToReceipt( int id, int count)
{
	std::string* nameReceiptArrTemp = new std::string[receiptSize];

	int* CountReceiptArrTemp = new int[receiptSize];

	double* priceReceiptArrTemp = new double[receiptSize];
	for (int i = 0; i < receiptSize; i++)
	{
		nameReceiptArrTemp[i] = nameReceiptArr[i];
		CountReceiptArrTemp[i] = CountReceiptArr[i];
		priceReceiptArrTemp[i] = priceReceiptArr[i];

	}
	delete[]nameReceiptArr;
	delete[]CountReceiptArr;
	delete[]priceReceiptArr;
	receiptSize++;

	nameReceiptArr = new std::string[receiptSize];
	CountReceiptArr = new int[receiptSize];
	priceReceiptArr = new double[receiptSize];
	for (int i = 0; i < receiptSize - 1; i++)
	{
		nameReceiptArr[i] = nameReceiptArrTemp[i];
		CountReceiptArr[i] = CountReceiptArrTemp[i];
		priceReceiptArr[i] = priceReceiptArrTemp[i];

	}


	nameReceiptArr[receiptSize - 1] = nameArr[id - 1];
	CountReceiptArr[receiptSize - 1] =  count;
	priceReceiptArr[receiptSize - 1] = priceArr[id - 1] * count;
	CountArr[id - 1] -= count;

}
void Shop()
{
	while (true)
	{
		int choose;
		do
		{
			std::cout << "1 - Показать склад\n";
			std::cout << "2 - Начать продажу\n";
			std::cout << "3 - Изменить цену\n";
			std::cout << "4 - Списать товар\n";
			std::cout << "5 - Пополнить товар\n";
			std::cout << "6 - Изменение склада\n";
			std::cout << "0 - Закончить смену\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 6);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Selling();
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

void PrintReceipt()
{
	std::cout << "Название\t\t\tКол-во\tЦена\n";
	for (int i = 0; i < receiptSize; i++)
	{
		std::cout << nameReceiptArr[i] << "\t\t" << CountReceiptArr[i] << "\t" << priceReceiptArr[i] << "\n";
	}
	std::cout << "\n";
}

void Selling()
{
	bool isFirst = true;
	int chooseId, chooseCount;
	char confirm;
	while (true)
	{
		do
		{
			std::cout << "Введите id товара: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "Данного товара нет\n";
				continue;
			}
			if (CountArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\nВыбранный товар: " << nameArr[chooseId - 1] << "\n";
					std::cout << "Кол-во данного товара складе: " << CountArr[chooseId - 1];
					std::cout << "Введите кол-во товара: ";
					std::cin >> chooseCount;
					if (chooseCount < 1 || chooseCount > CountArr[chooseId - 1])
					{
						std::cerr << "Error\n";
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				std::cerr << "Товара на складе нет\n";
				continue;
			}
			std::cout << "\n  Товар: " << nameArr[chooseId - 1] << "\t Кол-во: " << chooseCount;
			std::cout << "\n 1 - Потвердить\n 2 - Отмена: ";
			std::cin >> confirm;
			if (confirm == 1)
			{
				if (isFirst)
				{
					nameReceiptArr[receiptSize - 1] = nameArr[chooseId - 1];
					CountReceiptArr[receiptSize - 1] = chooseCount;
					priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
					CountArr[chooseId - 1] -= chooseCount;
					isFirst = false;
				}
				else
				{
					AddElementToReceipt(chooseId, chooseCount);
				}

			}
			
			else
			{
			continue;
		    }
			std::cout << "Купить еще1 товар?: \n";
			std::cout << "1 - Да\n 2 - Закончить покупки\n";
			std::cin >> confirm;
			if (confirm == 1)
			{
			continue;
			}
			break;
} 
while (true);
		
		
	 }

	
	
}


template<typename Arr>

void FillArr(Arr staticArr, Arr dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
