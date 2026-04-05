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
    if (N1 > N2) { int t = N1; N1 = N2; N2 = t; } // На случай, если перепутали порядок

    // Сортировка выбором (мини-макс) на убывание
    for (int i = N1; i < N2; i++) {
        int imax = i; // Поиск МАКСИМАЛЬНОГО индекса
        
        for (int j = i + 1; j <= N2; j++) {
            // Измененный знак сравнения для убывания
            if (mas[j] > mas[imax]) { 
                imax = j; 
            }
        }

        // Обмен значениями (Swap)
        if (imax != i) {
            int t = mas[i];
            mas[i] = mas[imax];
            mas[imax] = t;
        }
    }

    // Вывод массива
    cout << "Rezultat (po ubyvaniu na intervale): " << endl;
    for (int i = 0; i < n; i++) {
        if (i == N1) cout << "[ "; 
        cout << mas[i] << " ";
        if (i == N2) cout << "] "; 
    }
    cout << endl;

    return 0;
}
