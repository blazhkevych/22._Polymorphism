#pragma once
#include "InformationCarrier.h"
class MediaList // ����� ��������, ������ �������� ������� "USB", "HDD", "DVD".
{
	int m_size; // ���������� �������� � ������� (������ �������).
	InformationCarrier** m_mediaList; // ������������ ������ ���������� �� ������� ����� "InformationCarrier".
public:
	// ����������� �� ���������.
	MediaList();

	// ����������.
	~MediaList();

	// �������� ���������� ��������� � ������.
	int get_size() const;

	// ���������� ����������.
	void AddDevice();

	// ������ ����� ������ �c�������.
	void PrintAll() const;

	// ������ ������� �� ������ �c�������.
	void PrintSelective(int choice) const;

	// �������� ���������� �� ������.
	void Delete(int number);

	// ��������� �� ������ ���������� ��������.
	void Change(int number);

	// ����� �� ��������� ��������.
	void Search();

	// ���������� � ����.
	void Save();

	// �������� �� �����.
	void Load();
};