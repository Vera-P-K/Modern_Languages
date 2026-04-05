#include <iostream>

using namespace std;

// 1. Передача по значению (копия) — значения в main не изменятся
void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Передача по указателю — значения изменятся
void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Передача по ссылке — значения изменятся (самый удобный способ в C++)
void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 2, b = 5;

    cout << "Do obmena: a=" << a << " b=" << b << endl;

    // Вызов 1: ничего не изменится
    obmen1(a, b);
    cout << "Posle obmena 1: a=" << a << " b=" << b << endl;

    // Вызов 2: передаем адреса переменных через &
    obmen2(&a, &b);
    cout << "Posle obmena 2: a=" << a << " b=" << b << endl;

    // Вызов 3: передаем переменные как обычно, ссылка создастся сама
    obmen3(a, b);
    cout << "Posle obmena 3: a=" << a << " b=" << b << endl;

    return 0;
}
