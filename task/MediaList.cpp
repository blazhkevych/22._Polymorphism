#include "MediaList.h"

Collection::Collection() {
	for (int i = 0; i < ch_long; i++)
	{
		int r = rand() % 3;

		switch (r)
		{
		case 0:
			collection[i] = new usb;
			break;
		case 1:
			collection[i] = new dvd;
			break;

		case 2:
			collection[i] = new phd;
			break;
		}
		//collection[i]->SetFields();
	}
}


Collection::~Collection() {}


void Collection::Print() {
	int var = 1;
	for (int i = 0; i < ch_long; i++)
	{
		cout << var << endl;
		collection[i]->Print();
		int type = collection[i]->ret_class();
		switch (type)
		{
		case 0:
			cout << "Base" << endl;
			break;
		case 1:
			cout << "USB" << endl;
			break;
		case 2:
			cout << "PHD" << endl;
			break;
		case 3:
			cout << "DVD" << endl;
			break;
		default:
			break;

		}
		cout << "-------------------------------------------------------" << endl;
		var++;
	}
}


void Collection::chan(int nomb) {
	nomb = nomb - 1;
	collection[nomb]->settr();
}


void Collection::dell(int nomb) {
	nomb = nomb - 1;
	Base** temp = new Base * [ch_long - 1];
	for (int i = 0; i < ch_long; i++)
	{
		if (i < nomb) {
			temp[i] = collection[i];
		}
		else if (i > nomb)
		{
			temp[i - 1] = collection[i];
		}
	}
	delete collection[nomb];
	delete[] collection;
	ch_long--;
	collection = temp;
	temp = nullptr;
}


void Collection::add() {
	Base** temp = new Base * [ch_long + 1];
	for (int i = 0; i < ch_long; i++)
	{
		temp[i] = collection[i];
	}
	cout << "Type : (1 - usb || 2 - dvd || 3 - phd)   :";
	int var2;
	cin >> var2;
	switch (var2)
	{
	case 1:
		temp[ch_long] = new usb;
		break;
	case 2:
		temp[ch_long] = new dvd;
		break;
	case 3:
		temp[ch_long] = new phd;
		break;
	default:
		break;
	}
	temp[ch_long]->settr();
	delete[] collection;
	ch_long++;
	collection = temp;
	temp = nullptr;
}
void Collection::rand__str() {
	for (int i = 0; i < ch_long; i++)
	{
		collection[i]->rand_settr();
	}
}


void Collection::search() {
	cout << "1 - com_name \n 2 - produkt_model_name \n 3 - produkt_name \n 4 - count\n 5 - size\n 6 - speed\n";
	cout << "Choose param.  :";
	int var;
	cin >> var;
	switch (var)
	{
	case 1:
	{
		char temp[100]{};
		cin >> temp;
		for (int i = 0; i < ch_long; i++)
		{
			if (!strcmp(collection[i]->get_com_name(), temp))
			{
				collection[i]->Print();
			}
		}
		break;
	}
	case 2:
	{
		char temp[100]{};
		cin >> temp;
		for (int i = 0; i < ch_long; i++)
		{
			if (!strcmp(collection[i]->get_produkt_model_name(), temp))
			{
				collection[i]->Print();
			}
		}
		break;
	}
	case 3:
	{
		char temp[100]{};
		cin >> temp;
		for (int i = 0; i < ch_long; i++)
		{
			if (!strcmp(collection[i]->get_produkt_name(), temp))
			{
				collection[i]->Print();
			}
		}
		break;
	}
	case 4:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < ch_long; i++)
		{
			int j = collection[i]->get_count();
			if (j == temp)
			{
				collection[i]->Print();
			}
		}
		break;
	}
	case 5:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < ch_long; i++)
		{
			int j = collection[i]->get_size();
			if (j == temp)
			{
				collection[i]->Print();
			}
		}
		break;
	}
	case 6:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < ch_long; i++)
		{
			int j;
			switch (collection[i]->ret_class())
			{
			case 1:
			{
				usb* temp_class1 = static_cast<usb*>(collection[i]);
				j = temp_class1->get_speed();
				//delete temp_class1; 
				break;
			}
			case 2:
			{
				dvd* temp_class2 = static_cast<dvd*>(collection[i]);
				j = temp_class2->get_speed();
				//delete temp_class2;
				break;
			}
			case 3:
			{
				phd* temp_class3 = static_cast<phd*>(collection[i]);
				j = temp_class3->get_speed();
				//delete temp_class3;
				break;
			}
			}
			if (temp == j)
			{
				collection[i]->Print();
			}
		}
		break;
	}
	default:
		cout << "ERROR" << endl;
		break;
	}
}


void Collection::write() {
	ofstream out("./out.txt", ios_base::out | ios_base::trunc);
	if (!out.is_open())
	{
		cout << "Error!";
		return;
	}
	out.write((char*)&ch_long, sizeof(ch_long));
	for (int i = 0; i < ch_long; i++)
	{
		if (!out.is_open())
		{
			cout << "Error!";
			return;
		}
		int type = collection[i]->ret_class();
		out.write((char*)&type, sizeof(type));
		collection[i]->write(out);
	}
}


void Collection::read() {
	for (int i = 0; i < sizeof(collection); i++)
	{
		delete collection[i];
	}
	ifstream in("./out.txt", ios_base::in);
	if (!in.is_open())
	{
		cout << "Error!";
		return;
	}
	in.read((char*)&ch_long, sizeof(ch_long));
	collection = new Base * [ch_long];
	for (int i = 0; i < ch_long; i++)
	{
		if (!in.is_open())
		{
			cout << "Error!";
			return;
		}
		int type;
		in.read((char*)&type, sizeof(type));
		switch (type)
		{
		case 1:
			collection[i] = new usb;
			break;
		case 2:
			collection[i] = new dvd;
			break;
		case 3:
			collection[i] = new phd;
			break;
		}
		collection[i]->read(in);
	}
}