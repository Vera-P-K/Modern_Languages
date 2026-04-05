#include <iostream>  // Без .h
#include <iomanip>   // Без .h
#include <cstdlib>   // Вместо stdlib.h для rand()
#include <conio.h>   // Можно оставить для getch() , если выполняется в Windows/Visual Studio

using namespace std; // Добавлено пространство имен

#define N 5

int main() // void main переформатирована в int main
{
    float m[N][N];
    int i, j;

    // Заполнение массива
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) { 
            m[i][j] = rand() / 10.0f;
        }
    }

    // Вывод массива
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            // setw и setprecision работают правильно, 
            cout << setw(8) << setprecision(5) << m[i][j];
        }
        cout << endl; 
    }

    getch(); 
    return 0;
}
