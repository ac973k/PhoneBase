#include <iostream>
#include "SQLite\sqlite3.h"
#include "callback.h"

extern "C" __declspec(dllexport) void __stdcall Print(void)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "Callback function called";

	/* �������� ���� */
	rc = sqlite3_open("PhoneBase.db", &db);
	if (rc) {
		fprintf(stderr, "���������� ������� ��: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "�� ���������\n");
	}

	/* �������� ������� */
	sql = "SELECT * FROM PhoneBase ORDER BY ID";

	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "������\n");
	}
	sqlite3_close(db);

	std::cin.get();
	std::cin.get();

	system("cls");
}