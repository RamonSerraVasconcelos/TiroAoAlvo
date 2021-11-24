#include <stdio.h>
#include <windows.h>
#include "../list.h"
#include "../console.h"
#include "../borders.h"
#include "difficulty.h"
#include "player.h"

int hover, difficulty, difficultyX, difficultyY = 0;

void hoverDifficulty() {
        switch(difficultyY) {
        case 16:
            difficultyX = 59;
            gotoxy(difficultyX, difficultyY);
            setColor(COLOR_LIGHTGREEN);
            printf("F%ccil", 160);
            hover = 0;
            break;
        case 18:
            difficultyX = 58;
            gotoxy(difficultyX, difficultyY);
            setColor(COLOR_CYAN);
            printf("Normal");
            hover = 1;
            break;
        case 20:
            difficultyX = 58;
            gotoxy(difficultyX, difficultyY);
            setColor(COLOR_LIGHTRED);
            printf("Dif%ccil", 161);
            hover = 2;
            break;
    }
}

void unHover() {
    gotoxy(difficultyX, difficultyY);
    setColor(COLOR_DARKGREY);
}

void aboveDifficulty() {
    difficultyY = difficultyY - 2;
}

void belowDifficulty() {
    difficultyY = difficultyY + 2;
}

void difficultyControls() {
        if(detectedKey == 1) {
            switch(key) {
            case UP_KEY:
                if(hover == 1) {
                    unHover();
                    printf("Normal");
                    aboveDifficulty();
                    hoverDifficulty();
                } else if(hover == 2) {
                    unHover();
                    printf("Dif%ccil", 161);
                    aboveDifficulty();
                    hoverDifficulty();
                }
                break;
            case DOWN_KEY:
                if(hover == 0) {
                    unHover();
                    printf("F%ccil", 160);
                    belowDifficulty();
                    hoverDifficulty();
                } else if(hover == 1) {
                    unHover();
                    printf("Normal");
                    belowDifficulty();
                    hoverDifficulty();
                }
                break;
            case ENTER_KEY:
                Beep(2,3);
                if(difficultyY == 16) {
                    difficulty = 1;
                }else if(difficultyY == 18) {
                    difficulty = 2;
                }else {
                    difficulty = 3;
                }
                break;
            }
        }
        detectedKey = 0;
    return;
}

void startDifficultyScreen() {

        difficultyX = 58;
        difficultyY = 18;
        hover = 1;

        //SELECIONE A DIFICULDADE
        gotoxy(51,13);
        setColor(COLOR_WHITE);
        printf("SELECIONE A DIFICULDADE");
        for(int x=50; x<75; x++) {
            setColor(COLOR_DARKGREY);
            gotoxy(x,14);
            printf("%c", 196);
        }

        //DIFICULDADES
        gotoxy(59,16);
        setColor(COLOR_DARKGREY);
        printf("F%ccil", 160);
        gotoxy(58,18);
        setColor(COLOR_CYAN);
        printf("Normal");
        gotoxy(58,20);
        setColor(COLOR_DARKGREY);
        printf("Dif%ccil", 161);
        gotoxy(43,37);
        setColor(COLOR_WHITE);
        printf("/%c = Cima   %c/ = Baixo   %c%c = Selecionar", 92, 92, 60, 217);
        setColor(COLOR_DARKGREY);

        do{
            readKeyboard();
            difficultyControls();
        }while(difficulty == 0);
}

void easy() {
    p.howMuchTime = 80;
    p.ammo = 20;
    p.objective = 3;
}

void normal() {
    p.howMuchTime = 60;
    p.ammo = 15;
    p.objective = 4;
}

void hard() {
    p.howMuchTime = 50;
    p.ammo = 10;
    p.objective = 5;
}
