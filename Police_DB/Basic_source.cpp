
#include <iostream>
#include <string>
#include <conio.h>
#include "Auxiliary.h"
#include <map>
#include <cmath>

#define POLICE

int main()
{
///////////////////////////////////////////	
	Font(20);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
//////////////////////////////////////////	
#ifdef POLICE
	std::map<std::string, std::string> my_map;
	std::map<std::string, std::string>::iterator it;

	// Базовое заполнение STL map
	my_map.insert(std::pair< std::string, std::string >("АА 11-11", "Неправильная парковка"));
	my_map.insert(std::pair< std::string, std::string >("ББ 22-22", "Превышение скорости"));
	my_map.insert(std::pair< std::string, std::string >("ВВ 33-33", "Неправильная высадка пасажиров"));
	my_map.insert(std::pair< std::string, std::string >("ДД 44-44", "Запрещенный обгон"));
	my_map.insert(std::pair< std::string, std::string >("ГГ 55-55", "Просроченый техталон"));
	my_map.insert(std::pair< std::string, std::string >("ЕЕ 66-66", "Нет еб...й аптечки, понимаешь!!!"));
	my_map.insert(std::pair< std::string, std::string >("ЖЖ 33-33", "Неправильная высадка пасажиров"));
	my_map.insert(std::pair< std::string, std::string >("ЗЗ 44-44", "Запрещенный обгон"));
	my_map.insert(std::pair< std::string, std::string >("ИИ 55-55", "Просроченый техталон"));
	
	
vvod_S:
	std::system("cls");

	std::cout << std::endl << "\t\tВыбирете действие, которое необходимо сделать:  \n\n";
	std::cout << "0 - Ввести правонарушение БД \n1 - Полная распечатка БД \n2 - Распечатка данных по заданному номеру \n3 - Распечатка данных по диапазону номеров  \n4 - Показать дерево";
	std::cout << "\nESC - выход\n\n";


	
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

		
		for (it = my_map.begin(); it != my_map.end(); it++) // тест на совпадение
		{			
			if (it._Ptr->_Myval.first == num)
			{
				it._Ptr->_Myval.second = "" ? it._Ptr->_Myval.second += (", " + violations) : it._Ptr->_Myval.second += violations;

			    std::cout << "Данные по номерному знаку " << num << " добавлены" << std::endl;
				system("pause");
				goto vvod_S;
			}			
		}
		my_map.insert(std::pair< std::string, std::string >(num, violations));		
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
		for (it = my_map.begin(); it != my_map.end(); it++)
		{
			std::cout << it._Ptr->_Myval.first << "\t" << it._Ptr->_Myval.second << std::endl;
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

		
		for (it = my_map.begin(); it != my_map.end(); it++) // проверка на совпадение
		{		
			if (it._Ptr->_Myval.first == num)
			{
				std::cout << it._Ptr->_Myval.first << "\t" << it._Ptr->_Myval.second << std::endl;		       	
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
		
		for (it = my_map.begin(); it != my_map.end(); it++) 
		{
			
			if ((it._Ptr->_Myval.first >= num_low) & (it._Ptr->_Myval.first <= num_height))
			{
				std::cout << it._Ptr->_Myval.first << "\t" << it._Ptr->_Myval.second << std::endl;
				W_line();
			}
		}

		W_line();
		system("pause");
		goto vvod_S;
	};
	case 4: // Показать дерево
	{
///////////////////////// NULL 
		system("cls");

		std::map<std::string, std::string>::iterator null_position = my_map.begin();

		for (unsigned int i = 0; i < my_map.size(); i++)
		{
			null_position++;
		}

		W_line();
		std::cout << null_position._Ptr << "\t - NULL"  << std::endl;
		W_line();
////////////////////// root node

		std::map<std::string, std::string>::iterator root_position = my_map.begin();
		for (it = my_map.begin(); it != my_map.end(); it++)

		{
			if (it._Ptr->_Parent == null_position._Ptr)
			{
				root_position = it;
			}
		}
		std::cout << (*root_position).first << "\t" << root_position._Ptr << "\t" << " - root" << std::endl;
		W_line();

///////////// зависимости элементов STL map
		std::cout << "Номер" << "\t\t" << "Address" << "\t\t" << "Parent" << "\t\t" << "Left" << "\t\t" << "Right" << std::endl;

		W_line();
		for (it = my_map.begin(); it != my_map.end(); it++)
		{
			std::cout << (*it).first << "\t" << it._Ptr << "\t" << it._Ptr->_Parent << "\t" << it._Ptr->_Left << "\t" << it._Ptr->_Right << std::endl;
		}
		W_line();		

////////////////////////////////// Узнать глубину и ширину дерева
		int dip_tree = 0;
		int weight_tree;

		it = root_position;
		for (unsigned int i = 0; i < my_map.size(); i++)
		{
			if (it._Ptr->_Right != null_position._Ptr)
			{
				it._Ptr = it._Ptr->_Right;
				dip_tree++;
			}
		}
		weight_tree = pow(2, dip_tree);

////////////////////////////////////////// Создание двумерного динамического массива
		std::string** Mas = new std::string *[dip_tree + 2];
		for (int i = 0; i < dip_tree + 2; i++)
			Mas[i] = new std::string[weight_tree];

//////////////////////////////// заполнение масива значениями

		int n = 0;
		int hor = 0;
		int ver = 0;

		Mas[0][0] = root_position._Ptr->_Myval.first;	// корневой узел 

		it = root_position;
	a:

		hor = 0;
		for (int i = 0; i < weight_tree; i++)
		{
			if (Mas[ver + 1][i] == "") break;
			hor++;
		}

		if (Mas[ver + 1][hor] == "" && it._Ptr->_Right != null_position._Ptr)
		{
			ver++;
			it._Ptr = it._Ptr->_Right;
			Mas[ver][hor] = it._Ptr->_Myval.first;
			goto a;
		}
		else
		{
		up:
			if (it._Ptr->_Parent == null_position._Ptr) goto end;
			ver--;
			it._Ptr = it._Ptr->_Parent;
			for (int i = 0; i < weight_tree; i++)
			{
				if (it._Ptr->_Left->_Myval.first == Mas[ver + 1][i]) goto up;
			}
			hor = 0;
			for (int i = 0; i < weight_tree; i++)
			{
				if (Mas[ver + 1][i] == "") break;
				hor++;
			}

			if (Mas[ver + 1][hor] == "" && it._Ptr->_Left != null_position._Ptr)
			{
				ver++;
				it._Ptr = it._Ptr->_Left;
				Mas[ver][hor] = it._Ptr->_Myval.first;
				goto a;
			}
			goto up;
		}

	end:
///////////////////////////////  Прорисовка дерева 
		{
			int w = 16;
			const int centr = 16;
			int l = 0;
			double koef;
			int rw;
			int otstup;

			koef = pow(2, l);
			otstup = centr / koef;
			rw = w;

			for (int z = 0; z < w; z++)std::cout << "   ";
			std::cout << "RED_BLACK_TREE" << std::endl << std::endl;

		iter:

			if (Mas[l][0] != "")
			{
				if (koef != 1)
				{
					otstup = 2 * centr / koef;
					rw = rw + otstup / 2;
				}

				w = rw;
				for (int j = 0; j < 10; j++)
				{
					for (int z = 0; z < w; z++)std::cout << "   ";

					if (Mas[l][j] == "")
					{
						l++;
						koef = pow(2, l);
						break;
					}
					else
					{
						std::cout << Mas[l][j];
						std::cout << "\r";
						w -= otstup;
					}
				}
				std::cout << std::endl << std::endl << std::endl;
				goto iter;
			}
			delete[] Mas;
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
	
#endif // POLICE
	   
	return 0;
}


//Functions defenitions

