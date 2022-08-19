#include "USB.h"

#include <iostream>
using std::cout;
using std::cin;

// Конструктор без параметров.
USB::USB() :m_speed(0) {}

// Конструктор со всеми параметрами.
USB::USB(string companyName, string productModel, string productName, int size, int count, int speed)
	:InformationCarrier(companyName, productModel, productName, size, count), m_speed(speed) {}

// Деструктор.
//USB::~USB() {}

int USB::ret_class() { return 1; }

void USB::SetFields() {
	InformationCarrier::RandomFill();
	cout << "Produkt m_speed:";
	cin >> this->m_speed;
}

void USB::settr(char* com_name, char* produkt_model_name, char* produkt_name, int count, int size, int speed) {
	InformationCarrier::SetFields(com_name, produkt_model_name, produkt_name, count, size/*, m_speed*/);
	speed = this->m_speed;
}

char* USB::get_companyName() { return InformationCarrier::getCompanyName(); }

char* USB::get_productModel() { return InformationCarrier::getProductModel(); }

char* USB::get_productName() { return InformationCarrier::getProductName(); }

int USB::get_Size() { return InformationCarrier::getSize(); }

int USB::get_Count() { return InformationCarrier::getCount(); }

int USB::get_speed() { return this->m_speed; }

void USB::RandomFill() {
	InformationCarrier::RandomFill();
	m_speed = rand() % 50;
}

void USB::Print() {
	std::cout << std::endl;
	InformationCarrier::Print();
	std::cout << "Product m_speed: " << this->m_speed << std::endl;
}

void USB::Write(ofstream& out) {
	if (!out.is_open())
	{
		cout << "Error!";
		return;
	}

	InformationCarrier::Write(out);
	out.write((char*)&m_speed, sizeof(m_speed));
}
void USB::Read(ifstream& in) {
	int sizes[3];
	if (!in.is_open())
	{
		cout << "Error!";
		return;
	}
	InformationCarrier::Read(in);
	in.read((char*)&m_speed, sizeof(m_speed));
}