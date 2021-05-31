#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "Tree.h"
#include "HashTable.h"

//using namespace std;

int main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251);//�����
	setlocale(LC_ALL, "RUS");
	Tree tree;
	List list;
	HashTable table;
	Car car;
	Car_rental_status car_rental_status;
	Check_str string;
	Client client;
	std::string str;
	std::string state_registration_number;
	//car = Car( "�111��-11", "�������", "������", 1998, false );  ###�������� ������###
	//table.add(car.state_registration_number, car);

	//car = Car("�111��-11", "�������", "�����", 1991, false);
	//table.add(car.state_registration_number, car);

	//car = Car("�222��-22", "��������", "������", 1999, true);
	//table.add(car.state_registration_number, car);

	//car = Car("�333��-33", "����", "��������", 2000, false);
	//table.add(car.state_registration_number, car);

	///*car = Car("�444��-44", "����", "��������", 2000, true);
	//table.add(car.state_registration_number, car);*/


	//client = Client("10 �� 123456", "������ ��������� ������������", "40 17 831439", "���");
	//tree.put(client);

	//client = Client("20 �� 123456", "������� ����� ���������", "77 66 000000", "������");
	//tree.put(client);

	//client = Client("30 �� 123456", "�������� ������ �������", "55 44 111111", "�����");
	//tree.put(client);

	//client = Client("40 �� 123456", "���������� ������ �������", "11 44 111111", "�����");
	//tree.put(client);

	//client = Client("50 �� 123456", "�������� ������ �������", "55 44 123456", "�����");
	//tree.put(client);

	//car_rental_status = { "10 �� 123456" ,"�111��-11", "2020-05-05", "" };
	//list.push_back(car_rental_status);

	//car_rental_status = { "20 �� 123456" ,"�111��-11", "2000-04-03", "" };
	//list.push_back(car_rental_status);

	//car_rental_status = { "40 �� 123456" ,"�333��-33", "2021-05-05", "" };
	//list.push_back(car_rental_status);
	int n = -1;
	// ���� ��������������
	while (n != 0)
	{
		//system("cls");
		std::cout << std::endl <<
			" 1 - ����������� ������ �������" << std::endl <<
			" 2 - ������ � ������������ �������" << std::endl <<
			" 3 - �������� ���� ������������������ ��������" << std::endl <<
			" 4 - ������� ������ � ��������" << std::endl <<
			" 5 - ����� ������� �� ������ ������������� ��������������" << std::endl <<
			" 6 - ����� ������� �� ���������� ��� ��� ������" << std::endl <<
			" 7 - ���������� ������ ����������" << std::endl <<
			" 8 - �������� �������� �� ����������" << std::endl <<
			" 9 - �������� ���� ��������� �����������" << std::endl <<
			"10 - ������� ������ �� �����������" << std::endl <<
			"11 - ����� ���������� �� ����������������� ���������������� ������" << std::endl <<
			"12 - ����� ���������� �� �������� ����� ����������" << std::endl <<
			"13 - ����������� �������� ���������� � ������" << std::endl << //car - ������� false
			"14 - ����������� �������� ���������� �� �������" << std::endl <<//car - ������� true
			"15 - ����������� ������ ������� ���������� �� ������" << std::endl <<
			"16 - ����������� �������� ���������� �� ��������" << std::endl <<
			"17 - ������ � ������ �� ������ ��� �������� ����������� �� ��������" << std::endl <<
			"0 - �����\n�������� ��������: ";
		std::cin >> n; std::cout << std::endl << std::endl << std::endl;

		while (std::cin.fail() || std::cin.get() != '\n' || (n < 0) || (n > 17))
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
			std::cout << "������ �����, �������� ��������: ";
			std::cin >> n;
		}
		switch (n)
		{
		case 1:
			client = client.input();
			if (tree.search(client.driver_license_number) == false)
			{
				tree.put(client);
				std::cout << "������ ���������������.\n";
			}
			else
				std::cout << "������ � ����� ������������ �������������� ��� ����������!\n";
			break;
		case 2:
			str = string.input_driver_license_number();
			if (tree.search(str) == false)             
				std::cout << "������ � ����� ������������ �������������� �����������!\n";
			else
			{
				tree.remove(str);
				std::cout << "�������� �������\n";
				std::string state_reg_num = list.search_number("", str);
				if (list.search(state_reg_num) == true)
					list.remove(state_reg_num);
				Car car = table.findCarByKey(state_reg_num);
				if (car.state_registration_number != "" && car.available == false) {
					table.removeByKey(state_reg_num);
					car.available = true;
					table.add(car.state_registration_number, car);
				}
			}
			break;
		case 3:
			tree.print_postfix();
			break;
		case 4:
			tree.clear(); 
			table.return_all_cars();
			list.clear();
			break;
		case 5:
			str = string.input_driver_license_number();
			client = tree.searchBy_driver_license(str);
			if (list.search_number("", str) != "")
				std::cout << "��������������� ��������������� �����: " << list.search_number("", str); 
			break;
		case 6:
			std::cout << "0 - ����� ������� �� ���������� ���:\n";
			std::cout << "1 - ����� ������� �� ���������� ������:\n2 - �����\n�������� �������� : ";
			std::cin >> n;
			while (std::cin.fail() || std::cin.get() != '\n' || (n < 0) || (n > 1))
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
				std::cout << "������ �����, �������� ��������: ";
				std::cin >> n;
			}
			switch (n)
			{
			case 0:
				std::cout << "������� ���: ";
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::getline(std::cin, str);
				tree.searchByName(str);
				break;
			case 1:
				std::cout << "������� �����: ";
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::getline(std::cin, str);
				tree.searchByAdress(str);
				break;
			case 2:
				break;
			}
			n = -1;
			break;
		case 7:
			car = car.input();
			if (table.contains(car.state_registration_number) == false)
			{
				table.add(car.state_registration_number, car);
				std::cout << "���������� ��������!\n";
			}
			else
				std::cout << "���������� � ����� ��� ������� ��� ����������!\n";
			break;
		case 8:
			str = string.input_state_registration_number(); 
			if (table.contains(str) == false)
				std::cout << "���������� � ����� ��������������� ��������������� ������� �����������!\n";
			else
			{
				table.removeByKey(str);
				std::cout << "�������� �������\n";
				if (list.search(str) == true)
					list.remove(str);
			}
			break;
		case 9:
			table.display();
			break;
		case 10:
			list.clear();
			table.clear();
			std::cout << "������� ������ ������ �������\n";
			break;
		case 11:
			str = string.input_state_registration_number();
			car = table.findCarByKey(str);
			if (car.state_registration_number != "")
			{
				std::cout << car;
				str = list.search_number(str, "");
				std::cout << "����� ������������� �������������: " << str << std::endl;
				tree.search_name(str);
			}
			else
				std::cout << "������� ���������� �� ����������! " << std::endl;
			break;
		case 12:
			str = string.input_brand();
			table.findByBrand(str);
			break;
		case 13:
			std::cout << "����������� �������� ���������� � ������:\n";
			str = string.input_state_registration_number();
			car = table.findCarByKey(str);
			if (car.state_registration_number == "")
				std::cout << "������� ���������� �� ����������! " << std::endl;
			else if (car.available == true)
			{
				table.removeByKey(str);
				car.available = false;
				table.add(str, car);
				std::cout << "���������� ��������� � ������\n";
			}
			else
				std::cout << "����� ��� ��������) " << std::endl;
			break;
		case 14:
			std::cout << "����������� �������� ���������� �� �������:\n";
			str = string.input_state_registration_number();
			car = table.findCarByKey(str);
			if (car.state_registration_number == "")
				std::cout << "������� ���������� �� ����������! " << std::endl;
			else if (car.available == false)
			{
				table.removeByKey(str);
				car.available = true;
				table.add(str, car);
			}
			else
				std::cout << "����� ��� �� �����) " << std::endl;
			break;
		case 15:
			std::cout << "15 - ����������� ������ ������� ���������� �� ������" << std::endl;
			str = string.input_driver_license_number();
			client = tree.searchBy_driver_license(str);
			if (client.driver_license_number != "")
			{
				car = table.findCarByKey(string.input_state_registration_number());
				if (car.state_registration_number != "" && car.available == true)
				{
					table.removeByKey(car.state_registration_number);
					car.available = false;
					table.add(car.state_registration_number, car);
					str = string.input_date("������� ���� ������ ������� ���������� �� ������: ");
					car_rental_status = { client.driver_license_number, car.state_registration_number, str, "" };
					list.push_back(car_rental_status);
					std::cout << "���������� ����� �� ������\n";
				}
				else
					std::cout << "������ ���������� �� ���������� � ���� ��� �� �� ��������.\n";
			}
			else
				std::cout << "������ � ����� ������� ������������� ������������� �� ����������.\n";
			break;
		case 16:
			std::cout << "16 - ����������� �������� ���������� �� ��������" << std::endl;
			state_registration_number = string.input_state_registration_number();
			str = list.search_number(state_registration_number, ""); // str - ����� ��� �� �������
			car = table.findCarByKey(state_registration_number);
			if (str != "" && car.available == false)
			{
					table.removeByKey(state_registration_number);
					car.available = true;
					table.add(state_registration_number, car);
					car_rental_status = list.get(state_registration_number);
					car_rental_status.date_return = string.input_date("������� ���� �������� ���������� �� ������� �� ������: ");
					list.remove(state_registration_number);
					list.push_back(car_rental_status);
					std::cout << "���������� �������� �� �������\n";
			}
			else
				std::cout << "������ ���������� �� ��������� �� ������!\n";
			break;
		case 17:
			if (list.is_empty() != true)
			{
				list.sort();
				list.output_list();
			}
			else
				std::cout << "������ ����\n";
			break;
		case 0:
			break;
		}
	}
	return 0;
}
