#include <iostream>

using namespace std;

int main() {
    int mas[] = {10, 5, 8, 1, 4, 6, 4, 5, 9, 12, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);
    
    int N1, N2;
    cout << "Vvedite N1 i N2 (ot 0 do " << n - 1 << "): ";
    cin >> N1 >> N2;

    // Проверка корректности границ
    if (N1 < 0) N1 = 0;
    if (N2 >= n) N2 = n - 1;

    // Сортировка выбором (мини-макс) на интервале [N1, N2]
    for (int i = N1; i < N2; i++) {
        int imin = i; // Предполагаем, что текущий элемент минимальный
        
        for (int j = i + 1; j <= N2; j++) {
            if (mas[j] < mas[imin]) {
                imin = j; // Нашли индекс элемента поменьше
            }
        }

        // Обмен значениями (Swap)
        if (imin != i) {
            int t = mas[i];
            mas[i] = mas[imin];
            mas[imin] = t;
        }
    }

    // Вывод всего массива для проверки
    cout << "Rezultat: " << endl;
    for (int i = 0; i < n; i++) {
        if (i == N1) cout << "[ "; // Визуальное выделение начала интервала
        cout << mas[i] << " ";
        if (i == N2) cout << "] "; // Визуальное выделение конца интервала
    }
    cout << endl;

    return 0;
}
