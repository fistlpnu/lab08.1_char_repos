#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s) {
    int count = 0;
    char* t;
    while ((t = strstr(s, "OGO")) || (t = strstr(s, "AGA"))) {
        count++;
        s = t + 1; // Переміщаємо покажчик на наступний символ
    }
    return count;
}

char* Change(char* s) {
    char* result = new char[strlen(s) * 2]; // Виділяємо пам'ять з запасом
    result[0] = '\0'; // Очищаємо результатний рядок
    char* t = result; // Покажчик для заповнення нового рядка
    char* p;
    while ((p = strstr(s, "OGO")) || (p = strstr(s, "AGA"))) {
        // Додаємо частину рядка до збігу
        strncat(t, s, p - s);
        // Додаємо "***" замість "OGO" або "AGA"
        strcat(t, "***");
        t += strlen(t);
        // Зміщуємо покажчик на символ після збігу
        s = p + 3;
    }
    // Додаємо залишок рядка
    strcat(t, s);
    strcpy(s, result);
    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    // Підрахунок трійок "OGO" або "AGA"
    cout << "String contained " << Count(str) << " groups of \"OGO\" or \"AGA\"." << endl;
    // Заміна трійок на "***"
    char* modifiedStr = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << modifiedStr << endl;
    // Звільняємо виділену пам'ять
    delete[] modifiedStr;
    return 0;
}
