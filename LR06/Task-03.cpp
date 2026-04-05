#include <iostream>

using namespace std;

// ---  ФУНКЦИИ РАБОТЫ СО СТРОКАМИ ---

// 1. Определение длины строки (аналог strlen)
int my_strlen(const char* s) {
    int i = 0;
    while (s[i] != '\0') i++; // Считаем символы, пока не встретим нулевой байт
    return i;
}

// 2. Копирование строки (аналог strcpy)
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i]; // Копируем посимвольно
        i++;
    }
    dest[i] = '\0'; // Обязательно ставим символ конца строки
}

// 3. Конкатенация (склеивание) строк (аналог strcat)
void my_strcat(char* dest, const char* src) {
    int i = 0;
    while (dest[i] != '\0') i++; // Находим конец первой строки
    int j = 0;
    while (src[j] != '\0') {
        dest[i + j] = src[j]; // Дописываем вторую строку в конец первой
        j++;
    }
    dest[i + j] = '\0'; // Завершаем новую длинную строку
}

// 4. Сравнение строк (аналог strcmp)
int my_strcmp(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]) i++; // Идем, пока символы равны
    return (unsigned char)s1[i] - (unsigned char)s2[i]; // Возвращаем разницу (0 если равны)
}

// --- КЛАСС STROKA ---

class Stroka {
    char str[80]; // Массив для хранения символов (макс 79 + '\0')

public:
    // Конструктор: копирует текст в массив объекта
    Stroka(const char* string) {
        my_strcpy(str, string);
    }

    // Конструктор по умолчанию: пустая строка
    Stroka() {
        str[0] = '\0';
    }

    // Конструктор копирования
    Stroka(const Stroka& s) {
        my_strcpy(str, s.str);
    }

    // Оператор присваивания
    Stroka& operator=(const Stroka& s) {
        if (this != &s) { // Защита от самоприсваивания
            my_strcpy(str, s.str);
        }
        return *this;
    }

    // Оператор сцепления (изменяет левый операнд)
    Stroka& operator+(const Stroka& s) {
        my_strcat(str, s.str);
        return *this;
    }

    // Оператор сравнения
    int operator==(const Stroka& s) {
        if (my_strcmp(str, s.str) == 0) return 1;
        else return 0;
    }

    // Метод получения длины
    int dlina() {
        return my_strlen(str);
    }

    // Ввод строки (до первого пробела)
    void vvod() {
        cin >> str;
    }

    // Вывод строки
    void vyvod() {
        cout << str;
    }
};

// --- ГЛАВНАЯ ФУНКЦИЯ ---

int main() {
    // Инициализация объектов
    Stroka s1("qwert"), s3, s4(s1), s5;

    cout << "Vvedite s3: ";
    s3.vvod();

    s3 = "asdfg"; // Присваивание
    cout << "s3 = "; s3.vyvod(); cout << endl;

    // Сложение (s1 изменится после выполнения s1+s3)
    s5 = s1 + s3 + s4; 
    
    cout << "Dlina s5 = " << s5.dlina() << endl;
    cout << "s5 = "; s5.vyvod(); cout << endl;

    // Сравнение объектов
    if (s1 == s5) cout << "s1 и s5 ravny" << endl;
    else if (s1 == s4) cout << "s1 и s4 НЕ ravny (tak kak s1 izmenilas')" << endl;

    return 0;
}
