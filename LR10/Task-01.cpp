//
#include <iostream>

using namespace std;

// Структура узла ОДНОСВЯЗНОГО списка
struct Node {
    int d;          // Данные
    Node *next;     // Указатель только на СЛЕДУЮЩИЙ элемент
};

// Прототипы функций
Node* first(int d);
void add(Node **pend, int d);
Node* find(Node* const pbeg, int d);
int remove(Node **pbeg, Node **pend, int key);
void insert(Node* pbeg, Node **pend, int key, int d);

int main() {
    // 1. Формирование первого элемента
    Node *pbeg = first(1); 
    Node *pend = pbeg; // В начале начало и конец совпадают

    // 2. Добавление в конец элементов 2, 3, 4, 5
    for (int i = 2; i < 6; i++) add(&pend, i);

    // 3. Вставка числа 200 после числа 2
    insert(pbeg, &pend, 2, 200);

    // 4. Удаление числа 5
    if (!remove(&pbeg, &pend, 5)) cout << "Не найден" << endl;

    // 5. Вывод списка на экран
    Node *pv = pbeg;
    while (pv) {
        cout << pv->d << " ";
        pv = pv->next; // Переход к следующему
    }

    return 0;
}

// Создание первого узла
Node* first(int d) {
    Node *pv = new Node; // Выделяем память
    pv->d = d;           // Записываем данные
    pv->next = nullptr;  // Следующего нет
    return pv;
}

// Добавление в конец (используем указатель на указатель pend, чтобы обновить его)
void add(Node **pend, int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    (*pend)->next = pv; // Текущий последний теперь указывает на новый
    *pend = pv;         // Обновляем адрес конца списка
}

// Поиск узла по значению
Node* find(Node* const pbeg, int d) {
    Node *pv = pbeg;
    while (pv) {
        if (pv->d == d) return pv; // Нашли — возвращаем адрес
        pv = pv->next;
    }
    return nullptr;
}

// Удаление элемента
int remove(Node **pbeg, Node **pend, int key) {
    Node *curr = *pbeg;
    Node *prev = nullptr;

    // Ищем узел и запоминаем предыдущий 
    while (curr && curr->d != key) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) return 0; // Не нашли

    if (curr == *pbeg) { // Если удаляем голову
        *pbeg = (*pbeg)->next;
    } else { // Если удаляем в середине или конце
        prev->next = curr->next; // "Перепрыгиваем" удаляемый узел
        if (curr == *pend) *pend = prev; // Обновляем хвост, если удалили последний
    }

    delete curr; // Освобождаем память
    return 1;
}

// Вставка после элемента с ключом key
void insert(Node* pbeg, Node **pend, int key, int d) {
    Node *pkey = find(pbeg, key); // Ищем, после кого вставить
    if (pkey) {
        Node *pv = new Node;
        pv->d = d;
        pv->next = pkey->next; // Новый узел указывает на того, на кого указывал старый
        pkey->next = pv;       // Старый узел теперь указывает на новый
        if (pkey == *pend) *pend = pv; // Если вставили в самый конец, обновляем pend
    }
}
