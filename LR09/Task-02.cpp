// первоначальный вариант:
#include <iostream.h>
template <class T>
T getmax(T t1, T t2) //Возвращает больший из двух
{ //параметров
return t1 > t2?t1:t2)
}
template <class T>
T getmax (T t[], size_t size)
{
T retval = t[0];
int i;
for(i = 0; i < size; i++)
if(t[i] > retval) retval = t[i];
return retval;
}
void main (void) 
{
int i1 = 3, i2 = 5; 
int mas[] = {3, 9, 5, 8};
cout << “max int = ” << getmax (i1, i2) << endl;
cout << “max int = ”;
cout << getmax (sizeof (mas)/sizeof (mas[0]))<< endl;
}

// новый вариант:
#include <iostream> // Стандартная библиотека ввода-вывода (без .h)

using namespace std; // Использование пространства имен std

// 1. Шаблон функции для поиска большего из двух значений
template <class T>
T getmax(T t1, T t2) {
    // Используем тернарный оператор: если t1 > t2, вернуть t1, иначе t2
    return (t1 > t2) ? t1 : t2; 
}

// 2. Шаблон функции для поиска максимума в массиве
template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0]; // Предполагаем, что первый элемент — максимальный
    for (size_t i = 1; i < size; i++) { // Итерируемся по массиву
        if (t[i] > retval) {
            retval = t[i]; // Если нашли элемент больше, обновляем максимум
        }
    }
    return retval; // Возвращаем итоговое значение
}

int main() { // void main заменено на int main
    int i1 = 3, i2 = 5; 
    int mas[] = {3, 9, 5, 8}; 

    // Вызов первой версии getmax (для двух чисел)
    cout << "max int = " << getmax(i1, i2) << endl;

    // Вычисляем размер массива
    size_t n = sizeof(mas) / sizeof(mas[0]);

    // Вызов второй версии getmax (для массива)
    // В параметрах передаем сам массив и его размер
    cout << "max in array = " << getmax(mas, n) << endl;

    return 0; // Успешное завершение
}
