#include <iostream>
#include <cstring> // Аналог string.h в C++

using namespace std;

int main() {
    char s1[50] = "Hello"; // Создаем массив s1 с запасом места (50 байт)
    char s2[] = "World";   // Создаем массив s2, размер определится автоматически

    // 1. strlen() — возвращает количество символов в строке (без \0)
    cout << "Dlina s1: " << strlen(s1) << endl; 

    // 2. strcmp() — сравнивает строки. Возвращает 0, если строки идентичны
    if (strcmp(s1, s2) != 0) {
        cout << "Stroki raznye" << endl;
    }

    // 3. strcpy(куда, откуда) — копирует содержимое s2 в s1 (заменяет старое)
    strcpy(s1, s2); 
    cout << "s1 posle kopirovaniya: " << s1 << endl;

    // 4. strcat(куда, что) — добавляет строку в конец другой строки
    strcat(s1, "!"); 
    cout << "Rezultat strcat: " << s1 << endl;

    return 0;
}
