#include <iostream>
#include "callback.h"
#include "SQLite\sqlite3.h"

extern "C" __declspec(dllexport) void __stdcall Input(void)
{
	sqlite3 *db;		//��������� � ����� ����
	char *zErrMsg = 0;	//� ��� ��� ������
	int rc;
	char *sql;

	rc = sqlite3_open("PhoneBase.db", &db); //������� ����

	if (rc)
	{
		fprintf(stderr, "���������� ��������� ����: %s\n", sqlite3_errmsg(db));
	}
	else
	{
		fprintf(stderr, "���� ������\n");
	}

	/*���������� ������*/
	sql = "CREATE TABLE PhoneBase(" \
		"ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
		"FIRSTNAME TEXT NOT NULL," \
		"YEAR INT NOT NULL," \
		"NUMBER TEXT NOT NULL);";

	/*��������� ������*/
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL Error %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "���� ������ �������\n");
	}
	sqlite3_close(db);

	std::cin.get();
	std::cin.get();

	system("cls");
}