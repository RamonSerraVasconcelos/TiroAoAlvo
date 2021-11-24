#include <stdio.h>
#include <unistd.h>
#include "../list.h"
#include "../console.h"
#include "index.h"
#include "bullet.h"
#include "target.h"

List* bullet;

void insertBullet() {
    bullet = createList();
}

void updateBullet() {
    int bufferX;
    if(firedBullet == 1) {
        if(X(bullet,0) < 123) {
        bufferX = X(bullet,0);
        usleep(900);
        addX(bullet,0,1);
            if(X(bullet,0) == 123) {
                gotoxy(bufferX,Y(bullet,0));
                printf(" ");
                defineX(bullet,0,0);
                bufferX = 0;
                firedBullet = 0;
                gameplay = 1;
                resetTarget = Y(target,1);
            }
        }
        setColor(COLOR_BROWN);
        gotoxy(X(bullet,0),Y(bullet,0));
        printf("%c", symbol(bullet,0));
        gotoxy(bufferX,Y(bullet,0));
        printf(" ");
    }
}

void bulletHole() {
    setBackgroundColor(COLOR_WHITE);
    setColor(COLOR_BLACK);
    gotoxy(X(bullet,0) , Y(bullet,0));
    printf("%c", 250);
}
