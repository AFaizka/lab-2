#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

void TextScaner()
{
    setlocale(LC_CTYPE, "Russian");
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        wcout << L"Ошибка открытия файла!" << endl;
        exit(0);
    }

    string line; // строка для хранения текущей строки из файла
    queue<string> questionQueue;    // очередь для строк с вопросительным знаком
    queue<string> exclamationQueue; // очередь для строк с восклицательным знаком

    while (getline(file, line)) // читаем файл построчно
    {
        if (!line.empty()) {
            char lastChar = line.back(); // последний символ в строке

            // Условие для добавления строки в нужную очередь
            if (lastChar == '?' && isupper(line[0])) {
                questionQueue.push(line);
            } else if (lastChar == '!') {
                exclamationQueue.push(line);
            }
        }
    }

    file.close(); // закрываем файл

    // Сначала выводим строки со знаком вопроса
    wcout << L"Строки со знаком вопроса:" << endl;
    while (!questionQueue.empty())
    {
        cout << questionQueue.front() << endl;
        questionQueue.pop();
    }

    // Затем выводим строки со знаком восклицания
    wcout << L"Строки со знаком восклицания:" << endl;
    while (!exclamationQueue.empty())
    {
        cout << exclamationQueue.front() << endl;
        exclamationQueue.pop();
    }
}
