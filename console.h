#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ENTER_KEY 13
#define SPACE_KEY 32
#define ESC_KEY 27

char key, detectedKey;

enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARKGREY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTCYAN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
};

void setWindow(int Width, int Height);
void gotoxy(int x, int y);
void setBackgroundColor(int c);
void setColor(int ForgC);
void readKeyboard();
void hideCursor();
void removeScrollbar();
void invisibleSystemPause();
void longPause();
void longerPause();
void clearScreen();
