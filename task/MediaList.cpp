#include "MediaList.h"

#include <iostream>
#include <fstream>

#include "DVD.h"
#include "HDD.h"
#include "USB.h"

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

// ����������� �� ���������.
MediaList::MediaList()
{
	m_mediaList = nullptr;
	m_size = 0;
}

// ����������.
MediaList::~MediaList()
{
	for (int i = 0; i < m_size; i++)
		delete m_mediaList[i];
	delete[] m_mediaList;
}

// �������� ���������� ��������� � ������.
int MediaList::get_size() const
{
	return m_size;
}

// ���������� ����������.
void MediaList::AddDevice()
{
	int deviceCount{ 0 };
	do
	{
		cout << "\n������� ���������� ��������� ��� ���������� � ������: ";
		cin >> deviceCount;
		cin.get();
	} while (deviceCount <= 0);

	InformationCarrier** temp = new InformationCarrier * [m_size + deviceCount];
	for (int i = 0; i < m_size; i++)
		temp[i] = m_mediaList[i];

	delete[] m_mediaList;

	int inputNumOfStud{ 1 };
	for (int i = m_size; i < m_size + deviceCount; i++)
	{
		cout << "\n�������� ��� " << inputNumOfStud << " ����������: ";
		inputNumOfStud++;

		cout << "\n(1 - USB, 2 - DVD, 3 - HDD): ";
		int type;
		cin >> type;
		cin.get();
		switch (type)
		{
		case 1:
			temp[i] = new USB;
			break;
		case 2:
			temp[i] = new DVD;
			break;
		case 3:
			temp[i] = new HDD;
			break;
		default:
			break;
		}

		temp[i]->set_allFields();
	}

	m_size = m_size + deviceCount;
	m_mediaList = temp;
	temp = nullptr;
}

// ������ ����� ������ �c�������.
void MediaList::PrintAll() const
{
	for (int i = 0; i < m_size; i++)
	{
		cout << endl << "���������� � " << i + 1 << endl;
		m_mediaList[i]->Print();
		cout << "-------------------------------------------------------" << endl;
	}
}

// ������ ������� �� ������ �c�������.
void MediaList::PrintSelective(int choice) const
{
	int carriersPrinted{ 0 };
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*m_mediaList[i]) == typeid(USB) && choice == 2) // ������ ������ USB.			
		{
			carriersPrinted++;
			cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
				<< "-------------------------------------------------------";
			m_mediaList[i]->Print();
			cout << "-------------------------------------------------------" << endl;
		}

		if (typeid(*m_mediaList[i]) == typeid(HDD) && choice == 3) // ������ ������ HDD.			
		{
			carriersPrinted++;
			cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
				<< "-------------------------------------------------------";
			m_mediaList[i]->Print();
			cout << "-------------------------------------------------------" << endl;
		}

		if (typeid(*m_mediaList[i]) == typeid(DVD) && choice == 4)// ������ ������ DVD.		
		{
			carriersPrinted++;
			cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
				<< "-------------------------------------------------------";
			m_mediaList[i]->Print();
			cout << "-------------------------------------------------------" << endl;
		}

		/* ��� �����, �� ���� ���� ������ ��������.
		 *if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
			m_mediaList[i]->PrintAll();*/
	}
	cout << endl << "����� ����������� " << carriersPrinted << " ���������." << endl;
}

