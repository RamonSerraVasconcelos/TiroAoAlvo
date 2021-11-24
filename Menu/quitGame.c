#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include "../console.h"
#include "../list.h"
#include "../borders.h"
#include "../Game/target.h"


void quitGame() {
    system("@cls||clear");
    setColor(COLOR_WHITE);
    gotoxy(54,17);
    printf("Jogo Finalizado! ");
    usleep(999999);
    usleep(500000);
    system("@cls||clear");
    setColor(COLOR_DARKGREY);
    freeAllBorders();
    exit(0);
}
