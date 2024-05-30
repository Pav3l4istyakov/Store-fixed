#include<iostream>
#include <cstdlib>
#include <limits>
#include <string>
int size = 10;
int resiptsize = 1;
double cash = 30000.00;
double Cashincome = 0, cardincome = 0, totacincome = 0;

int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//массивы для чека
std::string* nameReciptArr = new std::string[resiptsize];
int* countReciptArr = new int[resiptsize];
double* priceReciptArr = new double[resiptsize];

//template < typename ArrType>
//void FillArray(ArrType staticArr, ArrType dinArr, int size);
//основные функии
void start();
void DeleteMainArrays();
void DeleteReciptArrays();
void CreateStorage();
void ShowStorage();
void Shop();
void Seling();
void AddElementToRecipt(int& reciptsize, int id, int count);
//void PriceRecipt();
void ChangePrice();
void RemoveFromStorage();
void AddToStorage();
void ChangeStorage();
void DeleteElementByIndex();
void discount();
void SecondDiscount();
void CashStatus();
void FillArray();
void PrintRecept();
//{
//	delete[] idArr;
//	delete[] nameArr;
//	delete[] countArr;
//	delete[] priceArr;
//
//}


void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1, 2, 3, 4, 5, 6 };
	std::string name[staticSize]{ "\t1-золотая цепь, 2- серебрянное кольцо, 3- золотое кольцо, 4- золотой слиток, 5-серебрянный слиток, 6- подвеска" };
	int count[staticSize]{ 8, 5, 6, 7, 10, 3 };
	double price[staticSize]{ 1000, 2000, 3000, 40000, 5000, 6000 };
	/*FillArray(id, idArr, staticSize);
	FillArray(name, nameArr, staticSize);
	FillArray(price, priceArr, staticSize);*/


}

