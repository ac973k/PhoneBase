// PhoneBase2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include "locale"

typedef void(__stdcall *MYPROC)(void);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	HMODULE hLib = LoadLibrary("plugins.dll");
	if (hLib)
	{

		setlocale(LC_ALL, "Russian");

		MYPROC Menu = (MYPROC)GetProcAddress(hLib, "Menu");
		if (Menu)
		{
			Menu();
		}

		int choice;
		std::cin >> choice;			//выбираем пункт меню
		while (choice != 8)
		{
			switch (choice)
			{
			case 1:
			{
				MYPROC Input = (MYPROC)GetProcAddress(hLib, "Input");
				if (Input)
				{
					Input();
				}
				break;
			}
			case 2:
			{
				MYPROC Print = (MYPROC)GetProcAddress(hLib, "Print");
				if (Print)
				{
					Print();
				}
				break;
			}
			case 3:
			{
				MYPROC Add = (MYPROC)GetProcAddress(hLib, "Add");
				if (Add)
				{
					Add();
				}
				break;						//Описание пунктов меню
			}
			case 4:
			{
				MYPROC Upd = (MYPROC)GetProcAddress(hLib, "Upd");
				if (Upd)
				{
					Upd();
				}
				break;
			}
			case 5:
			{
				MYPROC Del = (MYPROC)GetProcAddress(hLib, "Del");
				if (Del)
				{
					Del();
				}
				break;
			}

			case 6:
			{
				MYPROC Search = (MYPROC)GetProcAddress(hLib, "Search");
				if (Search)
				{
					Search();
				}
				break;
			}
			case 7:
			{
				MYPROC Count = (MYPROC)GetProcAddress(hLib, "Count");
				if (Count)
				{
					Count();
				}
				break;
			}
			case 8:
			{
				break;
			}
			default:
			{
				std::cout << "Ошибка\n";
			}
			}
			MYPROC Menu = (MYPROC)GetProcAddress(hLib, "Menu");
			if (Menu)
			{
				Menu();
			}
			std::cin >> choice;
		}
		std::cout << "Завершаем работу.\n";
	}
	else
	{
		std::cout << "Файл plugins.dll не найден! \n";
		std::cout << "Пожалуйста, переустановите приложение! \n";

		std::cin.get();
		std::cin.get();
	}
    return 0;
}

