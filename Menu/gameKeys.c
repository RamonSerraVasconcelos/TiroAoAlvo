#include <stdio.h>
#include "../list.h"
#include "../console.h"
#include "index.h"

void gameKeys() {
    gotoxy(60,12);
    setColor(COLOR_YELLOW);
    printf("TECLADO");
    for(int x=59; x<68; x++) {
        setColor(COLOR_DARKGREY);
        gotoxy(x,13);
        printf("%c", 196);
    }

    //TECLAS
    setColor(COLOR_WHITE);
    gotoxy(59,15);
    printf("/%c = Cima ", 92);
    gotoxy(58,17);
    printf("%c/ = Baixo ", 92);
    gotoxy(58,19);
    printf("%c = Esquerda ", 60);
    gotoxy(58,21);
    printf("%c = Direita ", 62);
    gotoxy(57,23);
    printf("%c%c%c%c = Atirar ", 192, 196, 196, 217);
    gotoxy(58,25);
    printf("ESC = Menu");
    setColor(COLOR_DARKGREY);
    gotoxy(45,37);
    printf("Pressione qualquer tecla para voltar...");
    menu = 0;
}
