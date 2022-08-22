#pragma once

#include "InformationCarrier.h"

class DVD : public InformationCarrier // Класс «DVD–диск».
{
	int m_speed; // Скорость записи.
public:
	// Конструктор без параметров.
	DVD();

	// Конструктор со всеми параметрами.
	DVD(string companyName, string productModel, string productName, int size, int count, int speed);

	// Деструктор.
	~DVD() override;

	// Установить значение поля "Скорость записи".
	void set_speed(int speed);

	// Установить значения всех полей обьекта "DVD".
	void set_allFields() override;

	// Получить значение поля "Скорость записи".
	int get_speed();

	// Печать объекта "DVD".
	void Print() override;

	// Запись объекта "DVD" в текстовый файл.
	void Write(ofstream& out) override;

	// Чтение объекта "DVD" из текстового файла.
	void Read(ifstream& in) override;
};