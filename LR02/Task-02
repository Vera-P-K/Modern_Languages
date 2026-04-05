#include <iostream>  // Библиотека для ввода-вывода (cout)
#include <iomanip>   // Библиотека для форматирования вывода (setw)
#include <cmath>     // Библиотека для математических функций (fabs)
#include <limits>    // Библиотека для работы с пределами типов (в данном коде не используется, но полезна)

using namespace std; // Использование стандартного пространства имен (чтобы не писать std::)

#define N 5          // Определение константы N — размерность квадратной матрицы 5x5

// --- Глобальные Минимумы / Максимумы ---

// Функция поиска минимального элемента во всей матрице
float get_min_matrix(float m[N][N]) {
    float res = m[0][0]; // Берем самый первый элемент за начальный минимум
    for(int i=0; i<N; i++) // Цикл по строкам
        for(int j=0; j<N; j++) // Цикл по столбцам
            if(m[i][j] < res) res = m[i][j]; // Если нашли меньше — обновляем
    return res; // Возвращаем результат
}

// Функция поиска максимального элемента во всей матрице
float get_max_matrix(float m[N][N]) {
    float res = m[0][0]; // Берем начальный максимум
    for(int i=0; i<N; i++) 
        for(int j=0; j<N; j++) 
            if(m[i][j] > res) res = m[i][j]; // Если нашли больше — обновляем
    return res;
}

// --- Треугольные части (Минимумы и Максимумы) ---

// Поиск максимума в нижней треугольной части (включая главную диагональ: j <= i)
float get_max_lower(float m[N][N]) {
    float res = m[0][0];
    for(int i=0; i<N; i++) 
        for(int j=0; j<=i; j++) // j идет только до индекса строки i
            if(m[i][j] > res) res = m[i][j];
    return res;
}

// Поиск минимума в нижней треугольной части
float get_min_lower(float m[N][N]) {
    float res = m[0][0];
    for(int i=0; i<N; i++) 
        for(int j=0; j<=i; j++) 
            if(m[i][j] < res) res = m[i][j];
    return res;
}

// Поиск максимума в верхней треугольной части (j >= i)
float get_max_upper(float m[N][N]) {
    float res = m[0][0];
    for(int i=0; i<N; i++) 
        for(int j=i; j<N; j++) // j начинается от индекса строки i
            if(m[i][j] > res) res = m[i][j];
    return res;
}

// Поиск минимума в верхней треугольной части
float get_min_upper(float m[N][N]) {
    float res = m[0][0];
    for(int i=0; i<N; i++) 
        for(int j=i; j<N; j++) 
            if(m[i][j] < res) res = m[i][j];
    return res;
}

// --- Диагонали ---

// Поиск минимума на главной диагонали (индексы i == j)
float get_min_main_diag(float m[N][N]) {
    float res = m[0][0];
    for(int i=1; i<N; i++) // Проходим одним циклом по m[i][i]
        if(m[i][i] < res) res = m[i][i];
    return res;
}

// Поиск максимума на главной диагонали
float get_max_main_diag(float m[N][N]) {
    float res = m[0][0];
    for(int i=1; i<N; i++) 
        if(m[i][i] > res) res = m[i][i];
    return res;
}

// Поиск минимума на второстепенной диагонали (индексы j = N - 1 - i)
float get_min_side_diag(float m[N][N]) {
    float res = m[0][N-1]; // Начальное значение — правый верхний угол
    for(int i=1; i<N; i++) 
        if(m[i][N-1-i] < res) res = m[i][N-1-i];
    return res;
}

// Поиск максимума на второстепенной диагонали
float get_max_side_diag(float m[N][N]) {
    float res = m[0][N-1];
    for(int i=1; i<N; i++) 
        if(m[i][N-1-i] > res) res = m[i][N-1-i];
    return res;
}

// --- Средние значения и Суммы треугольников ---

// Расчет среднего арифметического всей матрицы
float get_avg_matrix(float m[N][N]) {
    float s = 0;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) s += m[i][j]; // Суммируем всё
    return s / (N * N); // Делим на общее число элементов (25)
}

// Вычисление сумм и средних для треугольных областей
void get_triangle_sums_and_avgs(float m[N][N]) {
    float s_low = 0, s_up = 0;
    int count = (N * N + N) / 2; // Формула количества элементов в треугольнике
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(j <= i) s_low += m[i][j]; // Сумма нижнего
            if(j >= i) s_up += m[i][j];  // Сумма верхнего
        }
    }
    cout << "Sum Lower: " << s_low << " (Avg: " << s_low/count << ")\n";
    cout << "Sum Upper: " << s_up << " (Avg: " << s_up/count << ")\n";
}

// --- Строки и Столбцы ---

// Анализ каждой строки и каждого столбца отдельно
void analyze_rows_cols(float m[N][N]) {
    cout << "\n[ROWS] Sum | Min | Max | Avg\n";
    for(int i=0; i<N; i++) {
        float s=0, mi=m[i][0], ma=m[i][0];
        for(int j=0; j<N; j++) {
            s += m[i][j]; // Накапливаем сумму строки
            if(m[i][j] < mi) mi = m[i][j]; // Ищем мин в строке
            if(m[i][j] > ma) ma = m[i][j]; // Ищем макс в строке
        }
        cout << "R" << i << ": " << s << " | " << mi << " | " << ma << " | " << s/N << endl;
    }

    cout << "\n[COLS] Sum | Min | Max | Avg\n";
    for(int j=0; j<N; j++) {
        float s=0, mi=m[0][j], ma=m[0][j];
        for(int i=0; i<N; i++) {
            s += m[i][j]; // Накапливаем сумму столбца
            if(m[i][j] < mi) mi = m[i][j]; // Ищем мин в столбце
            if(m[i][j] > ma) ma = m[i][j]; // Ищем макс в столбце
        }
        cout << "C" << j << ": " << s << " | " << mi << " | " << ma << " | " << s/N << endl;
    }
}

// Нахождение элемента, значение которого ближе всего к среднему по матрице
float get_closest_to_avg(float m[N][N]) {
    float avg = get_avg_matrix(m);
    float closest = m[0][0];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            // Сравниваем абсолютную разницу (модуль)
            if(fabs(m[i][j] - avg) < fabs(closest - avg)) closest = m[i][j];
        }
    }
    return closest;
}

int main() {
    float m[N][N];
    // Заполнение матрицы случайными числами от 0 до 99
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) m[i][j] = (rand() % 100) / 1.0f;

    // Вывод получившейся матрицы в виде таблицы
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cout << setw(6) << m[i][j]; // setw(6) задает ширину колонки
        cout << endl;
    }

    // Вызов всех функций обработки и вывод результатов в консоль
    cout << "\nMatrix Min/Max: " << get_min_matrix(m) << " / " << get_max_matrix(m);
    cout << "\nLower Tri Min/Max: " << get_min_lower(m) << " / " << get_max_lower(m);
    cout << "\nUpper Tri Min/Max: " << get_min_upper(m) << " / " << get_max_upper(m);
    cout << "\nMain Diag Min/Max: " << get_min_main_diag(m) << " / " << get_max_main_diag(m);
    cout << "\nSide Diag Min/Max: " << get_min_side_diag(m) << " / " << get_max_side_diag(m);
    cout << "\nAvg Matrix: " << get_avg_matrix(m);
    cout << "\nClosest to Avg: " << get_closest_to_avg(m) << endl;
    
    get_triangle_sums_and_avgs(m);
    analyze_rows_cols(m);

    return 0; // Завершение программы
}