void ShowStorage()
{
	std::cout << "id\tназвание товара\t\t\t кол-во\t\t цена\n";
}
void CashStatus()
{
	totacincome = Cashincome + cardincome;
	std::cout << "Наличные в кассе" << cash << "\n выручка за смену" << "итоговая выручка за смену:" << totacincome;
}
template<typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr;
	}
}
void PrintRecept()
{
	std::cout << "Название\t\t\t Кол-во\t Цена\n";
	for (int  i = 0; i < resiptsize; i++)
	{
		std::cout << nameReciptArr[i] << "\t\t" << countReciptArr[i] << "\t" << priceReciptArr[i] << "\t\n";
	}
	std::cout << "\n";
}
void Shop()
{
	while (true)
	{
		int choose;
		do {
			std::cout << "1-показать склад\n";
			std::cout << "2-начать продажу\n";
			std::cout << "3-изменить цену\n";
			std::cout << "4-списать товар\n";
			std::cout << "5-пополнить склад\n";
			std::cout << "6-изменение склада\n";
			std::cout << "7-пополнить кассу";

			std::cout << "0-закончить смену\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 0);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Seling();
		}
		else if (choose == 3)
		{
			ChangePrice();
		}
		else if (choose == 4)
		{
			RemoveFromStorage();
		}
		else if (choose == 5)
		{
			AddToStorage();
		}
		else if (choose == 6)
		{
			CreateStorage();
		}
		else if (choose == 7)
		{
			CashStatus();
		}
		else if (choose == 0)
		{
			break;
		}
		else
		{
			std::cerr << "error!";
		}
	}
}
void Seling()
{
	int chooseId, chooseCount, confirm;
	bool isFirst = true;
	double totalSum = 0;
	while (true)
	{
		totalSum = 0;
		do
		{
			std::cout << "Введите id товара:";
			std::cin >> chooseId;
			if (chooseId<1 || chooseId>size)
			{
				std::cerr << "Данного товара нет\n";
				continue;
			}
			if (countArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\nВыбранный товар" << nameArr[chooseId - 1];
					std::cout << "Кол-во данного товара на складе" << countArr[chooseId - 1];
					std::cout << "Введите Кол-во товара";
					std::cin >> chooseCount;
					if (chooseCount<1 || chooseCount>countArr[chooseId - 1])
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
			std::cout << "Товар:" << nameArr[chooseId - 1] << "\t Кол-во:" << chooseCount;
			std::cout << "\n 1-подтвердить\n 2-отмена";
			std::cin >> confirm;
			if (confirm == 1)
			{
				if (isFirst)
				{
					nameReciptArr[resiptsize - 1] = nameArr[chooseId - 1];
					countReciptArr[resiptsize - 1] = chooseCount;
					priceReciptArr[resiptsize - 1] = chooseCount;
					countArr[chooseId - 1] = chooseCount;
					totalSum += priceArr[chooseId - 1] * chooseCount;
					isFirst = false;
				}
				else
				{
					AddElementToRecipt(resiptsize, chooseId, chooseCount);
					totalSum += priceArr[chooseId - 1] * chooseCount;
				}
			}
			else
			{
				continue;
			}
			std::cout << "Купить ещё один товар?\n";
			std::cout << "1-Да\n 2- Закончить покупки\n";
			std::cin >> confirm;
			if (confirm == 1)
			{
				continue;
			}
			break;
		} while (true);
		PrintRecept();
		int pay = 0;
		std::cout << "\n\n\n";
		do
		{
			std::cout << "1-Наличные\n2-оплата картой\n\n";
			std::cin >> pay;
		} while (pay < 1 || pay>2);
		if (pay == 1)
		{
			cash += totalSum;
			Cashincome += totalSum;
		}
		else if (pay == 2)
		{
			cardincome += totalSum;
		}
		break;
	}


}
void discount()
{
	int id, discount, kollichestvo = 0, price = 0;
	std::cout << "на каждую 3 покупку скидка 30%";
	std::cout << "введите id товара для покупки";
	std::cin >> id;
	if (kollichestvo < 3)
	{
		std::cout << "покупка без скидки";
	}
	else if (kollichestvo >= 3)
	{
		std::cout << "покупка будет со скидкой";
		discount = price * 30 / 100;
		std::cout << "скидка составдяет" << discount;
	}
}

void SecondDiscount()
{
	int id, discount, price = 0;
	std::cout << "для новых покупателей скидка на товар 20% ";
	std::cout << "введите id товара ";
	std::cin >> id;
	if (id == 1)
	{
		std::cout << "скидка 20%";
		discount = price * 20 / 100;
		std::cout << "скидка составляет" << discount;
		//continue;
	}
	else(id > 1);
	{
		std::cerr << "скидки не будет";
		//continue;
	}
}

void AddElementToRecipt(int& reciptsize, int id, int count)
{

	std::string* nameReciptArrTemp = new std::string[resiptsize];
	int* countReceiptArrTemp = new int[resiptsize];
	double* priceReceiptArrTemp = new double[resiptsize];
	for (int i = 0; i < resiptsize; i++)
	{
		nameReciptArrTemp[i] = nameReciptArr[i];
		countReceiptArrTemp[i] = countReciptArr[i];
		priceReceiptArrTemp[i] = priceReciptArr[i];
	}
	delete[]nameReciptArr;
	delete[]countReciptArr;
	delete[]priceReciptArr;
	resiptsize++;
	nameReciptArr = new std::string[resiptsize];
	countReciptArr = new int[resiptsize];
	priceReciptArr = new double[resiptsize];
	for (int i = 0; i < resiptsize - 1; i++)
	{
		nameReciptArr[i] = nameReciptArrTemp[i];
		countReciptArr[i] = countReceiptArrTemp[i];
		priceReciptArr[i] = priceReceiptArrTemp[i];
	}
	nameReciptArr[resiptsize - 1] = nameArr[id - 1];
	countReciptArr[resiptsize - 1] = count;
	priceReciptArr[resiptsize - 1] = priceArr[id - 1] * count;
	delete[]nameReciptArrTemp;
	delete[]countReceiptArrTemp;
	delete[]priceReceiptArrTemp;
}
void DeleteReciptArrays()
{
	int id = 0;
	int count = 0;
	nameReciptArr[resiptsize - 1] = nameArr[id - 1];
	countReciptArr[resiptsize - 1] = count;
	priceReciptArr[resiptsize - 1] = priceArr[id - 1] * count;
	countArr[id - 1] -= count;
}


void RemoveFromStorage()
{
	int id = 0;
	int count = 0;
	do {
		std::cout << "введите id товара:";
		std::cin >> count;
	} while (count < 0 || count > countArr[id - 1]);
	countArr[id - 1] -= countArr[id - 1];
	std::cout << "цена товара успешно изменена:";
}


void ChangePrice()
{
	int id;
	double newprice = 0;
	do {
		std::cout << "введите id для изменения цены";
		std::cin >> id;
	} while (newprice < 1 || newprice > 1000000);
	priceArr[id - 1] = newprice;
	std::cout << "цена товара успешно изменена!\n\n";
}

void AddToStorage()
{
	int id, count;
	do {
		std::cout << "введите id товара для пополнения";
		std::cin >> id;
	} while (id < 1 || id > idArr[size - 1]);

	std::cout << "\n\nвыбран товар:" << nameArr[id - 1] << "=" << countArr[id - 1] << "штук\n\n";
	do {
		std::cout << "\n введите кол-во товара:";
		std::cin >> count;
	} while (count < 0 || count > countArr[id - 1]);
	std::cout << "товар успешно пополнен\n\n";
}

void ChangeStorage()
{
	int choose = 0;
	do {
		std::cout << "1-добавить товар на склад\n";
		std::cout << "2-убрать товар со склада\n";
		std::cout << "3-выход\n";
	} while (choose < 0 || choose > 2);
	if (choose == 1)
	{
		int* idArr = new int[size];
		std::string* nameArr = new std::string[size];
		int* countArr = new int[size];
		double* priceArr = new double[size];
	}
	else if (choose == 2)
	{

	}
	else
	{
		std::cout << "выход";
	}
}


void DeleteElementByIndex()
{
	idArr = new int[size];
	nameArr = new std::string[size];
	countArr = new int[size];
	priceArr = new double[size];
	int index = 0;
	do {
		std::cout << "введите id товара для удаления";
		std::cin >> index;
	} while (index < 1 || index > size);
	for (int i = 0, j = 0; i < size, j < size, j++; i++)
	{
		if (i == index - 1)
		{
			i++;
			nameReciptArr[i] = idArr[j];
			nameReciptArr[i] = nameArr[j];
			priceReciptArr[i] = priceArr[j];


		}
		else
		{
			idArr[j] = idArr[i];
			nameArr[j] = nameArr[i];
			priceArr[j] = priceArr[j];
			countArr[j] = countArr[i];
		}
	}

	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;
}




void start()
{
	{
		std::cout << "****************************  Добро пожаловать в Бриллиант!********************";
		std::string adminLogin = "admin";
		std::string adminPassword = "admin";
		std::string login, password;
		int choose;
		bool exit = false;
		do
		{
			std::cout << "введите логин:";
			std::getline(std::cin, login);
			std::cout << "введите пароль:";
			std::getline(std::cin, password);
			if (login != adminLogin || password != adminPassword)
			{
				std::cerr << "Неверный логин или пароль\n";
				std::cout << "Попробовать ещё раз?\n1-да\n2-Выход из программы\n";
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
					std::cout << "Выберите формат склада\n 1-готовый склад\n 2- создать склад вручную\n";
					std::cin >> chooseStorageType;
				} while (chooseStorageType < 1 || chooseStorageType>2);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (chooseStorageType == 1)
				{
					CreateStorage();
					Shop();
				}
				else if (chooseStorageType == 2)
				{
					std::cout << "В разработке\n";
				}
				else
				{
					std::cerr << "Error chooseStorageType";
				}
			}
	} while (!exit);
	}
}

	






int main()
{
	setlocale(LC_ALL, "ru");
	start();
	/*DeleteMainArrays();
	delete[]nameReciptArr;
	delete[]countReciptArr;
	delete[]priceReciptArr;*/
	return 0;

}
