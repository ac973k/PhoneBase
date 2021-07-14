#include <iostream>
#include "SQLite\sqlite3.h"
#include <string>

extern "C" __declspec(dllexport) void __stdcall Upd(void)
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int rc;

	rc = sqlite3_open("PhoneBase.db", &db);
	if (rc) {
		fprintf(stderr, "Невозможно открыть БД: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "БД Загружена\n");
	}

	std::string id, FirstName, Year, PNumber;

	std::cout << "Введите ID записи, которую хотите изменить: \n";
	std::cin >> id;

	std::cout << "Введите Фамилию: \n";
	std::cin >> FirstName;

	std::cout << "Введите Год: \n";
	std::cin >> Year;

	std::cout << "Введите Номер Телефона: \n";
	std::cin >> PNumber;

	std::string sqlstatement = "UPDATE PhoneBase SET FIRSTNAME = ('" + FirstName + "') WHERE ID = ('" + id + "');";
	sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	sqlstatement = "UPDATE PhoneBase SET YEAR = ('" + Year + "') WHERE ID = ('" + id + "');";
	sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	sqlstatement = "UPDATE PhoneBase SET NUMBER = ('" + PNumber + "') WHERE ID = ('" + id + "');";
	sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);


	sqlite3_close(db);

	std::cout << "Готово\n";

	std::cin.get();
	std::cin.get();

	system("cls");
}