// �������� ���������� �� ������.
void MediaList::Delete(int number)
{
	number = number - 1;

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

// ��������� �� ������ ���������� ��������.
void MediaList::Change(int number)
{
	number = number - 1;
	cout << endl << "��� ����� �������� ?"
		<< "\n1 - ��� �������������."
		<< "\n2 - ������."
		<< "\n3 - ������� ��������."
		<< "\n4 - ���������� ���������."
		<< "\n5 - ��������."
		<< "\n������� ����� ���� ��� ���������, ����� ��� �������� >>> : ";
	int var;
	cin >> var;
	cin.get();
	switch (var)
	{
	case 1: // ��� �������������.
	{
		string temp;
		getline(cin, temp);
		m_mediaList[number]->set_companyName(temp);
		break;
	}
	case 2: // ������.
	{
		string temp;
		getline(cin, temp);
		m_mediaList[number]->set_productModel(temp);
		break;
	}
	case 3: // ������� ��������.
	{
		int temp;
		cin >> temp;
		m_mediaList[number]->set_size(temp);
		break;
	}
	case 4: // ���������� ���������.
	{
		int temp;
		cin >> temp;
		m_mediaList[number]->set_count(temp);
		break;
	}
	case 5: // ��������.
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
		cout << "������!" << endl;
		break;
	}
}

// ����� �� ��������� ��������.
void MediaList::Search()
{
	int carriersFound{ 0 }; // ����� ��������� ���������� ���������.
	cout << endl << "��� ����� ������ ?"
		<< "\n1 - ��� �������������."
		<< "\n2 - ������."
		<< "\n3 - ������������."
		<< "\n4 - ������� ��������."
		<< "\n5 - ���������� ���������."
		<< "\n6 - ��������."
		<< "\n������� ����� �������� ��� ������, ����� ��� �������� >>> : ";
	int var;
	cin >> var;
	switch (var)
	{
	case 1:
	{
		string temp;
		getline(cin, temp);
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_companyName() == temp) // ��� �������������.
			{
				carriersFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				m_mediaList[i]->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		break;
	}
	case 2:
	{
		string temp;
		getline(cin, temp);
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_productModel() == temp) // ������.
			{
				carriersFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				m_mediaList[i]->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		break;
	}
	case 3:
	{
		string temp;
		getline(cin, temp);
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_productName() == temp) // ������������.
			{
				carriersFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				m_mediaList[i]->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		break;
	}
	case 4:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_size() == temp) // ������� ��������.
			{
				carriersFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				m_mediaList[i]->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		break;
	}
	case 5:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
			if (m_mediaList[i]->get_count() == temp) // ���������� ���������.
			{
				carriersFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				m_mediaList[i]->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		break;
	}
	case 6:
	{
		int temp;
		cin >> temp;
		for (int i = 0; i < m_size; i++)
		{
			if (typeid(*m_mediaList[i]) == typeid(USB)) // ��������.
				if (dynamic_cast<USB*>(m_mediaList[i])->get_speed() == temp)
				{
					carriersFound++;
					cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
						<< "-------------------------------------------------------";
					m_mediaList[i]->Print();
					cout << "-------------------------------------------------------" << endl;
				}

			if (typeid(*m_mediaList[i]) == typeid(HDD))
				if (dynamic_cast<HDD*>(m_mediaList[i])->get_speed() == temp)
				{
					carriersFound++;
					cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
						<< "-------------------------------------------------------";
					m_mediaList[i]->Print();
					cout << "-------------------------------------------------------" << endl;
				}

			if (typeid(*m_mediaList[i]) == typeid(DVD))
				if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
				{
					carriersFound++;
					cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
						<< "-------------------------------------------------------";
					m_mediaList[i]->Print();
					cout << "-------------------------------------------------------" << endl;
				}

			/* ��� �����, �� ���� ���� ������ ��������.
			 *if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
				m_mediaList[i]->PrintAll();*/
		}
		break;
	}
	default:
		cout << "������!" << endl;
		break;
	}
	cout << endl << "����� ������� " << carriersFound << " ���������." << endl;
}

// ���������� � ����.
void MediaList::Save()
{
	// ������ �������� �������� ����� � ������������ � ���� ����, ������� ����������� �� ������ � ��������� ������.
	ofstream out("data.txt", ios_base::out | ios_base::trunc);
	if (!out.is_open()) // ���� �������� ����� ����������� �������� - �������.
	{
		cout << "Error!\n";
		return;
	}

	out << m_size << "\n"; // ���������� ���������� ��������� � �������.

	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*m_mediaList[i]) == typeid(USB))
			m_mediaList[i]->Write(out);
		if (typeid(*m_mediaList[i]) == typeid(HDD))
			m_mediaList[i]->Write(out);
		if (typeid(*m_mediaList[i]) == typeid(DVD))
			m_mediaList[i]->Write(out);
	}
	out.close(); // ��������� �������� �����.
}

// �������� �� �����.
void MediaList::Load()
{
	// ������ ������� �������� ����� � ������������ � ���� ����, ������� ����������� �� ������ � ��������� ������.
	ifstream in("data.txt");
	if (!in.is_open()) // ���� �������� ����� ����������� �������� - �������.
	{
		cout << "Error!\n";
		return;
	}

	in >> m_size; // ��������� ���������� ���������� �������� � �����.
	m_mediaList = new InformationCarrier * [m_size];

	string productName{}; // ������������. 

	for (int i = 0; i < m_size; i++)
	{
		getline(in, productName);
		in >> productName;

		if (productName == "USB")
		{
			m_mediaList[i] = new USB;
			m_mediaList[i]->set_productName(productName);
			m_mediaList[i]->Read(in);
			continue;
		}
		if (productName == "HDD")
		{
			m_mediaList[i] = new HDD;
			m_mediaList[i]->set_productName(productName);
			m_mediaList[i]->Read(in);
			continue;
		}
		if (productName == "DVD")
		{
			m_mediaList[i] = new DVD;
			m_mediaList[i]->set_productName(productName);
			m_mediaList[i]->Read(in);
		}
	}
	in.close();
}