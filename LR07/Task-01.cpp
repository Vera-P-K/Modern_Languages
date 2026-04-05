#include <graphics.h> // Аналог Graph
#include <conio.h>    // Аналог Crt (getch, kbhit)
#include <stdlib.h>   // Для rand() и randomize()
#include <dos.h>      // Для delay()

// Базовый класс Точка
class point {
public:
    int x, y;       // Координаты
    int cvet;       // Цвет

    // Инициализация данных
    void init(int xn, int yn, int color) {
        x = xn; y = yn; cvet = color;
    }

    virtual void show() {} // Виртуальная функция прорисовки
    virtual void hide() {} // Виртуальная функция скрытия

    // Получение текущих координат
    void locat(int &xl, int &yl) {
        xl = x; yl = y;
    }

    // Логика перемещения объекта
    void fly(int cost) {
        int xx, yy;
        show(); // Показать объект первый раз
        
        do {
            locat(xx, yy); // Берем текущую позицию
            
            // Случайное смещение по X в пределах экрана
            do {
                xx = x + (int)(( (double)rand() / RAND_MAX - 0.5 ) * cost);
            } while (xx <= 0 || xx >= getmaxx());

            // Случайное смещение по Y в пределах экрана
            do {
                yy = y + (int)(( (double)rand() / RAND_MAX - 0.5 ) * cost);
            } while (yy <= 0 || yy >= getmaxy());

            hide();      // Стираем в старом месте
            x = xx; y = yy; // Обновляем координаты
            show();      // Рисуем в новом месте
            delay(300);  // Задержка (мерцание)
        } while (!kbhit()); // Пока не нажата клавиша
        getch(); // Очистка буфера клавиатуры
    }
};

// Класс Круг (наследуется от Точки)
class krug : public point {
public:
    int radius;

    void init(int xn, int yn, int r, int color) {
        point::init(xn, yn, color);
        radius = r;
        show();
    }

    void show() {
        setcolor(cvet);           // Установить цвет контура
        setfillstyle(1, cvet);    // Сплошная заливка
        fillellipse(x, y, radius, radius); // Рисуем закрашенный круг
    }

    void hide() {
        setcolor(getbkcolor());        // Цвет фона
        setfillstyle(1, getbkcolor()); // Заливка цветом фона
        fillellipse(x, y, radius, radius);
    }
};

// Класс Кольцо (наследуется от Круга)
class ring : public krug {
public:
    int width;

    void init(int xn, int yn, int r, int color, int wid) {
        width = wid;
        krug::init(xn, yn, r, color);
    }

    void show() {
        krug::show(); // Рисуем внешний круг
        setfillstyle(1, getbkcolor()); // Стиль заливки цветом фона
        fillellipse(x, y, radius - width, radius - width); // Рисуем отверстие
    }
};

int main() {
    int d = DETECT, r;
    initgraph(&d, &r, (char*)""); // Инициализация графики

    setbkcolor(8); // Установка цвета фона

    krug testkrug;
    ring testring;

    // Инициализация и запуск объектов
    testkrug.init(150, 40, 50, 1);
    testring.init(450, 80, 90, 10, 15);

    testkrug.fly(100);
    testring.fly(60);

    getch(); // Пауза
    testkrug.hide();
    testring.hide();

    closegraph(); // Закрытие графического режима
    return 0;
}
