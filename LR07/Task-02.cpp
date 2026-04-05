// часть с добавлением новых функций
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

class point {
public:
    int x, y, cvet;
    void init(int xn, int yn, int color) { x = xn; y = yn; cvet = color; }
    virtual void show() {}
    virtual void hide() {}
    
    // Обновленный метод fly с изменением цвета и формы
    void fly(int cost) {
        int xx, yy;
        show();
        do {
            // 1. Меняем цвет фигуры на случайный при каждом шаге
            cvet = rand() % 15 + 1; 
            
            xx = x + (int)(((double)rand() / RAND_MAX - 0.5) * cost);
            yy = y + (int)(((double)rand() / RAND_MAX - 0.5) * cost);

            // Проверка границ экрана
            if (xx > 0 && xx < getmaxx() && yy > 0 && yy < getmaxy()) {
                hide();     // Стираем старую фигуру
                x = xx; y = yy;
                show();     // Рисуем обновленную фигуру (новый цвет/сектор)
                delay(100); // Пауза для плавности
            }
        } while (!kbhit()); // Цикл пока не нажата клавиша
        getch();
    }
};

class ring : public point {
public:
    int radius, width, s_angle; // s_angle - угол выреза
    bool expanding;             // Флаг: расширяем или сужаем сектор

    void init(int xn, int yn, int r, int color, int wid) {
        point::init(xn, yn, color);
        radius = r; width = wid;
        s_angle = 10;           // Начальный угол выреза
        expanding = true;       // Начинаем с расширения
    }

    // Метод отрисовки с динамическим сектором
    void show() {
        setcolor(cvet);
        setfillstyle(1, cvet);
        
        // Рисуем сектор вместо целого круга
        // Вырез будет от 0 до s_angle градусов
        pieslice(x, y, s_angle, 360, radius); 

        // Рисуем "дырку" внутри (кольцо)
        setfillstyle(1, getbkcolor());
        pieslice(x, y, 0, 360, radius - width);

        // Логика изменения угла (сужение/расширение)
        if (expanding) s_angle += 5; else s_angle -= 5;
        if (s_angle >= 90 || s_angle <= 0) expanding = !expanding;
    }

    void hide() {
        setcolor(getbkcolor());
        setfillstyle(1, getbkcolor());
        pieslice(x, y, 0, 360, radius + 1); // Стираем всю область
    }
};

int main() {
    int d = DETECT, r;
    initgraph(&d, &r, (char*)"");
    
    ring testring;
    testring.init(300, 200, 80, 4, 20);
    testring.fly(50); // Запуск движения с трансформацией

    closegraph();
    return 0;
}
