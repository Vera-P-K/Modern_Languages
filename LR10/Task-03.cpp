//
#include <iostream>
#include <string>

using namespace std;

// 1. Структура данных об автобусе
struct Bus {
    int number;          // Номер автобуса
    string driver;       // Фамилия и инициалы водителя
    int route;           // Номер маршрута

    // Оператор для удобного вывода данных об автобусе
    friend ostream& operator<<(ostream& os, const Bus& b) {
        os << "[N" << b.number << " | " << b.driver << " | Маршрут: " << b.route << "]";
        return os;
    }
};

// 2. Узел списка (шаблонный)
template <typename T>
struct Node {
    T data;
    Node* next;
};

// 3. Класс "Список автобусов"
template <typename T>
class BusList {
private:
    Node<T>* head;
public:
    BusList() { head = nullptr; }

    // Добавление в начало списка
    void add(T item) {
        Node<T>* newNode = new Node<T>{item, head};
        head = newNode;
    }

    // Поиск и удаление автобуса по его номеру
    // Возвращает true, если автобус найден и извлечен в переменную outItem
    bool extract(int busNum, T& outItem) {
        Node<T>* curr = head;
        Node<T>* prev = nullptr;

        while (curr != nullptr) {
            if (curr->data.number == busNum) { // Если номер совпал
                outItem = curr->data;          // Копируем данные для переноса
                if (prev == nullptr) head = curr->next; // Если это первый элемент
                else prev->next = curr->next;           // Если элемент в середине/конце
                delete curr;                            // Удаляем узел из памяти
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false; // Автобус не найден
    }

    // Вывод всех автобусов из списка
    void showAll(string title) {
        cout << "\n--- " << title << " ---" << endl;
        Node<T>* curr = head;
        if (!curr) cout << "Список пуст." << endl;
        while (curr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

int main() {
    BusList<Bus> inPark;   // Список автобусов в парке
    BusList<Bus> onRoute;  // Список автобусов на маршруте

    // Начальное формирование данных 
    inPark.add({101, "Иванов И.П.", 15});
    inPark.add({202, "Сорокин А.Ю.", 42});
    inPark.add({303, "Извозчиков П.С.", 10});

    int choice, num;
    Bus tempBus;

    while (true) {
        cout << "\n1. Выезд из парка\n2. Въезд в парк\n3. Список в парке\n4. Список на маршруте\n0. Выход\n: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                cout << "Номер для въезда: "; cin >> num;
                if (inPark.extract(num, tempBus)) { // Забираем из парка
                    onRoute.add(tempBus);           // Отправляем на маршрут
                    cout << "Автобус N" << num << " уехал по маршруту." << endl;
                } else cout << "Такой номер маршрута отсутствует." << endl;
                break;
            case 2:
                cout << "Номер прибытия: "; cin >> num;
                if (onRoute.extract(num, tempBus)) { // Забираем с маршрута
                    inPark.add(tempBus);             // Возвращаем в парк
                    cout << "Автобус N" << num << " вернулся в парк." << endl;
                } else cout << "Этого автобуса нет на маршруте" << endl;
                break;
            case 3:
                inPark.showAll("Автобусы в парке");
                break;
            case 4:
                onRoute.showAll("Автобусы на маршруте");
                break;
        }
    }
    return 0;
}
