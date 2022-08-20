#pragma once

#include "InformationCarrier.h"

class DVD  : public InformationCarrier // класс «DVD–диск».
{
	int m_speed; // Скорость записи.
public:
	// TODO: в каждом производном классе в конструкторе, при создании обьекта в поле "наименование" вписать USB/DVD/HDD
	// возможно использовать type_id или просто в конструкторе жестко записать USB/DVD/HDD
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

	// Заполнение обьекта "DVD" случайными данными.
	void RandomFill() override;

	// Печать объекта "DVD".
	void Print() override;

	// Запись объекта "DVD" в текстовый файл.
	void Write(ofstream& out) override;

	// Чтение объекта "DVD" из текстового файла.
	void Read(ifstream& in) override;
};