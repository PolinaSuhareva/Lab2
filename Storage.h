#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Sign.h"

using namespace std;

class Store
{
private:
    Sign **array;
    int countElement;

public:
    Store();
    Store(int size);
    Store(const Store &s);
    ~Store();

    void SortedArray(); // сортировка после ввода
    void FindLname(); // поиск по фамилии
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значние
};

#endif
