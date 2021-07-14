#include <iostream>
#include "SQLite\sqlite3.h"
#include <string>

extern "C" __declspec(dllexport) void __stdcall Add(void)
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

	std::string FirstName, Year, PNumber;

	std::cout << "������� �������: \n";
	std::cin >> FirstName;
	std::cout << "������� ���: \n";
	std::cin >> Year;
	std::cout << "������� ����� ��������: \n";
	std::cin >> PNumber;

	std::string sqlstatement = "INSERT INTO PhoneBase (FIRSTNAME, YEAR, NUMBER) VALUES('" + FirstName + "','" + Year + "','" + PNumber + "');";

	sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	std::cout << "������ \n";
	std::cin.get();
	std::cin.get();

	system("cls");
}