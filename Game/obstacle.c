#include <stdio.h>
#include <windows.h>
#include "../list.h"
#include "../console.h"
#include "index.h"
#include "bullet.h"

List* obstacle;
int obstacleX = 100;

void insertObstacle() {
    obstacle = createList();

    obstacle = push(obstacle, 177, obstacleX , 30);
    obstacle = push(obstacle, 177, obstacleX , 30);
}

void topObstacle(int bufferY) {
    gotoxy(obstacleX ,Y(obstacle,1)-1);
    printf("%c", symbol(obstacle,0));
    gotoxy(obstacleX ,bufferY-1);
    printf(" ");
}

void bottomObstacle(int bufferY) {
    gotoxy(obstacleX ,Y(obstacle,1));
    printf("%c", symbol(obstacle,0));
    gotoxy(obstacleX ,bufferY);
    printf(" ");
}

void updateObstacle() {
    int bufferY = 0;
    if(firedBullet != 1) {
        bufferY = 0;
        if(obstacleLimit == 0) {
            bufferY = Y(obstacle,1);
            addY(obstacle,1,1);
            if(Y(obstacle,1) == 34) {
                obstacleLimit = 1;
            }
        }else if(obstacleLimit == 1) {
            bufferY = Y(obstacle,1);
            addY(obstacle,1,-1);
            if(Y(obstacle,1) == 4) {
                obstacleLimit = 0;
            }
        }
        setColor(COLOR_WHITE);
        if(obstacleLimit == 0) {
            bottomObstacle(bufferY);
            topObstacle(bufferY);
        } else {
            topObstacle(bufferY);
            bottomObstacle(bufferY);
        }
    }
}


void detectHitObstacle() {
    if(X(bullet,0) == X(obstacle,1)) {
        if(Y(bullet,0) == Y(obstacle,1) || Y(bullet,0) == Y(obstacle,1)-1) {
            Beep(5,2);
            setColor(COLOR_DARKGREY);
            gotoxy(X(bullet,0) , Y(bullet,0));
            printf("%c", symbol(obstacle,0));
            firedBullet = 0;
            gameplay = 1;
            defineX(bullet,0,0);
            resetTarget = Y(obstacle,0);
        }
    }
}
