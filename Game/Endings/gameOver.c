#include <stdio.h>
#include <windows.h>
#include "../../list.h"
#include "../../console.h"
#include "../../borders.h"
#include "../../Menu/index.h"
#include "../difficulty.h"
#include "../target.h"
#include "../ammo.h"

void gameOver() {
    menu = 0;
    difficulty = 0;
    freeFloorBorder();
    listFree(target);
    listFree(collectableAmmo);
    system("@cls||clear");
    gotoxy(57,16);
    setColor(COLOR_LIGHTRED);
    printf("FIM DE JOGO");
    gotoxy(53,18);
    setColor(COLOR_WHITE);
    printf("O TEMPO SE ESGOTOU!");
    longerPause();
    setColor(COLOR_DARKGREY);
    gotoxy(42,37);
    printf("Pressione qualquer tecla para continuar...");
    invisibleSystemPause();
}
