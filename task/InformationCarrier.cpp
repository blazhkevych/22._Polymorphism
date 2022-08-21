﻿#include "InformationCarrier.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Конструктор без параметров.
InformationCarrier::InformationCarrier() : m_size(0), m_count(0) {}

// Конструктор cо всеми параметрами.
InformationCarrier::InformationCarrier(string companyName, string productModel, string productName, int size, int count)
	:m_companyName(companyName), m_productModel(productModel), m_productName(productName), m_size(size), m_count(count) {}

// Деструктор.
InformationCarrier::~InformationCarrier() = default;

// Установить значение поля "Имя производителя".
void InformationCarrier::set_companyName(string companyName)
{
	m_companyName = companyName;
}

// Установить значение поля "Модель".
void InformationCarrier::set_productModel(string productModel)
{
	m_productModel = productModel;
}

// Установить значение поля "Наименование".
void InformationCarrier::set_productName(string productName)
{
	m_productName = productName;
}

// Установить значение поля "Ёмкость носителя".
void InformationCarrier::set_size(int size)
{
	m_size = size;
}

// Установить значение поля "Количество носителей".
void InformationCarrier::set_count(int count)
{
	m_count = count;
}

// Установить значения всех полей объекта "InformationCarrier".
void InformationCarrier::set_allFields()
{
	cout << endl
		<< "Имя производителя: ";
	cin >> m_companyName;
	cout << "Модель: ";
	cin >> m_productModel;
	cout << "Ёмкость носителя: ";
	cin >> m_size;
	cout << "Количество носителей: ";
	cin >> m_count;
}

// Получить значение поля "Имя производителя".
string InformationCarrier::get_companyName() { return m_companyName; }

// Получить значение поля "Модель".
string InformationCarrier::get_productModel() { return m_productModel; }

// Получить значение поля "Наименование".
string InformationCarrier::get_productName() { return m_productName; }

// Получить значение поля "Ёмкость носителя".
int InformationCarrier::get_count() const { return m_count; }

// Получить значение поля "Количество носителей".
int InformationCarrier::get_size() const { return m_size; }

// Заполнение объекта "InformationCarrier" случайными данными.
void InformationCarrier::RandomFill()
{
	m_companyName = rand() % 27 + 65; // TODO: проверить как работает
	m_productModel = rand() % 27 + 65; // TODO: проверить как работает
	//m_productName = rand() % 27 + 65; // TODO: проверить как работает

	m_count = rand() % 50;
	m_size = rand() % 50;
}

// Печать объекта "InformationCarrier".
void InformationCarrier::Print()
{
	cout << "Имя производителя: " << m_companyName << endl;
	cout << "Модель: " << m_productModel << endl;
	cout << "Наименование: " << m_productName << endl;
	cout << "Ёмкость носителя: " << m_size << endl;
	cout << "Количество носителей: " << m_count << endl;
}

// Запись объекта "InformationCarrier" в текстовый файл.
void InformationCarrier::Write(ofstream& out)
{
	out << "Наименование: " << m_productName << endl // Пишем первым, для понимания что мы будем вычитывать из файла.
		<< "Имя производителя: " << m_companyName << endl
		<< "Модель: " << m_productModel << endl
		<< "Ёмкость носителя: " << m_size << endl
		<< "Количество носителей: " << m_count << endl;
}

// Чтение объекта "InformationCarrier" из текстового файла.
void InformationCarrier::Read(ifstream& in)
{
	in >> m_productName;
	in >> m_companyName;
	in >> m_productModel;
	in >> m_size;
	in >> m_count;
}