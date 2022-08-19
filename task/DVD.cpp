#include "DVD.h"

#include <iostream>
using std::cout;
using std::cin;

DVD::DVD() {};

DVD::~DVD() {};

int DVD::ret_class() { return 3; }

void DVD::SetFields() {
	InformationCarrier::SetFields();
	cout << "Produkt m_speed:";
	cin >> this->m_speed;
}

void DVD::settr(char* com_name, char* produkt_model_name, char* produkt_name, int count, int size, int speed) {
	InformationCarrier::SetFields(com_name, produkt_model_name, produkt_name, count, size/*, m_speed*/);
	speed = this->m_speed;
}

char* DVD::get_companyName() { return InformationCarrier::getCompanyName(); }

char* DVD::get_productModel() { return InformationCarrier::getProductModel(); }

char* DVD::get_productName() { return InformationCarrier::getProductName(); }

int DVD::get_Count() { return InformationCarrier::getCount(); }

int DVD::get_Size() { return InformationCarrier::getSize(); }

int DVD::get_speed() { return this->m_speed; }

void DVD::RandomFill() {
	InformationCarrier::RandomFill();
	m_speed = rand() % 50;
}

void DVD::Print() {
	std::cout << std::endl;
	InformationCarrier::Print();
	std::cout << "Product m_speed: " << this->m_speed << std::endl;
}

void DVD::Write(ofstream& out) {
	if (!out.is_open())
	{
		cout << "Error!";
		return;
	}

	InformationCarrier::Write(out);
	out.write((char*)&m_speed, sizeof(m_speed));
}
void DVD::Read(ifstream& in) {
	int sizes[3];
	if (!in.is_open())
	{
		std::cout << "Error!";
		return;
	}
	InformationCarrier::Read(in);
	in.read((char*)&m_speed, sizeof(m_speed));
}