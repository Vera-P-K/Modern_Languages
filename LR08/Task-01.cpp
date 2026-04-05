// класс и методы его реализации объединены в один файл
#include <iostream>
#include <cstring>

using namespace std;

class Stroka {
    char str[80]; // Поле для хранения строки (максимум 79 символов + '\0')

public:
    // Конструкторы
    Stroka(const char* string) { strcpy(str, string); } // Из обычной строки
    Stroka() { str[0] = '\0'; }                         // По умолчанию (пустая)
    Stroka(const Stroka& s) { strcpy(str, s.str); }    // Копирования

    // Оператор присваивания
    Stroka& operator=(const Stroka& s) {
        if (this != &s) strcpy(str, s.str); // Копируем данные, если адреса разные
        return *this; // Возвращаем ссылку на текущий объект
    }

    // Оператор сложения (конкатенация)
    Stroka& operator+(const Stroka& s) {
        strcat(str, s.str); // Приклеиваем строку s к текущей
        return *this;       // Возвращаем измененный объект
    }

    // Оператор сравнения
    int operator==(const Stroka& s) {
        return strcmp(str, s.str) == 0; // 1 если равны, 0 если нет
    }

    // Метод получения длины
    int dlina() { return strlen(str); }

    // --- ПЕРЕГРУЗКА ОПЕРАТОРОВ ВВОДА И ВЫВОДА ---

    // Оператор помещения в поток (вывод <<)
    // friend дает функции доступ к закрытому полю str
    friend ostream& operator<<(ostream& os, const Stroka& s) {
        os << s.str; // Записываем строку в поток вывода
        return os;   // Возвращаем поток для цепочек (cout << a << b)
    }

    // Оператор извлечения из потока (ввод >>)
    friend istream& operator>>(istream& is, Stroka& s) {
        is >> s.str; // Считываем слово из потока ввода в массив str
        return is;   // Возвращаем поток для цепочек (cin >> a >> b)
    }
};

int main() {
    // Создаем объекты
    Stroka s1("qwert"), s3, s4(s1), s5;

    cout << "Vvedite stroku s3: ";
    cin >> s3; // Используем перегруженный оператор >>

    s3 = "asdfg"; // Присваивание
    cout << "s3 = " << s3 << endl; // Используем перегруженный оператор <<

    // Склеиваем строки. Вопрос по работе оператора (?)
    s5 = s1 + s3 + s4; 
    
    cout << "dlina s5 = " << s5.dlina() << endl;
    cout << "s5 = " << s5 << endl; // Вывод объекта s5 напрямую

    // Сравнение
    if (s1 == s5)
        cout << "stroki s1 i s5 ravny" << endl;
    else if (s1 == s4)
        cout << "stroki s1 i s4 ravny" << endl;

    return 0;
}
