#pragma once

#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;

class InformationCarrier abstract // Абстрактный базовый класс «Носитель информации».
{
protected:
	string m_companyName;		// Имя производителя.
	string m_productModel;		// Модель.
	string m_productName;		// Наименование. ( только для чтения(распознания объекта) из файла DVD/HDD/USB) 
	int m_size;					// Ёмкость носителя.
	int m_count;				// Количество носителей.
public:
	// Конструктор без параметров.
	InformationCarrier();

	// Конструктор cо всеми параметрами.
	InformationCarrier(string companyName, string productModel, string productName, int size, int count);

	// Деструктор.
	virtual ~InformationCarrier();

	// Установить значение поля "Имя производителя".
	void set_companyName(string companyName);

	// Установить значение поля "Модель".
	void set_productModel(string productModel);

	// Установить значение поля "Наименование".
	void set_productName(string productName);

	// Установить значение поля "Ёмкость носителя".
	void set_size(int size);

	// Установить значение поля "Количество носителей".
	void set_count(int count);

	// Установить значения всех полей объекта "InformationCarrier".
	virtual void set_allFields(); // TODO: переопределить в производных классах.

	// Получить значение поля "Имя производителя".
	virtual string get_companyName();

	// Получить значение поля "Модель".
	string get_productModel();

	// Получить значение поля "Наименование".
	string get_productName();

	// Получить значение поля "Ёмкость носителя".
	int get_count() const;

	// Получить значение поля "Количество носителей".
	int get_size() const;

	// Заполнение объекта "InformationCarrier" случайными данными.
	virtual void RandomFill(); // TODO: переопределить в производных классах.

	// Печать объекта "InformationCarrier".
	virtual void Print();// TODO: переопределить в производных классах.

	// Запись объекта "InformationCarrier" в текстовый файл.
	virtual void Write(ofstream& out);// TODO: переопределить в производных классах.

	// Чтение объекта "InformationCarrier" из текстового файла.
	virtual void Read(ifstream& in);// TODO: переопределить в производных классах.
};