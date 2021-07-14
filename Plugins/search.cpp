#include <iostream>
#include "SQLite\sqlite3.h"
#include "callback.h"
#include <string>

extern "C" __declspec(dllexport) void __stdcall Search(void)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string sql;
	const char* data = "Callback function called";
	std::string FirstName;

	std::cout << "������� �������: \n";
	std::cin >> FirstName;

	/* �������� ���� */
	rc = sqlite3_open("PhoneBase.db", &db);
	if (rc) {
		fprintf(stderr, "���������� ������� ��: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "�� ���������\n");
	}

	/* �������� ������� */
	sql = "SELECT ID, NUMBER FROM PhoneBase WHERE FIRSTNAME = ('" + FirstName + "');";

	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
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