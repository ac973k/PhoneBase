// PhoneBase2.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		std::cin >> choice;			//�������� ����� ����
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
				break;						//�������� ������� ����
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
				std::cout << "������\n";
			}
			}
			MYPROC Menu = (MYPROC)GetProcAddress(hLib, "Menu");
			if (Menu)
			{
				Menu();
			}
			std::cin >> choice;
		}
		std::cout << "��������� ������.\n";
	}
	else
	{
		std::cout << "���� plugins.dll �� ������! \n";
		std::cout << "����������, �������������� ����������! \n";

		std::cin.get();
		std::cin.get();
	}
    return 0;
}

