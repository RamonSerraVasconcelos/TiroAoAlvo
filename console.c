#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include "console.h"
#include "borders.h"

void setWindow(int Width, int Height) {
    COORD coord;
    coord.X = Width;
    coord.Y = Height;

    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setBackgroundColor(int c) {
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)c) << 4)); // Background colors take up the second-least significant byte
#else
    RLUTIL_PRINT(getANSIBackgroundColor(c));
#endif
}

void setColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void readKeyboard() {
    if(kbhit()) { // se houve toque no teclado
        key = getch(); // armazena tecla pressionada
        detectedKey = 1;
    }
}

void hideCursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
   return;
}

void removeScrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void invisibleSystemPause() {
    setColor(COLOR_BLACK);
    setBackgroundColor(COLOR_BLACK);
    gotoxy(60,0);
    system("pause");
    return;
}

void longPause() {
    usleep(99999);
    usleep(99999);
    usleep(99999);
}

void longerPause() {
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
    usleep(99999);
}

void clearScreen() {
    system("@cls||clear");
    setColor(COLOR_DARKGREY);
    printBorders();
}
