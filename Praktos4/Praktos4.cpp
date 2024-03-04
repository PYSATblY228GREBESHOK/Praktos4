#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <cstdlib>


using namespace std;

string reverse(const string& word) {
    string reversed = word;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

string removeVowels(const std::string& str) {
    string vowels = "AEIOUaeiouАЕЁИОУЫЭЮЯаеёиоуыэюя";
    string result = str;
    result.erase(std::remove_if(result.begin(), result.end(), [&](char c) {
        return vowels.find(c) != std::string::npos; }),
        result.end());
    return result;
}
string removeConsonants(const std::string& str) {
    string consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyzБВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфхцчшщ";
    string result = str;
    result.erase(std::remove_if(result.begin(), result.end(), [&](char c) {
        return consonants.find(c) != std::string::npos; }),
        result.end());
    return result;
}
string shuffle(const string& word) {
    string shuffled = word;
    random_shuffle(shuffled.begin(), shuffled.end());
    return shuffled;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    string word;
    cout << "Введите слово: ";
    getline(cin, word);

    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Слово выводится задом наперед.\n";


        cout << "2. Вывести слово без гласных.\n";
        cout << "3. Вывести слово без согласных.\n";
        cout << "4. Рандомно раскидывать буквы заданного слова.\n";
        cout << "5. Выйти из программы.\n";

        int choice;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Результат: " << reverse(word) << endl;
            break;
        case 2:
            cout << "Результат: " << removeVowels(word) << endl;
            break;
        case 3:
            cout << "Результат: " << removeConsonants(word) << endl;
            break;
        case 4:
            cout << "Результат: " << shuffle(word) << endl;
            break;
        case 5:
            cout << "До свидания!\n";
            return 0;
        default:
            cout << "Неверный ввод. Пожалуйста, выберите число от 1 до 5.\n";
        }
    }

    return 0;
}