#pragma once

#include "InformationCarrier.h"

class HDD : public InformationCarrier // Класс «Портативный жесткий диск».
{
	int m_speed; // Скорость вращения шпинделя.
public:
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

	// Печать объекта "HDD".
	void Print() override;

	// Запись объекта "HDD" в текстовый файл.
	void Write(ofstream& out) override;

	// Чтение объекта "HDD" из текстового файла.
	void Read(ifstream& in) override;
};