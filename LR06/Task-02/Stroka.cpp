#include "Stroka.h" // Подключаем описание нашего класса

using namespace std; // Чтобы не писать std:: перед cin и cout

// Конструктор: копирует переданный текст в массив str
Stroka::Stroka(const char *string) {
    strcpy(str, string);
}

// Конструктор по умолчанию: записывает в начало массива символ конца строки
Stroka::Stroka() {
    str[0] = '\0';
}

// Конструктор копирования: копирует строку из другого объекта Stroka
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str);
}

// Оператор присваивания: копирует текст и возвращает ссылку на текущий объект (*this)
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {         // Проверка, чтобы не копировать самого себя
        strcpy(str, s.str);
    }
    return *this;             // Возвращаем объект для цепочек типа s1 = s2 = s3
}

// Оператор сложения: добавляет строку s в конец текущей строки (strcat)
Stroka& Stroka::operator+(const Stroka& s) { 
    strcat(str, s.str);
    return *this;             // Возвращает измененный объект
}

// Оператор сравнения: strcmp возвращает 0, если строки совпали
int Stroka::operator==(const Stroka& s) {
    if (strcmp(str, s.str) == 0) return 1; // Возвращаем 1 (истина)
    else return 0;                         // Возвращаем 0 (ложь)
}

// Возвращает длину строки через стандартную функцию strlen
int Stroka::dlina() {
    return strlen(str);
}

// Считывает текст из стандартного потока ввода
void Stroka::vvod() {
    cin >> str;
}

// Выводит текст в стандартный поток вывода
void Stroka::vyvod() {
    cout << str;
}
