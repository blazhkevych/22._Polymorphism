#pragma once
#include "InformationCarrier.h"
class HDD final : public InformationCarrier // класс «Портативный жесткий диск»;
{
	int m_speed; // Скорость вращения шпинделя.
public:
	// TODO: в каждом производном классе в конструкторе, при создании обьекта в поле "наименование" вписать USB/DVD/HDD
	// возможно использовать type_id или просто в конструкторе жестко записать USB/DVD/HDD
	HDD();
	~HDD();
	int ret_class();
	void SetFields();
	void settr(char* com_name, char* produkt_model_name, char* produkt_name, int count, int size, int speed);
	char* get_companyName();
	char* get_productModel();
	char* get_productName();
	int get_Count();
	int get_Size();
	int get_speed();
	void RandomFill();
	void Print();
	void Write(ofstream& out);
	void Read(ifstream& in);
};

