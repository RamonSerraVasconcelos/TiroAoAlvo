#include <stdio.h>
#include <windows.h>
#include "../../list.h"
#include "../../console.h"
#include "../../borders.h"
#include "../../Menu/index.h"
#include "../difficulty.h"
#include "../target.h"
#include "../ammo.h"

void gameWon() {
        menu = 0;
        freeFloorBorder();
        listFree(target);
        listFree(collectableAmmo);
        system("@cls||clear");
        gotoxy(57,14);
        setColor(COLOR_YELLOW);
        printf("PARAB%cNS!", 144);
        gotoxy(44,16);
        setColor(COLOR_WHITE);
        printf("VOC%c COMPLETOU SEU OBJETIVO A TEMPO!", 210);
        gotoxy(47,18);
        setColor(COLOR_DARKGREY);
        printf("JOGO CONCLU%cDO NA DIFICULDADE: ", 214);
        switch(difficulty) {
            case 1:
                gotoxy(59,20);
                setColor(COLOR_LIGHTGREEN);
                printf("F%cCIL", 181);
                break;
            case 2:
                gotoxy(58,20);
                setColor(COLOR_CYAN);
                printf("NORMAL");
                break;
            case 3:
                gotoxy(58,20);
                setColor(COLOR_LIGHTRED);
                printf("DIF%cCIL", 214);
                break;
        }
        difficulty = 0;
        longerPause();
        setColor(COLOR_DARKGREY);
        gotoxy(42,37);
        printf("Pressione qualquer tecla para continuar...");
        invisibleSystemPause();
}
