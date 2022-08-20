#include "DVD.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Конструктор без параметров.
DVD::DVD() :InformationCarrier(), m_speed(0)
{
	m_productName = "DVD";
}

// Деструктор.
DVD::~DVD() = default;

// Конструктор со всеми параметрами.
DVD::DVD(string companyName, string productModel, string productName, int size, int count, int speed)
	:InformationCarrier(companyName, productModel, productName, size, count), m_speed(speed)
{
	set_productName("DVD");
}

// Установить значение поля "Скорость записи".
void DVD::set_speed(int speed)
{
	m_speed = speed;
}

// Установить значения всех полей обьекта "DVD".
void DVD::set_allFields()
{
	InformationCarrier::set_allFields();
	cout << "Скорость записи: ";
	cin >> m_speed;
}

// Получить значение поля "Скорость записи".
int DVD::get_speed()
{
	return this->m_speed;
}

// Заполнение обьекта случайными данными.
void DVD::RandomFill()
{
	InformationCarrier::RandomFill();
	m_speed = rand() % 50;
}

// Печать объекта "DVD".
void DVD::Print()
{
	cout << endl;
	InformationCarrier::Print();
	cout << "Скорость записи: " << m_speed << endl;
}

// Запись объекта "DVD" в текстовый файл.
void DVD::Write(ofstream& out)
{
	// TODO: написать реализацию
}

// Чтение объекта "DVD" из текстового файла.
void DVD::Read(ifstream& in)
{
	// TODO: написать реализацию
}