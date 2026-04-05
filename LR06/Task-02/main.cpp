#include "Stroka.h" // Подключаем наш класс
#include <iostream>

using namespace std;

int main() {        // Точка входа в программу
    // Создаем s1 с текстом, s3 — пустую, s4 — копию s1, s5 — пустую
    Stroka s1("qwert"), s3, s4(s1), s5;

    s3.vvod();      // Просим пользователя ввести строку для s3
    s3 = "asdfg";   // Используем оператор присваивания (создается временный объект и копируется)
    s3.vyvod();     // Выводим s3
    cout << endl;   // Перенос строки

    // Склеиваем s1, s3 и s4 в одну длинную строку и записываем в s5
    s5 = s1 + s3 + s4; 
    
    cout << "dlina s5 = " << s5.dlina() << endl; // Печатаем длину s5
    s5.vyvod();     // Печатаем содержимое s5
    cout << endl;

    // Сравниваем строки через оператор ==
    if (s1 == s5)
        cout << "stroki s1 i s5 ravny" << endl;
    else if (s1 == s4)
        cout << "stroki s1 i s4 ravny" << endl;

    return 0;       // выход
}
