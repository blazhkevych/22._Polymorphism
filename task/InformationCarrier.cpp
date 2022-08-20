#include "InformationCarrier.h"

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
	/*if (!out.is_open())
	{
		cout << "Error!";
		return;
	}
	ofstream out("output.txt");*/

	/*std::string input;
	std::cin >> input;
	std::ofstream out("output.txt");
	out << input;
	out.close();*/

	/*int size = _msize(m_companyName) + 1;
	out.write((char*)&size, sizeof(size));
	out.write((char*)m_companyName, size);

	size = _msize(m_productModel) + 1;
	out.write((char*)&size, sizeof(size));
	out.write((char*)m_productModel, size);

	size = _msize(m_productName) + 1;
	out.write((char*)&size, sizeof(size));
	out.write((char*)m_productName, size);

	out.write((char*)&m_count, sizeof(m_count));
	out.write((char*)&this->m_size, sizeof(this->m_size));*/
}

// Чтение объекта "InformationCarrier" из текстового файла.
void InformationCarrier::Read(ifstream& in) {
	/*int sizes[3];
	if (!in.is_open())
	{
		cout << "Error!";
		return;
	}*/


	/*in.read((char*)&sizes[0], sizeof(sizes[0]));
	in.read(m_companyName, sizes[0]);

	in.read((char*)&sizes[1], sizeof(sizes[1]));
	in.read(m_productModel, sizes[1]);

	in.read((char*)&sizes[2], sizeof(sizes[2]));
	in.read(m_productName, sizes[2]);

	in.read((char*)&m_count, sizeof(m_count));
	in.read((char*)&m_size, sizeof(m_size));*/
}