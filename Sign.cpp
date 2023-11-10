#include <iostream>
#include <string.h>
#include "Sign.h"

using namespace std;

// конструктор по умолчанию
Sign::Sign()
{
    this->LnameFname = "None";
    this->sign = "None";
    this->birthday = "None";

    cout << "Вызван конструктор по умолчанию класса Sign" << endl;
}

// конструктор с параметром
Sign::Sign(string LnameFname, string sign, string birthday)
{
    this->LnameFname = LnameFname;
    this->sign = sign;
    this->birthday = birthday;

    cout << "Вызван конструктор с параметром класса Sign" << endl;
}

// конструктор копирования
Sign::Sign(const Sign &s)
{
    this->LnameFname = s.LnameFname;
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

    if (choice == "1") cout << "Фамилия Имя: " << this->LnameFname << endl;
    else if (choice == "2") cout << "Знак зодиака: " << this->sign << endl;
    else if (choice == "3") cout << "День рождения: " << this->birthday << endl;
    else if (choice == "4") cout << "Фамилия Имя: " << this->LnameFname << "Знак зодиака: " << this->sign << "День рождения: " << this->birthday << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}

// метод доступа к дню рождения
string Sign::GetBirthday()
{
    return this->birthday;
}

// метод доступа к фамилии имя
string Sign::GetLname()
{
    return this->LnameFname;
}

// метод вставки значения
void Sign::Set()
{
    cin >> *this;
}

// метод изменения значений
void Sign::Change()
{
    string choice;

    try
    {
        cout << "Что хотите изменить?" <<
                "1 - Фамилия Имя" <<
                "2 - Знак зодиака" <<
                "3 - День рождения" << endl;
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

    getline(cin, choice); // обнуляем поток ввода

    if (choice == "1")
    {
        cout << "Фамилия Имя: ";
        cin >> this->LnameFname;
    }
    else if (choice == "2")
    {
        cout << "Знак зодиака: ";
        cin >> this->sign;
    }
    else if (choice == "3")
    {
        cout << "День рождения: ";
        cin >> this->birthday;
    }
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}

ostream &operator<< (ostream &stream, Sign s) // перегрузка оператора извлеченния
{
    stream << "Все поля класса:" << endl;
    stream << s.LnameFname << endl;
    stream << s.sign << endl;
    stream << s.birthday << endl;

    return stream;
}

istream &operator>> (istream &stream, Sign &s) // перегрузка оператора вставки
{
    cout << "Вставка значений:" << endl;
    cout << "Фамилия имя: ";
    stream >> s.LnameFname;
    cout << "Знак зодиака: ";
    stream >> s.sign;
    cout << "День рождения: ";
    stream >> s.birthday;
    string buf;
    getline(stream, buf); // обнуляем поток ввода
    return stream;
}
