#pragma once

#include "InformationCarrier.h"

class USB : public InformationCarrier // Класс «USB-флеш-накопитель».
{
	int m_speed; // Скорость USB.
public:
	// Конструктор без параметров.
	USB();

	// Конструктор со всеми параметрами.
	USB(string companyName, string productModel, string productName, int size, int count, int speed);

	// Деструктор.
	~USB() override;

	// Установить значение поля "Скорость USB".
	void set_speed(int speed);

	// Установить значения всех полей обьекта "USB".
	void set_allFields() override;

	// Получить значение поля "Скорость USB".
	int get_speed();

	// Печать объекта "USB".
	void Print() override;

	// Запись объекта "USB" в текстовый файл.
	void Write(ofstream& out) override;

	// Чтение объекта "USB" из текстового файла.
	void Read(ifstream& in) override;
};