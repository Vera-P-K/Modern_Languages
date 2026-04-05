#include <iostream> // Стандартная библиотека ввода-вывода (без .h)

using namespace std; // Использование пространства имен std

class Money {
    long dollars; // Поле для хранения долларов
    int cents;    // Поле для хранения центов

public:
    Money() : dollars(0), cents(0) { } // Конструктор по умолчанию с инициализацией
    Money(long d, int c) : dollars(d), cents(c) { } // Конструктор с параметрами

    // Оператор сравнения "больше" (const гарантирует, что метод не меняет объект)
    int operator>(const Money& amt) const;

    // Дружественная функция для вывода в поток (cout << obj)
    friend ostream& operator<<(ostream& os, const Money& amt);
};

// Реализация оператора сравнения
int Money::operator>(const Money& amt) const {
    // Возвращает true, если долларов больше ИЛИ долларов поровну, но центов больше
    return (dollars > amt.dollars) || ((dollars == amt.dollars) && (cents > amt.cents));
}

// Реализация оператора вывода
ostream& operator<<(ostream& os, const Money& amt) {
    // Форматированный вывод в виде $19.10
    os << "$" << amt.dollars << "." << (amt.cents < 10 ? "0" : "") << amt.cents;
    return os;
}

// Реализация функции сортировки (метод пузырька)
void Sort(Money mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1]) { // Используем перегруженный оператор >
                Money temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

int main() { // void main заменено на int main по стандарту
    // Инициализация массива объектов Money
    Money mas[] = {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };

    int n = sizeof(mas) / sizeof(mas[0]); // Вычисление количества элементов

    Sort(mas, n); // Вызов функции сортировки

    // Цикл вывода отсортированного массива
    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }

    return 0; // Успешное завершение программы
}
