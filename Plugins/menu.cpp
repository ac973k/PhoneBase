#include <iostream>

extern "C" __declspec(dllexport) void __stdcall Menu(void)
{
	std::cout << "Выберите действие:\n"
		"1 Создать базу\n"
		"2 Просмотр базы\n"
		"3 Добавить запись\n"						//Наше меню
		"4 Изменить запись\n"
		"5 Удалить запись\n"
		"6 Поиск\n"
		"7 Колл-во\n"
		"8 Выход\n";
}