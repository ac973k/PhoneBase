#include <iostream>

extern "C" __declspec(dllexport) void __stdcall Menu(void)
{
	std::cout << "�������� ��������:\n"
		"1 ������� ����\n"
		"2 �������� ����\n"
		"3 �������� ������\n"						//���� ����
		"4 �������� ������\n"
		"5 ������� ������\n"
		"6 �����\n"
		"7 ����-��\n"
		"8 �����\n";
}