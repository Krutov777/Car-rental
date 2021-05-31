#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Check_str.h"
#include  "HashTable.h"

struct Car_rental_status
{
	std::string driver_license_number;    //����� ������������� �������������
	std::string state_registration_number;//��������������� ��������������� �����
	std::string date_receive;			  // ���� ������ ������
	std::string date_return;			  // ���� �������� ������

	bool operator > (Car_rental_status obj)
	{
		return this->state_registration_number > obj.state_registration_number ? true : false;
	}
	bool operator < (Car_rental_status obj)
	{
		return this->state_registration_number < obj.state_registration_number ? true : false;
	}
	bool operator == (Car_rental_status obj)
	{
		return this->state_registration_number == obj.state_registration_number ? true : false;
	}

	void output(Car_rental_status object)
	{
		std::cout << "  ������ � ������ �� ������ ��� �������� ����������� �� ��������:" << std::endl;
		std::cout << "����� ������������� �������������: "; std::cout << object.driver_license_number << std::endl;
		std::cout << "��������������� ��������������� �����: "; std::cout << object.state_registration_number << std::endl;
		std::cout << "���� ������ ������ "; std::cout << object.date_receive << std::endl;;
		std::cout << "���� �������� ������ "; std::cout << object.date_return << std::endl << std::endl;
	}
};

struct node
{
	Car_rental_status data;
	node* next;
};

class List : public Check_str
{
private:
	node* head;
public:
	List();
	~List();
	void clear();
	bool is_empty();
	Car_rental_status input_elem();
	void push_back(Car_rental_status elem);
	void push_front();
	void pop_back();
	void pop_front();
	void remove(std::string state_registration_number);
	void removeByDriverLicense(std::string driver_license_number);
	bool search(std::string state_registration_number);
	std::string searchBy_driver_license(std::string driver_license_number);
	int size();
	void edit(Car_rental_status elem, int index);
	void sort();
	void output_list();
	Car_rental_status get(std::string state_registration_number);
	Car_rental_status get_item(int index);//index � 1
	std::string search_number(std::string state_registration_number = "", std::string driver_license_number = "");
};
