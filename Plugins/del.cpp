#include <iostream>
#include "SQLite\sqlite3.h"
#include <string>

extern "C" __declspec(dllexport) void __stdcall Del(void)
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int rc;

	rc = sqlite3_open("PhoneBase.db", &db);
	if (rc) {
		fprintf(stderr, "���������� ������� ��: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "�� ���������\n");
	}


	std::cout << "������� id ������, ������� ������ �������: \n";

	std::string id;
	std::cin >> id;

	std::string sqlstatement = "DELETE FROM PhoneBase WHERE ID = ('" + id + "');";
	sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	std::cout << "������ �������\n";

	std::cin.get();
	std::cin.get();

	system("cls");
}