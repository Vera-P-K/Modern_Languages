// первоначальный вариант
#include <iostream.h> ’
#include <string.h>
template <class T>
'T getmax(T t1, T t2) //Возвращает больший из двух
{ //параметров
return t1 > t2?t1:t2;
}
char* getmax (char s1, char s2){ .
return strcmp (sl, s2) >0? s1: s2;
}
template <class T>
T getmax(T t[], size_t size)
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
char *s1 = “строка1”;
char *s2 = “строка2”;
cout << “max int =” << getmax (i1, i2) << endl;
cout << “max str = ” << getmax (s1, s2) << endl;
}

//второй вариант:
#include <iostream> // Стандартный ввод-вывод
#include <cstring>  // Для функции strcmp

using namespace std; // Использование пространства имен std

// 1. Универсальный шаблон для базовых типов (int, double и т.д.)
template <class T>
T getmax(T t1, T t2) {
    // Возвращает t1, если оно больше t2, иначе t2
    return (t1 > t2) ? t1 : t2;
}

// 2. Специальная версия функции специально для C-строк (char*)
// Она перекрывает шаблон, когда передаются указатели на символы
const char* getmax(const char* s1, const char* s2) {
    // strcmp возвращает > 0, если первая строка больше по алфавиту
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

// 3. Шаблон для поиска максимума в массиве любого типа
template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0]; // Берем первый элемент за стартовый максимум
    for (size_t i = 1; i < size; i++) { // Цикл со второго элемента
        if (t[i] > retval) retval = t[i]; // Обновляем, если нашли больше
    }
    return retval; // Возвращаем итоговый максимум
}

int main() { // void main заменено на стандартный int main
    int i1 = 3, i2 = 5;
    const char* s1 = "строка1"; // Используем const для строковых литералов
    const char* s2 = "строка2";

    // Вызов шаблона для целых чисел
    cout << "max int = " << getmax(i1, i2) << endl;

    // Вызов специальной версии для строк (сравнение по алфавиту)
    cout << "max str = " << getmax(s1, s2) << endl;

    return 0;
}
