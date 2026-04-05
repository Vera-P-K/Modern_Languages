#include <iostream> // Исправлено: iostream.h -> iostream
#include <cmath>    // Для использования pow()

int main() { // Исправлено: void main (viod) -> int main()
    int base, exp;
    long long k; // Для больших степеней испльзую long long

    // Запрос основания у пользователя
    std::cout << "Введите основание: ";
    std::cin >> base;
    
    std::cout << "Введите максимальную степень: ";
    std::cin >> exp;

    for (int i = 0; i <= exp; i++) { 
        // Использование функции pow из cmath или собственной функции
        k = 1;
        for(int j=0; j<i; j++) k *= base; 
        
        std::cout << "Основание " << base << "^" << i << " = " << k << std::endl;
    }

    return 0;
}
