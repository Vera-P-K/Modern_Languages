#include <stdio.h>
#include <string.h> // Для работы с функцией strstr (поиск подстроки)

// Функция поиска: принимает файл для чтения, файл для записи и искомую строку
void find_string(FILE *in, FILE *out, const char *target) {
    char line[1024]; // Буфер для хранения одной строки из файла
    int line_num = 1; // Счетчик строк для отчета

    // fgetc читает файл построчно, пока не дойдет до конца
    while (fgets(line, sizeof(line), in)) {
        // strstr ищет target внутри строки line. Если находит — возвращает адрес совпадения
        if (strstr(line, target) != NULL) {
            // Записываем в выходной файл номер строки и саму строку с совпадением
            fprintf(out, "Найдено в строке %d: %s", line_num, line);
        }
        line_num++; // Переходим к следующему номеру
    }
}

int main(void) {
    char name[50], target[50]; // Имена файлов и искомое слово
    FILE *in, *out;

    printf("Введите имя файла для поиска: ");
    scanf("%49s", name);
    printf("Что искать?: ");
    scanf("%49s", target);

    // Открываем исходный файл на чтение ("r")
    if ((in = fopen(name, "r")) == NULL) {
        return printf("Ошибка открытия %s\n", name), 1;
    }

    // Создаем/открываем файл result.txt на запись ("w") для итогов
    if ((out = fopen("result.txt", "w")) == NULL) {
        fclose(in); // Закрываем первый файл перед выходом
        return printf("Ошибка создания файла результатов\n"), 1;
    }

    // Вызываем функцию поиска
    find_string(in, out, target);

    printf("Поиск завершен. Результаты в файле result.txt\n");

    fclose(in);  // Освобождаем входной файл
    fclose(out); // Сохраняем и закрываем файл результатов
    return 0;
}
