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
	void setCompanyName(string companyName);

	// Установить значение поля "Модель".
	void setProductModel(string productModel);

	// Установить значение поля "Наименование".
	void setProductName(string productName);

	// Установить значение поля "Ёмкость носителя".
	void setSize(int size);

	// Установить значение поля "Количество носителей".
	void setCount(int count);

	// Получить значение поля "Имя производителя".
	string getCompanyName();

	// Получить значение поля "Модель".
	string getProductModel();

	// Получить значение поля "Наименование".
	string getProductName();

	// Получить значение поля "Ёмкость носителя".
	int getCount() const;

	// Получить значение поля "Количество носителей".
	int getSize() const;

	// Заполнение обьекта случайными данными.
	virtual void RandomFill(); // TODO: переопределить в производных классах.

	// Печать объекта.
	virtual void Print();// TODO: переопределить в производных классах.

	// Запись в текстовый файл.
	virtual void Write(ofstream& out);// TODO: переопределить в производных классах.

	// Чтение из текстового файла.
	virtual void Read(ifstream& in);// TODO: переопределить в производных классах.
};