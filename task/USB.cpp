#include "USB.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Конструктор без параметров.
USB::USB() :InformationCarrier(), m_speed(0)
{
	m_productName = "USB";
}

// Деструктор.
USB::~USB() = default;

// Конструктор со всеми параметрами.
USB::USB(string companyName, string productModel, string productName, int size, int count, int speed)
	:InformationCarrier(companyName, productModel, productName, size, count), m_speed(speed)
{
	set_productName("USB");
}

// Установить значение поля "Скорость USB".
void USB::set_speed(int speed)
{
	m_speed = speed;
}

// Установить значения всех полей обьекта "USB".
void USB::set_allFields()
{
	InformationCarrier::set_allFields();
	cout << "Скорость USB: ";
	cin >> m_speed;
}

// Получить значение поля "Скорость USB".
int USB::get_speed()
{
	return this->m_speed;
}

// Заполнение обьекта случайными данными.
void USB::RandomFill()
{
	InformationCarrier::RandomFill();
	m_speed = rand() % 50;
}

// Печать объекта "USB".
void USB::Print()
{
	cout << endl;
	InformationCarrier::Print();
	cout << "Скорость USB: " << m_speed << endl;
	// TODO: возможно для метода чтения из файла нужно после m_speed дописывать в файл пробел
}

// Запись объекта "USB" в текстовый файл.
void USB::Write(ofstream& out)
{
	InformationCarrier::Write(out);
	out << "Скорость USB: " << m_speed << endl;
}

// Чтение объекта "USB" из текстового файла.
void USB::Read(ifstream& in)
{
	InformationCarrier::Read(in);
	in >> m_speed;
}