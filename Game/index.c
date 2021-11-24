#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "../list.h"
#include "../console.h"
#include "../borders.h"
#include "../Menu/index.h"
#include "difficulty.h"
#include "tutorial.h"
#include "index.h"
#include "bullet.h"
#include "target.h"
#include "obstacle.h"
#include "player.h"
#include "ammo.h"
#include "Endings/gameOver.h"
#include "Endings/gameWon.h"

int downCounter, gameTime, gameplay, resetTarget, targetLimit, obstacleLimit, firedBullet = 0;
time_t start, now;

void controls() {
    if(resetTarget != Y(target,1)) {
        gameplay = 0;
    }
    if(firedBullet != 1 && gameplay != 1) {
        int bufferX = p.x;
        int bufferY = p.y;
        if(detectedKey == 1) {
            switch(key) {
            case UP_KEY:
                if(p.y > 5) {
                    p.y--;
                    clearPlayer(bufferX,bufferY);
                    printPlayer();
                }
                break;
            case DOWN_KEY:
                if(p.y < 32) {
                    p.y++;
                    clearPlayer(bufferX,bufferY);
                    printPlayer();
                }
                break;
            case RIGHT_KEY:
                if(p.x < 10) {
                    p.x++;
                    clearPlayer(bufferX,bufferY);
                    printPlayer();
                }
                break;
            case LEFT_KEY:
                if(p.x > 6) {
                    p.x--;
                    clearPlayer(bufferX,bufferY);
                    printPlayer();
                }
                break;
            case SPACE_KEY:
                if(p.ammo > 0) {
                    defineX(bullet,0,p.x+6);
                    defineY(bullet,0,p.y);
                    updateBullet();
                    p.ammo--;
                    firedBullet = 1;
                    Beep(100,20);
                    break;
                }
                Beep(2,5);
                break;
            case ESC_KEY:
                freeFloorBorder();
                listFree(target);
                setColor(COLOR_DARKGREY);
                difficulty = 0;
                menu = 0;
                break;
            }
        }
        detectedKey = 0;
    }
    return;
}

void updateStatus() {
    //Tempo
    time(&now);
    downCounter = now - start;
    gameTime = p.howMuchTime - downCounter;

    if(gameTime == 9) {
        gotoxy(120,37);
        setColor(COLOR_BLACK);
        printf(" ");
    }

    //Nome do jogador:
    setColor(COLOR_LIGHTRED);
    gotoxy(3,37);
    printf("Jogador: ");
    setColor(COLOR_WHITE);
    gotoxy(12,37);
    if(strlen(p.name) < 1) {
        printf("An%cnimo", 147);
    } else {
        printf("%s", p.name);
    }

    // Quantidade de balas do jogador
    setColor(COLOR_YELLOW);
    gotoxy(36,37);
    printf("Quantidade de balas: ");
    setColor(COLOR_WHITE);
    gotoxy(57,37);
    printf("%d", p.ammo);
    if(p.ammo == 9) {
        gotoxy(58,37);
        setColor(COLOR_BLACK);
        printf(" ");
    }
    // Objetivo
    setColor(COLOR_LIGHTBLUE);
    gotoxy(62,37);
    printf("Objetivo: ");
    setColor(COLOR_WHITE);
    gotoxy(72,37);
    printf("%d", p.objective);
    // Acertos
    setColor(COLOR_LIGHTGREEN);
    gotoxy(76,37);
    printf("Acertos: ");
    setColor(COLOR_WHITE);
    gotoxy(85,37);
    printf("%d", p.hits);
    // Relógio
    setColor(COLOR_WHITE);
    gotoxy(112,37);
    printf("Tempo: %d", gameTime);
    //setColor(COLOR_BLUE);

    if(gameTime <= 0) {
        gameOver();
    }

    if(p.hits >= p.objective) {
        gameWon();
    }
}


void startGame() {
    //Dificuldade inserida
    tutorial();
    if(difficulty == 1){
        easy();
    }else if(difficulty == 2){
        normal();
        insertObstacle();
    }else if(difficulty ==  3){
        hard();
        insertObstacle();
    }

    // Para o relogio
    time(&start);

    // Posicao inicial do personagem
    p.x = 8;
    p.y = 18;
    p.hits = 0;

    // Avatar
    p.body[0] = 220;
    p.body[1] = 219;
    p.body[2] = 223;
    p.body[3] = 254;
    p.body[4] = 218;
    p.body[5] = 196;

    // Insere chão
    setColor(COLOR_DARKGREY);
    for(int x=2; x<123; x++) {
        borders = push(borders, (char)223, x, 36);
    }

    //Alvo
    insertTarget();

    //Bala
    insertBullet();
    bullet = push(bullet, 175, p.x+6, p.y);

    //Munição coletável
    insertCA();
    newCA();

    printBorders();
    printPlayer();
}


void gameInProgress() {
    do{
        readKeyboard();
        controls();
        updateStatus();
        updateTarget();
        updateBullet();
        detectHit();
        detectCA();
        if(difficulty > 1 ) {
            updateObstacle();
            detectHitObstacle();
        }
        //Caso não haja um disparo, usar tal velocidade
        if(firedBullet != 1) {
            usleep(9000);
        }
    }while(menu == 1);
}
