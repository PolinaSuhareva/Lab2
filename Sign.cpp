#include <iostream>
#include <string.h>
#include "Sign.h"

using namespace std;

// конструктор по умолчанию
Sign::Sign()
{
    this->FnameLname = "None";
    this->sign = "None";
    this->birthday = "None";

    cout << "Вызван конструктор по умолчанию класса Sign" << endl;
}

// конструктор с параметром
Sign::Sign(string FnameLname, string sign, string birthday)
{
    this->FnameLname = FnameLname;
    this->sign = sign;
    this->birthday = birthday;

    cout << "Вызван конструктор с параметром класса Sign" << endl;
}

// конструктор копирования
Sign::Sign(const Sign &s)
{
    this->FnameLname = s.FnameLname;
    this->sign = s.sign;
    this->birthday = s.birthday;

    cout << "Вызван конструктор копирования класса Sign" << endl;
}

// деструктор
Sign::~Sign()
{
    cout << "Вызван деструктор класса Sign" << endl;
}

// метод извлечения значений
void Sign::Extract()
{
    cout << this;
}

// метод доступа к полям
void Sign::Get()
{
    string choice;

    try
    {
        cout << "Что хотите получить?" <<
                "1 - Фамилия Имя" <<
                "2 - Знак зодиака" <<
                "3 - День рождения" <<
                "4 - Все поля" << endl;
        cout << "Выбор: ";
        cin >> choice;

        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "Пункт назначения: " << this->FnameLname << endl;
    else if (choice == "2") cout << "Номер поезда: " << this->sign << endl;
    else if (choice == "3") cout << "Время отправления: " << this->birthday << endl;
    else if (choice == "4") cout << "Пункт назначения: " << this->FnameLname << "Номер поезда: " << this->sign << "Время отправления: " << this->birthday << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}


// метод вставки значения
void Sign::Set()
{
    cin >> *this;
}

// метод изменения значений
void Sign::Change()
{

}

ostream &operator<< (ostream &stream, Sign s) // перегрузка оператора извлеченния
{

}

iostream &operator>> (istream &stream, Sign &s) // перегрузка оператора вставки
{

}
