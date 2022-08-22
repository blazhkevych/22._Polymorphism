#include "HDD.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Конструктор без параметров.
HDD::HDD() :InformationCarrier(), m_speed(0)
{
	m_productName = "HDD";
}

// Деструктор.
HDD::~HDD() = default;

// Конструктор со всеми параметрами.
HDD::HDD(string companyName, string productModel, string productName, int size, int count, int speed)
	:InformationCarrier(companyName, productModel, productName, size, count), m_speed(speed)
{
	set_productName("HDD");
}

// Установить значение поля "Скорость вращения шпинделя".
void HDD::set_speed(int speed)
{
	m_speed = speed;
}

// Установить значения всех полей обьекта "HDD".
void HDD::set_allFields()
{
	InformationCarrier::set_allFields();
	cout << "Скорость вращения шпинделя: ";
	cin >> m_speed;
}

// Получить значение поля "Скорость вращения шпинделя".
int HDD::get_speed()
{
	return this->m_speed;
}

// Печать объекта "HDD".
void HDD::Print()
{
	cout << endl;
	InformationCarrier::Print();
	cout << "Скорость вращения шпинделя: " << m_speed << endl;
}

// Запись объекта "HDD" в текстовый файл.
void HDD::Write(ofstream& out)
{
	InformationCarrier::Write(out);
	out << m_speed << "\n";
}

// Чтение объекта "HDD" из текстового файла.
void HDD::Read(ifstream& in)
{
	InformationCarrier::Read(in);
	in >> m_speed;
}