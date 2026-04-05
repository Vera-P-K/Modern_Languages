#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.txt", "r");   // Открытие файла для чтения
    FILE *out = fopen("output.txt", "w"); // Создание файла для результата
    
    if (!in || !out) { // Если какой-то файл не открылся, то выход
        printf("Ошибка с файлами!\n");
        return 1;
    }

    char line[256];      // Буфер для хранения текущей строки
    char pageNum[16];    // массив, где хранятся цифры номера страницы
    int hasPage = 0;     // Флаг: нашелся ли номер в начале страницы

    // Чтение файла построчно
    while (fgets(line, sizeof(line), in)) {
        
        // Проверка, есть ли в строке номер страницы 
        // Если это начало файла, то эта строка — первая на странице
        if (strstr(line, "-") != NULL && (hasPage == 0)) {
            int k = 0;
            // Считывает только цифры из строки 
            for (int i = 0; line[i] != '\0'; i++) {
                if (isdigit(line[i])) {
                    pageNum[k++] = line[i];
                }
            }
            pageNum[k] = '\0'; // Завершает строку с номером
            hasPage = 1;       // Счетчик номеров страниц
            continue;          // Пропуск печати этой строки (перенос)
        }

        
    // 2. Если файл закончился, а номер последней страницы еще не напечатан
    if (hasPage) {
        fprintf(out, "\n%s\n", pageNum);
    }

    fclose(in);  // Закрывает файлы
    fclose(out);
    printf("Итог в файле output.txt\n");
    return 0;
}
