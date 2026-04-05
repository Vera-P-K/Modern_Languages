//1.
ifstream (const char *name, int omode = ios: :in, int prot = filebuf::openprot) ;
ofstream (const char *name, int omode = ios::out, int prot = filebuf::openprot),
ifstream const char *name, int omode, int prot = filebuf::openprot);

* ifstream(int f); ofstream(int f); fstream(int f);

ifstream(int f, char *b, int len);
ofstream(int f, char *b, int len); .

fstream(int f, char *b, int len);

//2.

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <ctype.h>
void main (void)

char fname[15], c;
cout << "Введите имя исходного файла";
cin >> fname;
// Открыли входной файл
ifstream ifs (fname);
if( !ifs) // Проверяем поток

cout << "Не открыт входной файл" << fname;

cout << "Введите имя выходного файла";
cin >> fname;

//Открытие выходного файла
ofstream ofs (fname);
if( !ofs) // Проверяем поток
{

cout << "Не открыт выходной файл" << fname;

// Пока не произойдет ошибки, делаем:
while (ifs && ofs)
{

ifs.get(c); // Чтение символа из файла

// Переводим прочитанный символ в

// верхний регистр

¢ = toupper(c);

ofs.put(c); // Запись символа в файл

cout <<’.’;

cout <<endl
<< "Выходной файл является копией"
<< "входного файла"
<< "в верхнем регистре";

//3.

#include <iostream.h>

#include <fstream.h>

#include <stdlib.h>

itn main (void)

{
char name[12];
fstream fin; // Неоткрытый объект-поток
cout << "Введите имя файла: ";
cin >> name;

// Открыли входной поток

fin.open (name, ios::in);
if(fin) // Проверяем состояние потока
{

cout << “Файл открыт << name << endl;
Sfin.close(); //Закрываем файл
}

else

{
cout <<"Не открыт выходной файл"
<< name << endl;

return 0;
}

// актуализированный вариант

#include <iostream>  // Для ввода-вывода в консоль (cin, cout)
#include <fstream>   // Для работы с файловыми потоками (ifstream, ofstream)
#include <cctype>    // Для функции toupper (обработка символов)
#include <string>    // Для удобной работы с именами файлов

using namespace std; // Используем стандартное пространство имен

int main() { // Стандартный заголовок главной функции
    string in_name, out_name; // Переменные для имен файлов (динамический размер)
    char c; // Буфер для одного символа

    // --- БЛОК 1: ВВОД ИМЕН И ОТКРЫТИЕ ---
    cout << "Введите имя исходного файла: ";
    cin >> in_name;

    // Создаем объект входного потока и открываем файл
    ifstream ifs(in_name); 
    if (!ifs.is_open()) { // Проверка: удалось ли открыть файл
        cerr << "Ошибка: не открыт входной файл " << in_name << endl;
        return 1; // Выход с кодом ошибки
    }

    cout << "Введите имя выходного файла: ";
    cin >> out_name;

    // Создаем объект выходного потока
    ofstream ofs(out_name);
    if (!ofs.is_open()) {
        cerr << "Ошибка: не открыт выходной файл " << out_name << endl;
        return 1;
    }

    // --- БЛОК 2: ПОСИМВОЛЬНАЯ ОБРАБОТКА ---
    // Читаем символ, пока не достигнем конца файла (EOF)
    // ifs.get(c) возвращает поток, который приводится к false в конце файла
    while (ifs.get(c)) {
        // toupper переводит символ в верхний регистр (нужно приведение к unsigned char)
        c = (char)toupper((unsigned char)c);
        
        // Записываем обработанный символ в выходной файл
        ofs.put(c);
        
        // Визуальная индикация процесса (точка на каждый символ)
        cout << '.';
    }

    // --- БЛОК 3: ЗАВЕРШЕНИЕ ---
    cout << "\n Файл обработан." << endl;

    // Потоки закрываются автоматически при выходе из функции, 
    // но явное закрытие — хороший тон для управления ресурсами.
    ifs.close();
    ofs.close();

    return 0; // Успешное завершение
}
