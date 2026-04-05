//
#include <iostream>

using namespace std;

// 1. Шаблон структуры "Узел"
template <typename T>
struct Node {
    T data;         // Данные, хранящиеся в узле (тип T)
    Node* next;     // Указатель на следующий узел в списке
};

// 2. Шаблон класса "Односвязный список"
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Указатель на начало (голову) списка
    int size;       // Текущее количество элементов в списке

public:
    // Конструктор: создает пустой список
    LinkedList() {
        head = nullptr; // В начале список пуст, головы нет
        size = 0;       // Размер равен нулю
    }

    // Деструктор: очищает память при удалении объекта списка
    ~LinkedList() {
        clear(); // Вызываем метод полной очистки
    }
}
