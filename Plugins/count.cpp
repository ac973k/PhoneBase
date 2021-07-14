#include <iostream>
#include "SQLite\sqlite3.h"
#include "callback.h"
#include <string>


extern "C" __declspec(dllexport) void __stdcall Count(void)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string sql;
	const char* data = "Callback function called";
	std::string Year;

	std::cout << "Введите Год: \n";
	std::cin >> Year;

	/* открытие базы */
	rc = sqlite3_open("PhoneBase.db", &db);
	if (rc) {
		fprintf(stderr, "Невозможно открыть БД: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "БД Загружена\n");
	}

	/* создание запроса */

	sql = "SELECT COUNT(ID) FROM PhoneBase WHERE YEAR >= ('" + Year + "');";

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Готово\n");
	}
	sqlite3_close(db);

	std::cin.get();
	std::cin.get();

	system("cls");
}