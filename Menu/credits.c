#include <stdio.h>
#include "../list.h"
#include "../console.h"
#include "index.h"

void credits() {
    gotoxy(60,12);
    setColor(COLOR_YELLOW);
    printf("CR%cDITOS", 144);
    for(int x=59; x<69; x++) {
        setColor(COLOR_DARKGREY);
        gotoxy(x,13);
        printf("%c", 196);
    }

    //TECLAS
    setColor(COLOR_LIGHTGREEN);
    gotoxy(50,15);
    printf("Disciplina:");
    setColor(COLOR_WHITE);
    gotoxy(62,15);
    printf("Estrutura de Dados");
    setColor(COLOR_LIGHTBLUE);
    gotoxy(52,17);
    printf("Professor:");
    setColor(COLOR_WHITE);
    gotoxy(63,17);
    printf("Thiago Waltrik");
    for(int x=59; x<69; x++) {
        setColor(COLOR_DARKGREY);
        gotoxy(x,19);
        printf("%c", 196);
    }
    setColor(COLOR_LIGHTRED);
    gotoxy(40,21);
    printf("Alunos/Criadores:");
    setColor(COLOR_WHITE);
    gotoxy(58,21);
    printf("Paulo Zaneripe, Ramon Vasconcelos");
    for(int x=59; x<69; x++) {
        setColor(COLOR_DARKGREY);
        gotoxy(x,23);
        printf("%c", 196);
    }
    setColor(COLOR_WHITE);
    gotoxy(39,25);
    printf("Instituto Federal de Santa Catarina (Campus Tubar%co)", 198);
    setColor(COLOR_DARKGREY);
    gotoxy(45,37);
    printf("Pressione qualquer tecla para voltar...");
    menu = 0;
}
