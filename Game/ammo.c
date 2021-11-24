#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "../list.h"
#include "../console.h"
#include "index.h"
#include "player.h"
#include "difficulty.h"

List* collectableAmmo;

void insertCA() {
    collectableAmmo = createList();
}

void newCA() {
    int yMin, yMax, randomX, randomY = 0;
    int xMin = 6;
    int xMax = 10;
    int xDiff = xMax - xMin;

    srand(time(NULL));

    if(p.y - 3 < 12) {
        yMin = 17;
        yMax = 33;
    } else if(p.y + 3 > 12) {
        yMin = 5;
        yMax = 10;
    }

    int yDiff = yMax - yMin;

    randomY = rand() % (yDiff + 1) + yMin;

    randomX = rand() % (xDiff + 1) + xMin;

    collectableAmmo = push(collectableAmmo, 176, randomX, randomY);
}

void printCA() {
    setColor(COLOR_BROWN);
    printList(collectableAmmo);
}

void detectCA() {
    if(listSize(collectableAmmo) == 1 && p.ammo == 0) {
        printCA();
        if(p.y + 3 == Y(collectableAmmo, 0) || p.y - 3 == Y(collectableAmmo, 0) || p.y + 2 == Y(collectableAmmo, 0) || p.y - 2 == Y(collectableAmmo, 0) || p.y + 1 == Y(collectableAmmo, 0) || p.y - 1 == Y(collectableAmmo, 0) || p.y == Y(collectableAmmo, 0)){
            p.ammo =+ 5;
            setColor(COLOR_BLACK);
            gotoxy(X(collectableAmmo, 0), Y(collectableAmmo, 0));
            printf(" ");
            listFree(collectableAmmo);
            insertCA();
            newCA();
            Beep(200,5);
        }
    }
}
