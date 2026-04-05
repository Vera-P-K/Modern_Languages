#include <iostream>
#include <cstring>

using namespace std;

// --- ШАБЛОН КЛАССА СТЕК ---
template <class T>
class Tstack {
protected:
    int numItem; // Текущее количество элементов в стеке
    T *item;     // Указатель на массив элементов
public:
    // Конструктор: выделяет динамическую память под размер size
    Tstack(size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }
    // Деструктор: освобождает выделенную память
    ~Tstack() {
        delete[] item;
    }
    // Метод добавления в стек
    void push(T t) {
        item[numItem++] = t;
    }
    // Метод извлечения из стека
    T pop() {
        return item[--numItem];
    }
    // Проверка, пуст ли стек (нужно для логики вывода из тупика)
    bool isEmpty() {
        return numItem == 0;
    }
};

int main() {
    // Массив вагонов в исходном составе (номера в случайном порядке)
    int train[] = {3, 1, 2}; 
    int n = sizeof(train) / sizeof(train[0]);
    
    // Создаем "тупик" на базе шаблона стека
    Tstack<int> tupik(n);
    
    // Ожидаемый номер следующего вагона на выходе (сортируем 1, 2, 3...)
    int nextExpected = 1;

    cout << "Исходный состав: 3, 1, 2" << endl;
    cout << "Начало сортировки..." << endl;

    for (int i = 0; i < n; i++) {
        // Если номер вагона не тот, который мы ждем на выходе — отправляем в тупик
        if (train[i] != nextExpected) {
            cout << "Вагон " << train[i] << " отправлен в тупик." << endl;
            tupik.push(train[i]);
        } else {
            // Если это нужный вагон — он проезжает мимо тупика сразу на выход
            cout << "Вагон " << train[i] << " поехал на выход." << endl;
            nextExpected++;       
        }
    }

    // Выводим все оставшиеся вагоны из тупика
    while (!tupik.isEmpty()) {
        int v = tupik.pop();
        cout << "Вагон " << v << " выехал из тупика" << endl;
    }

    return 0;
}
