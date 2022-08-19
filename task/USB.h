#pragma once
#include "InformationCarrier.h"

class USB final : public InformationCarrier // Класс «USB-флеш-накопитель».
{
	int m_speed; // Скорость USB.
public:
	// TODO: в каждом производном классе в конструкторе, при создании обьекта в поле "наименование" вписать USB/DVD/HDD
	// возможно использовать type_id или просто в конструкторе жестко записать USB/DVD/HDD
	// Конструктор без параметров.
	USB();

	// Конструктор со всеми параметрами.
	USB(string companyName, string productModel, string productName, int size, int count, int speed);

	// Деструктор.
	//~USB(); // TODO: а нужен ли ?????????????

	// TODO: Продолжить отсюда реализацию нужных, не всех скорее всего, а только гет/сет для USB поля speed.


	void SetFields();
	void settr(char* com_name, char* produkt_model_name, char* produkt_name, int count, int size, int speed);
	string get_companyName();
	string get_productModel();
	string get_productName();
	int get_Size();
	int get_Count();;
	int get_speed();
	void RandomFill();
	void Print();
	void Write(ofstream& out);
	void Read(ifstream& in);
};

