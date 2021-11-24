#include <stdio.h>
#include <windows.h>
#include "../list.h"
#include "../console.h"
#include "index.h"
#include "bullet.h"
#include "target.h"
#include "player.h"

List* target;

void insertTarget() {
    target = createList();

    target = push(target, 223, 119, 12);
    target = push(target, 219, 119, 13);
    target = push(target, 220, 119, 14);
}

void topTarget(int bufferY) {
    setColor(COLOR_LIGHTRED);
    gotoxy(119,Y(target,1)-1);
    printf("%c", symbol(target,0));
    gotoxy(119,bufferY-1);
    printf(" ");
}

void middleTarget(int bufferY) {
    setColor(COLOR_WHITE);
    gotoxy(119,Y(target,1));
    printf("%c", symbol(target,1));
}

void bottomTarget(int bufferY) {
    setColor(COLOR_LIGHTRED);
    gotoxy(119,Y(target,1)+1);
    printf("%c", symbol(target,2));
    gotoxy(119,bufferY+1);
    printf(" ");
}

void updateTarget() {
    int bufferY = 0;
    if(firedBullet != 1) {
        bufferY = 0;
        if(targetLimit == 0) {
            bufferY = Y(target,1);
            addY(target,1,1);
            if(Y(target,1) == 34) {
                targetLimit = 1;
            }
        }else if(targetLimit == 1) {
            bufferY = Y(target,1);
            addY(target,1,-1);
            if(Y(target,1) == 3) {
                targetLimit = 0;
            }
        }
        topTarget(bufferY);
        bottomTarget(bufferY);
        middleTarget(bufferY);
    }
}

void almost(int symbol) {
    Beep(300,10);
    Beep(200,10);
    gotoxy(57,4);
    setColor(COLOR_LIGHTRED);
    printf("QUAAASE!\n");
    setColor(COLOR_RED);
    gotoxy(X(bullet,0), Y(bullet,0));
    printf("%c", symbol);
    gotoxy(57,5);
    invisibleSystemPause();
    gotoxy(57,4);
    printf("                  ");
    firedBullet = 0;
    gameplay = 1;
    defineX(bullet,0,0);
    resetTarget = Y(target,1);
}

void detectHit() {
    if(X(bullet,0) == X(target,1)) {
        if(Y(bullet,0) == Y(target,1)) {
            p.hits++;
            gotoxy(85,37);
            setColor(COLOR_WHITE);
            printf("%d", p.hits);
            Beep(300,5);
            gotoxy(57,4);
            setColor(COLOR_LIGHTGREEN);
            printf(" EM CHEIO! \n");
            setColor(COLOR_BLACK);
            bulletHole();
            setBackgroundColor(COLOR_BLACK);
            if(p.hits != p.objective) {
                invisibleSystemPause();
                gotoxy(57,4);
                printf("                  ");
            }
            firedBullet = 0;
            gameplay = 1;
            defineX(bullet,0,0);
            resetTarget = Y(target,1);
        }
    }
    if(X(bullet,0) == X(target,1)) {
        if(Y(bullet,0) == Y(target,1)+1){
            almost(223);
        }
        if(Y(bullet,0) == Y(target,1)-1){
            almost(220);
        }
    }
}
