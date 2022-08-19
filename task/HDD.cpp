#include "HDD.h"

#include <iostream>
using std::cout;
using std::cin;

HDD::HDD() {};

HDD::~HDD() {};

int HDD::ret_class() { return 2; }

void HDD::SetFields() {
	InformationCarrier::SetFields();
	cout << "Produkt m_speed:";
	cin >> this->m_speed;
}

void HDD::settr(char* com_name, char* produkt_model_name, char* produkt_name, int count, int size, int speed) {
	InformationCarrier::SetFields(com_name, produkt_model_name, produkt_name, count, size/*, m_speed*/);
	speed = this->m_speed;
}

char* HDD::get_companyName() { return InformationCarrier::getCompanyName(); }

char* HDD::get_productModel() { return InformationCarrier::getProductModel(); }

char* HDD::get_productName() { return InformationCarrier::getProductName(); }

int HDD::get_Count() { return InformationCarrier::getCount(); }

int HDD::get_Size() { return InformationCarrier::getSize(); }

int HDD::get_speed() { return this->m_speed; }

void HDD::RandomFill() {
	InformationCarrier::RandomFill();
	m_speed = rand() % 50;
}

void HDD::Print() {
	std::cout << std::endl;
	InformationCarrier::Print();
	std::cout << "Product m_speed: " << this->m_speed << std::endl;
}

void HDD::Write(ofstream& out) {
	if (!out.is_open())
	{
		cout << "Error!";
		return;
	}
	InformationCarrier::Write(out);
	out.write((char*)&m_speed, sizeof(m_speed));
}
void HDD::Read(ifstream& in) {
	int sizes[3];
	if (!in.is_open())
	{
		std::cout << "Error!";
		return;
	}
	InformationCarrier::Read(in);
	in.read((char*)&m_speed, sizeof(m_speed));
}