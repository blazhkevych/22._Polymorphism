#include "MediaList.h"

#include <iostream>

#include "DVD.h"
#include "HDD.h"
#include "USB.h"

using std::cout;
using std::cin;
using std::endl;

// Конструктор по умолчанию.
MediaList::MediaList()
{
	m_mediaList = nullptr;
	m_size = 0;
}

// Деструктор.
MediaList::~MediaList()
{
	for (int i = 0; i < m_size; i++)
		delete m_mediaList[i];
	delete[] m_mediaList;
}

// Получить количество устройств в списке.
int MediaList::get_size() const
{
	return m_size;
}

// Добавление устройства.
void MediaList::AddDevice()
{
	int deviceCount;
	do
	{
		cout << "\nВведите количество устройств для добавления в список: ";
		cin >> deviceCount;
		cin.get();
	} while (deviceCount <= 0);

	InformationCarrier** temp = new InformationCarrier * [m_size + deviceCount];
	for (int i = 0; i < m_size; i++)
		temp[i] = m_mediaList[i];

	int inputNumOfStud{ 0 };
	for (int i = m_size; i < m_size + deviceCount; i++)
	{
		cout << "\nВыберите тип " << inputNumOfStud << " устройства: ";
		inputNumOfStud++;

		cout << "\n(1 - USB, 2 - DVD, 3 - HDD): ";
		int type;
		cin >> type;

		switch (type)
		{
		case 1:
			temp[m_size + i] = new USB;
			break;
		case 2:
			temp[m_size + i] = new DVD;
			break;
		case 3:
			temp[m_size + i] = new HDD;
			break;
		default:
			break;
		}

		temp[m_size + i]->set_allFields();
	}

	delete[] m_mediaList;
	m_size = m_size + deviceCount;
	m_mediaList = temp;
	temp = nullptr;
}

// Печать списка уcтройств.
void MediaList::PrintAll() const
{
	for (int i = 0; i < m_size; i++)
	{
		cout << endl << "Устройство № " << i << endl;
		m_mediaList[i]->Print();
		cout << "-------------------------------------------------------" << endl;
	}
}

// Удаление устройства по номеру.
void MediaList::Delete(int number)
{
	for (int i = 0; i < m_size; i++)
	{
		cout << endl << "Устройство № " << i << endl;
		m_mediaList[i]->Print();
		cout << "-------------------------------------------------------" << endl;
	}

	InformationCarrier** temp = new InformationCarrier * [m_size - 1];

	for (int i = 0; i < m_size; i++)
	{
		if (i < number)
		{
			temp[i] = m_mediaList[i];
		}
		else if (i > number)
		{
			temp[i - 1] = m_mediaList[i];
		}
	}

	delete m_mediaList[number];
	delete[] m_mediaList;

	m_size--;
	m_mediaList = temp;
	temp = nullptr;
}

// Изменение по номеру параметров носителя.
void MediaList::Change(int number) // TODO: определённых параметров носителя !!!! доработать.
{
	cout << endl << "Что будем изменять ?"
		<< "\n1 - Имя производителя."
		<< "\n2 - Модель."
		<< "\n3 - Ёмкость носителя."
		<< "\n4 - Количество носителей."
		<< "\n5 - Скорость."
		<< "\nВведите номер поля для изменения, затем его значение >>> : ";
	int var;
	cin >> var;
	switch (var)
	{
	case 1: // Имя производителя.
	{
		string temp;
		cin >> temp;
		m_mediaList[number]->set_companyName(temp);
		break;
	}
	case 2: // Модель.
	{
		string temp;
		cin >> temp;
		m_mediaList[number]->set_productModel(temp);
		break;
	}
	case 3: // Ёмкость носителя.
	{
		int temp;
		cin >> temp;
		m_mediaList[number]->set_size(temp);
		break;
	}
	case 4: // Количество носителей.
	{
		int temp;
		cin >> temp;
		m_mediaList[number]->set_count(temp);
		break;
	}
	case 5: // Скорость.
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
		{
			if (typeid(*m_mediaList[number]) == typeid(USB))
				dynamic_cast<USB*>(m_mediaList[number])->set_speed(temp);

			if (typeid(*m_mediaList[number]) == typeid(HDD))
				dynamic_cast<HDD*>(m_mediaList[number])->set_speed(temp);

			if (typeid(*m_mediaList[number]) == typeid(DVD))
				dynamic_cast<DVD*>(m_mediaList[number])->set_speed(temp);
		}
		break;
	}
	default:
		cout << "Ошибка!" << endl;
		break;
	}
}

// Поиск по заданному критерию.
void MediaList::Search()
{
	cout << endl << "Что будем искать ?"
		<< "\n1 - Имя производителя."
		<< "\n2 - Модель."
		<< "\n3 - Наименование."
		<< "\n4 - Ёмкость носителя."
		<< "\n5 - Количество носителей."
		<< "\n6 - Скорость."
		<< "\nВведите номер критерия для изменения, затем его значение >>> : ";
	int var;
	cin >> var;
	switch (var)
	{
	case 1:
	{
		string temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_companyName() == temp) // Имя производителя.
				m_mediaList[i]->Print();
		break;
	}
	case 2:
	{
		string temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_productModel() == temp) // Модель.
				m_mediaList[i]->Print();
		break;
	}
	case 3:
	{
		string temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_productName() == temp) // Наименование.
				m_mediaList[i]->Print();
		break;
	}
	case 4:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_size() == temp) // Ёмкость носителя.
				m_mediaList[i]->Print();
		break;
	}
	case 5:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_count() == temp) // Количество носителей.
				m_mediaList[i]->Print();
		break;
	}
	case 6:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
		{
			if (typeid(*m_mediaList[i]) == typeid(USB)) // Скорость.
				if (dynamic_cast<USB*>(m_mediaList[i])->get_speed() == temp)
					m_mediaList[i]->Print();

			if (typeid(*m_mediaList[i]) == typeid(HDD))
				if (dynamic_cast<HDD*>(m_mediaList[i])->get_speed() == temp)
					m_mediaList[i]->Print();

			if (typeid(*m_mediaList[i]) == typeid(DVD))
				if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
					m_mediaList[i]->Print();

			/* или проще, по идее тоже должно работать.
			 *if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
				m_mediaList[i]->PrintAll();*/
		}
		break;
	}
	default:
		cout << "Ошибка!" << endl;
		break;
	}
}