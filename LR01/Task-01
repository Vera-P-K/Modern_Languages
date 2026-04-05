#include <iostream> // 1. Исправлено: iostream.h -> iostream
#include <cmath>    // Для работы с функциями степени, если нужно

// 2. Исправлено: void main -> int main
int main() 
{
    int i, k;
    int power(int, int); // Прототип функции

    for (i = 0; i < 10; i++)
    {
        k = power(2, i);                
        
        // 3. Исправлены "cout" -> "std::cout", "endl" -> "std::endl"
        std::cout << "i = " << i << ", k = " << k << std::endl;
    }
    return 0;
}

// 4. Исправлена функция для возведения в степень
int power(int x, int n)
{
    int i, p = 1;
    // Добавлена проверка: 2^0 = 1, поэтому цикл должен корректно обрабатывать n=0
    for (i = 0; i < n; i++) p *= x; 
    return p;
}
