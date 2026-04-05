#include <iostream>  // Для ввода-вывода (cout, cin)
#include <cstring>   // Для стандартных функций работы с C-строками (strlen, strcpy)

using namespace std; // Чтобы не писать std:: перед каждым стандартным именем

class MyString {
private:
    char* data; // Указатель на массив символов в динамической памяти (куче)
    int length; // Переменная для хранения текущего количества символов

public:
    // 1. Конструктор по умолчанию: создает пустую строку
    MyString() {
        length = 0;           // Длина равна нулю
        data = new char[1];   // Выделяем 1 байт памяти
        data[0] = '\0';       // Записываем туда признак конца строки
    }

    // 2. Конструктор из обычной строки 
    MyString(const char* s) {
        length = strlen(s);          // Считаем длину входящей строки
        data = new char[length + 1]; // Выделяем память (длина + 1 байт для '\0')
        strcpy(data, s);             // Копируем символы в нашу память
    }

    // 3. Конструктор копирования: вызывается при MyString s2 = s1
    MyString(const MyString& other) {
        length = other.length;       // Берем длину оригинала
        data = new char[length + 1]; // Резервируем память под копию
        strcpy(data, other.data);    // Копируем данные из оригинала в новый объект
    }

    // 4. Деструктор: вызывается автоматически при удалении объекта
    ~MyString() {
        delete[] data; // Освобождение памяти во избежание утечек
    }

    // Метод для получения длины строки без изменения объекта
    int getLength() const {
        return length;
    }

    // Перегрузка оператора присваивания (=)
    MyString& operator=(const MyString& other) {
        if (this != &other) {          // Проверка: не присваиваем ли мы строку самой себе
            delete[] data;             // Удаляем старое содержимое
            length = other.length;     // Устанавливаем новую длину
            data = new char[length + 1]; // Выделяем новую память
            strcpy(data, other.data);  // Копируем данные
        }
        return *this;                  // Возвращаем текущий объект для цепочек (a = b = c)
    }

    // Перегрузка оператора сложения (+) для сцепления строк
    MyString operator+(const MyString& other) {
        // Создаем временный буфер достаточного размера
        char* temp = new char[length + other.length + 1];
        strcpy(temp, data);       // Копируем первую часть
        strcat(temp, other.data); // Приклеиваем вторую часть
        
        MyString result(temp);    // Создаем новый объект на основе склеенной строки
        delete[] temp;            // Удаляем временный буфер
        return result;            // Возвращаем результат
    }

    // Перегрузка оператора сравнения (==)
    bool operator==(const MyString& other) const {
        // strcmp возвращает 0, если строки полностью идентичны
        return strcmp(data, other.data) == 0;
    }

    // «Дружественная» функция вывода (позволяет писать cout << s1)
    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.data; // Выводим внутренний массив символов в поток
        return os;    // Возвращаем поток для дальнейшего вывода
    }

    // «Дружественная» функция ввода (позволяет писать cin >> s1)
    friend istream& operator>>(istream& is, MyString& s) {
        char buf[1024];        // Временный буфер для ввода с клавиатуры
        is >> buf;             // Считываем слово в буфер
        s = MyString(buf);     // Обновляем строку через конструктор и оператор =
        return is;
    }
};

int main() {
    MyString s1("Добрый "); // Сработал конструктор из char*
    MyString s2("вечер");
    MyString s3;          // Сработал конструктор по умолчанию

    s3 = s1 + " " + s2;   // Склеивание (+) и присваивание (=)

    cout << "Stroka: " << s3 << endl;       // Вывод (<<)
    cout << "Dlina: " << s3.getLength() << endl; // Длина

    if (s1 == s2) cout << "Equal" << endl;  // Сравнение (==)
    else cout << "Different" << endl;

    return 0; // Конец программы
}
