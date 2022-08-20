#pragma once

#include "InformationCarrier.h"

class HDD : public InformationCarrier // класс «Портативный жесткий диск»;
{
	int m_speed; // Скорость вращения шпинделя.
public:
	// TODO: в каждом производном классе в конструкторе, при создании обьекта в поле "наименование" вписать USB/DVD/HDD
	// возможно использовать type_id или просто в конструкторе жестко записать USB/DVD/HDD
	// Конструктор без параметров.
	HDD();

	// Конструктор со всеми параметрами.
	HDD(string companyName, string productModel, string productName, int size, int count, int speed);

	// Деструктор.
	~HDD() override;

	// Установить значение поля "Скорость вращения шпинделя".
	void set_speed(int speed);

	// Установить значения всех полей обьекта "HDD".
	void set_allFields() override;

	// Получить значение поля "Скорость вращения шпинделя".
	int get_speed();

	// Заполнение обьекта "HDD" случайными данными.
	void RandomFill() override;

	// Печать объекта "HDD".
	void Print() override;

	// Запись объекта "HDD" в текстовый файл.
	void Write(ofstream& out) override;

	// Чтение объекта "HDD" из текстового файла.
	void Read(ifstream& in) override;
};

