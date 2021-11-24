#include <stdio.h>
#include "list.h"
#include "console.h"
#include "borders.h"

List* borders;

void insertBorders() {
        borders = createList();
        // Insere paredes
        //Teto
        for(int x=2; x<123; x++) {
            borders = push(borders, (char)223, x, 1);
        }
        //Parede esquerda
        for(int y=1; y < 39; y++) {
            borders = push(borders, (char)219, 1, y);
        }
        //Parede direita
        for(int y=1; y < 39; y++) {
            borders = push(borders, (char)219, 123, y);
        }
        //Borda de baixo
        for(int x=2; x<123; x++) {
            borders = push(borders, (char)220, x, 38);
        }
}

void printBorders() {
    printList(borders);
}

void freeFloorBorder() {
    for(int x=2; x<123; x++) {
        borders = listRemoveByCoord(borders, x, 36);
    }
}

void freeAllBorders() {
    for(int i=0; i<124; i++) {
        borders = listRemoveByCoord(borders, i, i);
    }
}
