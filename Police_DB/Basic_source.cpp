
#include <iostream>
#include <set>
#include <string>
#include <conio.h>
#include "Auxiliary.h"



struct node { //узел
	
	std::string key;
	std::string data;	
		
	// Metods
	void print() { std::cout << this->key << "\t" << this->data << std::endl; }
	
	// Operators
	bool operator<(const node& other) const
	{
		if ((this->key) < other.key) 
		{return true;} else return false;

	}
	
	//Constructors
	node()
	{
		this->key ="";
		this->data = "";
		
	}
	node(std::string key, std::string data)
	{
		this->key = key;
		this->data = data;		
	}
	//Destructor
	~node()
	{

	}
};


std::ostream& operator<<(std::ostream& os,const node& n);

#define POLICE
//#define TEST
int main()
{
	
	Font(20);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");


#ifdef POLICE
	std::set<node> S;
	std::set<node>::iterator it;

	node a("ВН 22-22", "Неправильная парковка");
	node b("КА 33-33", "Превышение скорости");
		
	S.insert(a);	
	S.insert(b);	
	
vvod_S:
	std::system("cls");

	std::cout << std::endl << "\t\tВыбирете действие, которое необходимо сделать:  \n\n";
	std::cout << "0 - Ввести правонарушение БД \n1 - Полная распечатка БД \n2 - Распечатка данных по заданному номеру \n3 - Распечатка данных по диапазону номеров  \n4 - Показать дерево";
	std::cout << "\nESC - выход\n\n";


	//std::cout << _getch()-48;
	switch (_getch() - 48)
	{
	case 0://  Добавление или обновление элемента
	{
		std::string num;
		std::string violations;

		system("cls");
		W_line();
		std::cout << "Введите номер авто(прим. BI 32-11): ";
		std::getline(std::cin, num);
		W_line();
		std::cout << "Введите нарушение: ";
		std::getline(std::cin, violations);
		W_line();

		node buff;
		for (it = S.begin(); it != S.end(); it++) // тест на совпадение
		{
			buff = *it;
			if (buff.key == num)
			{
				S.erase(it);
				buff.data != "" ? buff.data += (", " + violations) : buff.data += violations;
				S.insert(buff);
			    std::cout << "Данные по номерному знаку " << num << " добавлены" << std::endl;
				system("pause");
				goto vvod_S;
			}			
		}
		node nw(num, violations);
		S.insert(nw);
		std::cout << "Создан новый узел " << num  << std::endl;
		system("pause");
		goto vvod_S;
	};
	case 1://  Полная распечатка
	{
		system("cls");
		W_line();
		std::cout << "Номер авто" << "\t|" << " Нарушения" << std::endl;
		W_line();
		for (it = S.begin(); it != S.end(); it++)
		{
			std::cout << *it << std::endl;
			W_line();
		}
		system("pause");
		goto vvod_S;
	};
	case 2://  Выборочный поиск
	{
		std::string num;
		
		system("cls");
		W_line();
		std::cout << "Введите номер авто(прим. BI 32-11): ";
		std::getline(std::cin, num);
		system("cls");
		W_line();
		std::cout << "Номер авто" << "\t|" << " Нарушения" << std::endl;
		W_line();

		node buff;
		for (it = S.begin(); it != S.end(); it++) // тест на совпадение
		{
			buff = *it;
			if (buff.key == num)
			{
				buff.print();
				std::cout << "OK";
			
			}
		}

		W_line();
	    system("pause");
	    goto vvod_S;
	};
	case 3: // 
	{

		std::string num_low, num_height;

		system("cls");
		W_line();
		std::cout << "Введите нижнюю границу поиска номеров авто(прим. BI 32-11): ";
		std::getline(std::cin, num_low);
		std::cout << "Введите верхнюю границу поиска номеров авто(прим. BI 32-11): ";
		std::getline(std::cin, num_height);
		system("cls");
		W_line();
		std::cout << "Номер авто" << "\t|" << " Нарушения" << std::endl;
		W_line();

		node buff;
		for (it = S.begin(); it != S.end(); it++) 
		{
			buff = *it;
			if ((buff.key >= num_low) & (buff.key <= num_height))
			{
				buff.print();
				W_line();
			}
		}

		W_line();
		system("pause");
		goto vvod_S;
	};
	case 4: // 
	{
		system("cls");
		std::cout << "В процессе разработки" << std::endl;
		std::cout << "PTR" << "\t\t" << "Left" << "\t\t" << "Right" << "\t\t" << "Parent" << std::endl;
		W_line();
		/*
		node buff;
		std::_Tree_node<struct node, void *> * a[5];
		it = S.begin();
		a[1] = it._Ptr;


		std::cout << "\t"<< a[1];
		if (it._Ptr->_Parent == S.begin()._Ptr->_Parent) 
		{
			buff = *it;
			std::cout << buff.key;
		}
*/
		for (it = S.begin(); it != S.end(); it++)
		{			
			std::cout << it._Ptr << "\t" << it._Ptr->_Left << "\t" << it._Ptr->_Right << "\t" << it._Ptr->_Parent << std::endl;
		}


		system("pause");
		goto vvod_S;
	};

	case -21:
	{
		break;
	};
	default:
	{
		std::cout << "Неверный ввод_\n";
		std::system("pause");
		std::system("cls");
		goto vvod_S;

	};
	
	}
	//End();
	//system("pause");
#endif // POLICE

#ifdef TEST
	W_line();
	std::set<int> S = {1,2,3};
	std::set<int>::iterator it, it2;
	
	//std::string root = "";


	//node a("BI 47-42", "Неправильная парковка");
	//node b("BI 43-55", "Превышение скорости");

	//if (!S.size()) root = a.key;
	//S.insert(24);
	//if (!S.size()) root = b.key;
	//
	for (it = S.begin(); it != S.end(); it++)
	{
		std::cout << it._Ptr << "\t" << *it << std::endl;
	}
	//std::string = it._Ptr;
	S.insert(4);
	W_line();
	std::cout << "PTR" << "\t\t" << "Left" << "\t\t" << "Right" << "\t\t" << "Parent" << std::endl;
	
	for (it = S.begin(); it != S.end(); it++)
	{		
		std::cout <<  std::endl;
	}
	
	for (it = S.begin(); it != S.end(); it++)
	{
		std::cout << it._Ptr << "\t" << it._Ptr->_Left << "\t" << it._Ptr->_Right << "\t"<< it._Ptr->_Parent << std::endl;
	}

	it = S.end();
	std::cout << it._Ptr;
	//std::cout << it._Ptr->_Isnil;
	
	//it = S.find(a);

#endif // TEST


	return 0;
}


//Functions defenitions



std::ostream& operator<<(std::ostream& os, const node& n)
{
	os << n.key << "\t|"<< n.data;
	return os;
}