#include <iostream>
using namespace std;

int main() {
    int mas[] = {2, 5, -8, 1, -4, 6, 4, -5, -9, 12, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);
    int i, j, imin;

    // Сортировка выбором (Selection Sort)
    for (i = 0; i < n - 1; i++) {
        imin = i; // Предполагаем, что текущий элемент — минимальный
        
        for (j = i + 1; j < n; j++) {
            if (mas[j] < mas[imin]) {
                imin = j; // Нашли элемент еще меньше
            }
        }

        // Меняем местами найденный минимум и текущий элемент mas[i]
        int t = mas[i];
        mas[i] = mas[imin];
        mas[imin] = t;
    }

    // Вывод результата
    for (i = 0; i < n; i++) cout << mas[i] << " ";
    
    return 0;
}
