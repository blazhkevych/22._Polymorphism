#pragma once
#include "InformationCarrier.h"
class MediaList // Класс хранящий, массив объектов классов "USB", "HDD", "DVD".
{
	int m_size; // Количество объектов в массиве (размер массива).
	InformationCarrier** m_mediaList; // Динамический массив указателей на базовый класс "InformationCarrier".
public:
	// Конструктор по умолчанию.
	MediaList();

	// Деструктор.
	~MediaList();

	// Получить количество устройств в списке.
	int get_size() const;

	// Добавление устройства.
	void AddDevice();

	// Печать всего списка уcтройств.
	void PrintAll() const;	

	// Печать выборки из списка уcтройств.
	void PrintSelective(int choice) const;

	// Удаление устройства по номеру.
	void Delete(int number);

	// Изменение по номеру параметров носителя.
	void Change(int number);

	// Поиск по заданному критерию.
	void Search();

	// Сохранение в файл.
	void Save();

	// Загрузка из файла.
	void Load();
};