#include <iostream>
#include "callback.h"
#include "SQLite\sqlite3.h"

extern "C" __declspec(dllexport) void __stdcall Input(void)
{
	sqlite3 *db;		//связываем с базой файл
	char *zErrMsg = 0;	//а тут для ошибок
	int rc;
	char *sql;

	rc = sqlite3_open("PhoneBase.db", &db); //создаем файл

	if (rc)
	{
		fprintf(stderr, "Невозможно загрузить базу: %s\n", sqlite3_errmsg(db));
	}
	else
	{
		fprintf(stderr, "файл создан\n");
	}

	/*составляем запрос*/
	sql = "CREATE TABLE PhoneBase(" \
		"ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
		"FIRSTNAME TEXT NOT NULL," \
		"YEAR INT NOT NULL," \
		"NUMBER TEXT NOT NULL);";

	/*Выполняем запрос*/
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL Error %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "База данных создана\n");
	}
	sqlite3_close(db);

	std::cin.get();
	std::cin.get();

	system("cls");
}