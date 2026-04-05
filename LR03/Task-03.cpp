#include <iostream>

using namespace std;

int main() {
    int mas[] = {2, 5, -8, 1, -4, 6, 4, -5, -9, 12, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);

    for (int i = 0; i < n - 1; i++) {
        int target_idx = i;

        for (int j = i + 1; j < n; j++) {
            // Если текущий элемент i - ЧЕТНЫЙ
            if (mas[i] % 2 == 0) {
                // Ищем минимальное среди ЧЕТНЫХ (сортировка по возрастанию)
                if (mas[j] % 2 == 0 && mas[j] < mas[target_idx]) {
                    target_idx = j;
                }
            } 
            // Если текущий элемент i - НЕЧЕТНЫЙ
            else {
                // Ищем максимальное среди НЕЧЕТНЫХ (сортировка по убыванию)
                if (mas[j] % 2 != 0 && mas[j] > mas[target_idx]) {
                    target_idx = j;
                }
            }
        }

        // Обмен (только если нашли подходящий элемент другого индекса)
        if (target_idx != i) {
            int t = mas[i];
            mas[i] = mas[target_idx];
            mas[target_idx] = t;
        }
    }

    // Вывод результата
    cout << "Sorted (Even UP, Odd DOWN): " << endl;
    for (int i = 0; i < n; i++) cout << mas[i] << " ";
    cout << endl;

    return 0;
}
