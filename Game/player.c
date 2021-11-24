#include <stdio.h>
#include "../list.h"
#include "../console.h"
#include "player.h"

Player p;

void hat() {
    setColor(COLOR_BROWN);
    gotoxy(p.x-2,p.y-2);
    printf("%c", p.body[0]);
    for(int i =-1; i<2; i++) {
        gotoxy(p.x+i,p.y-2);
        printf("%c", p.body[1]);
    }
    gotoxy(p.x+2,p.y-2);
    printf("%c", p.body[0]);
}

void head() {
    setColor(COLOR_WHITE);
    for(int i =-1; i<2; i++) {
        gotoxy(p.x+i,p.y-1);
        printf("%c", p.body[1]);
    }
}

void arms() {
    setColor(COLOR_CYAN);
    gotoxy(p.x-2,p.y);
    printf("%c", p.body[0]);
    gotoxy(p.x-1,p.y);
    printf("%c", p.body[3]);
    gotoxy(p.x,p.y);
    printf("%c", p.body[1]);
    gotoxy(p.x+1,p.y);
    printf("%c", p.body[3]);
    gotoxy(p.x+2,p.y);
    printf("%c", p.body[0]);
    gotoxy(p.x+3,p.y);
    printf("%c", p.body[0]);
}

void gun() {
    setColor(COLOR_DARKGREY);
    gotoxy(p.x+4,p.y);
    printf("%c", p.body[4]);
    gotoxy(p.x+5,p.y);
    printf("%c", p.body[5]);
}

void hands() {
    setColor(COLOR_CYAN);
    gotoxy(p.x-2,p.y+1);
    printf("%c", p.body[2]);
    gotoxy(p.x,p.y+1);
    printf("%c", p.body[1]);
}

void legs() {
    setColor(COLOR_BROWN);
    gotoxy(p.x-2,p.y+2);
    printf("%c", p.body[0]);
    gotoxy(p.x-1,p.y+2);
    printf("%c", p.body[1]);
    gotoxy(p.x+1,p.y+2);
    printf("%c", p.body[1]);
    gotoxy(p.x+2,p.y+2);
    printf("%c", p.body[0]);
}

void printPlayer() {
    hat();head();arms();gun();hands();legs();
}

void clearPlayer(int bufferX,int bufferY) {
    for(int p = -2; p < 3; p++) {
        for(int i = -2; i < 3; i++) {
            gotoxy(bufferX + i,bufferY + p);
            printf(" ");
        }
    }
    gotoxy(bufferX+3,bufferY);
    printf(" ");
    gotoxy(bufferX+4,bufferY);
    printf(" ");
    gotoxy(bufferX+5,bufferY);
    printf(" ");
}
