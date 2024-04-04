#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname) // створення файлу з введених рядків
{
    ofstream fout(fname); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    string s; // введений користувачем рядок
    do
    {
        cin.get(); // очищуємо буфер клавіатури – щоб не було символу
        cin.sync(); // "кінець рядка", який залишився після вводу числа
        cout << "enter line: "; getline(cin, s); // ввели рядок
        fout << s << endl; // записали його у файл
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}

void PrintTXT(char* fname) {
    ifstream fin(fname); // відкрили файл для зчитування
    string s; // прочитаний рядок
    while (getline(fin, s)) { // поки можна прочитати рядок
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
    fin.close(); // закриваємо файл після виведення
}

bool ContainsThreeConsecutiveStars(const char* filename) {
    ifstream fin(filename); // відкрили файл для зчитування
    string line; // рядок з файлу

    while (getline(fin, line)) { // читаємо файл по рядках
        size_t found = line.find("***"); // шукаємо групу з трьох зірочок

        if (found != string::npos) { // якщо знайдено
            fin.close(); // закриваємо файл
            return true; // повертаємо true
        }
    }
    fin.close(); // закриваємо файл
    return false; // якщо не знайдено, повертаємо false
}

int main() {
    char filename[100]; // ім'я файлу
    cout << "Enter the name of the file: ";
    cin.getline(filename, 100); // отримуємо ім'я файлу від користувача

    CreateTXT(filename); // створюємо файл з введеними рядками
    cout << "Content of the file:" << endl;
    PrintTXT(filename); // виводимо вміст файлу на екран

    if (ContainsThreeConsecutiveStars(filename)) {
        cout << "The file contains a group of three consecutive stars '*'." << endl;
    } else {
        cout << "The file does not contain a group of three consecutive stars '*'." << endl;
    }

    return 0;
}
