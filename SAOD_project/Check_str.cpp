#include "Check_str.h"


std::string Check_str::input_driver_license_number()
{
	std::regex regular("\\d{2}\\s[�|�|�|�|�|�|�|�|�|�|�|�]{2}\\s[0-9]{6}");
	do {
		std::cout << "����� ������������� �������������: ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_state_registration_number()
{
	std::regex regular("[�|�|�|�|�|�|�|�|�|�|�|�]{1}\\d{3}[�|�|�|�|�|�|�|�|�|�|�|�]{2}-\\d{2}");
	do {
		std::cout << "��������������� ��������������� �����: ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_date(std::string line)
{
	std::regex regular("[0-9]{4}-(0[1-9]|[1][0-2])-(0[1-9]|[1-2][0-9]|3[0-1])");
	do {
		std::cout << line;
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_name()
{
	std::regex regular("[a-zA-Z�-��-�]{1,20}\\s[a-zA-Z�-��-�]{1,20}\\s[a-zA-Z�-��-�]{1,20}");
	do {
		std::cout << "���:(����� ������, �� ����� 20 ��������) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_passport()
{
	std::regex regular("[0-9]{2}\\s[0-9]{2}\\s[0-9]{6}");
	do {
		std::cout << "���������� ������:(�� �� ������, ��� �-�����) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_adress()
{
	do {
		std::cout << "�����:(1-60 ��������) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while (str.size() > 60 || str.size() < 1);
	return str;
}

std::string Check_str::input_brand()
{
	do {
		std::cout << "����� ����������:(1-60 ��������) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while (str.size() > 60 || str.size() < 1);
	return str;
}

std::string Check_str::input_color()
{
	do {
		std::cout << "���� ����������:(1-60 ��������) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while (str.size() > 60 || str.size() < 1);
	return str;
}

int Check_str::input_year_of_release()
{
	std::regex regular("[1-9][0-9]{3}");
	do {
		std::cout << "��� ������� ����������:(4 �����) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return stoi(str);
}
