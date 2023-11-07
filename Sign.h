#include <iostream>
#include <string.h>
using namespace std;

class Sign
{
private:
    string FnameLname; // фамилия имя
    string sign; // знак зодиака
    string birthday; // день рождения

public:
    Sign(); // конструктор по умолчанию
    Sign(string FnameLname, string sign, string birthday); // конструктор с параметром
    Sign(const Sign &s); // конструктор копирования
    ~Sign(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод доступа к полям
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Sign s); // перегрузка оператора извлеченния
    friend iostream &operator>> (istream &stream, Sign &s); // перегрузка оператора вставки
};
