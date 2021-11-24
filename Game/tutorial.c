#include <stdio.h>
#include "../console.h"

int t = 0;

void tutorial() {
        if(t == 0){
            gotoxy(57,15);
            setColor(COLOR_GREY);
            printf("Instru%c%ces:", 135, 228);
            gotoxy(33,17);
            setColor(COLOR_WHITE);
            printf("Acerte o meio do alvo em movimento at%c completar seu", 130);
            gotoxy(86,17);
            setColor(COLOR_LIGHTBLUE);
            printf("Objetivo");
            gotoxy(94,17);
            setColor(COLOR_WHITE);
            printf("!");
            gotoxy(33,19);
            setColor(COLOR_DARKGREY);
            printf("Caso se esgotem as balas, uma muni%c%co colet%cvel ser%c lan%cada.", 135, 198, 160, 160, 135);
            gotoxy(42,37);
            printf("Pressione qualquer tecla para continuar...");
            invisibleSystemPause();
            clearScreen();
            t = 1;
        }
}
