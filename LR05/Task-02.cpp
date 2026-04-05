#include <stdio.h>
#include <ctype.h> // Подключаем для функции isprint()

int main(void) {
    char name[50], ch; // Массив для имени и переменная для символа
    int printable = 0, non_printable = 0; // Счетчики символов
    FILE *in;

    printf("Введите имя файла: ");
    scanf("%49s", name);

    // Открываем файл для чтения ("r")
    if ((in = fopen(name, "r")) == NULL) {
        return printf("Ошибка открытия %s\n", name), 1; 
    }

    // Читаем файл посимвольно до конца (EOF)
    while ((ch = getc(in)) != EOF) {
        putchar(ch); // Выводим символ на экран

        // Проверяем: если символ отображаемый (буквы, цифры, знаки)
        if (isprint((unsigned char)ch)) {
            printable++; // Увеличиваем счетчик "непустых"
        } else {
            non_printable++; // Увеличиваем счетчик "пустых" (управляющих)
        }
    }

    // Вывод статистики
    printf("\n\nСтатистика:\n");
    printf("Отображаемых (непустых): %d\n", printable);
    printf("Скрытых (пустых/управляющих): %d\n", non_printable);

    fclose(in); // Закрываем файл
    return 0;
}
