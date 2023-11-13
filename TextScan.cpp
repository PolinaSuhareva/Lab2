#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void TextScaner()
{
    fstream file;
    file.open("Text.txt");

    if (!file.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string line;
        string word;
        string maxWord = "";
        unsigned short int maxLen = 0;

        while (!file.eof())
        {
            getline(file, line);
            for (int id = 0; id < line.size()+1; id++)
            {
                if (line[id] == ' ' || line[id] == '.' || line[id] == ',' || line[id] == '!' || line[id] == '?' || line[id] == ';' ||
                    line[id] == '"' || line[id] == '\'' || line[id] == '\n' || line[id] == '\0')
                {
                    if (word.size() > maxLen) {maxLen = word.size(); maxWord = word;}
                    word = "";
                }
                else word += line[id];
            }
        }

        file.clear();
        file.seekg(0); // переводим курсор в начало файла

        unsigned short countWord = 0;

        while (!file.eof())
        {
            getline(file, line);
            for (int id = 0; id < line.size()+1; id++)
            {
                if (line[id] == ' ' || line[id] == '.' || line[id] == ',' || line[id] == '!' || line[id] == '?' || line[id] == ';' ||
                    line[id] == '"' || line[id] == '\'' || line[id] == '\n' || line[id] == '\0')
                {
                    if (word == maxWord) countWord++;
                    word = "";
                }
                else word += line[id];
            }
        }

        cout << "Самое длинное слово: " << maxWord << " | Его длина = " << maxWord.size()/2 << " | Оно встретилось: " << countWord << endl;
    }

    file.close();
}
