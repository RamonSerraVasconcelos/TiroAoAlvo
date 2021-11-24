#include <stdio.h>
#include <windows.h>
#include "../list.h"
#include "../console.h"
#include "../borders.h"
#include "index.h"

    int selected, menu, menuX, menuY = 0;

    void selector() {
            switch(menuY) {
            case 15:
                menuX = 59;
                gotoxy(menuX, menuY);
                setColor(COLOR_WHITE);
                printf("Iniciar");
                selected = 0;
                break;
            case 17:
                menuX = 58;
                gotoxy(menuX, menuY);
                setColor(COLOR_WHITE);
                printf("Controles");
                selected = 1;
                break;
            case 19:
                menuX = 58;
                gotoxy(menuX, menuY);
                setColor(COLOR_WHITE);
                printf("Cr%cditos", 130);
                selected = 2;
                break;
            case 21:
                menuX = 57;
                gotoxy(menuX, menuY);
                setColor(COLOR_WHITE);
                printf("Sair do Jogo");
                selected = 3;
                break;
        }
    }

    void unSelector() {
        gotoxy(menuX, menuY);
        setColor(COLOR_DARKGREY);
    }

    void aboveOption() {
        menuY = menuY - 2;
    }

    void belowOption() {
        menuY = menuY + 2;
    }

    void menuControls() {
            if(detectedKey == 1) {
                switch(key) {
                case UP_KEY:
                    if(selected == 1) {
                        unSelector();
                        printf("Controles");
                        aboveOption();
                        selector();
                    } else if(selected == 2) {
                        unSelector();
                        printf("Cr%cditos", 130);
                        aboveOption();
                        selector();
                    } else if(selected == 3) {
                        unSelector();
                        printf("Sair do Jogo");
                        aboveOption(menuY);
                        selector();
                    }
                    break;
                case DOWN_KEY:
                    if(selected == 0) {
                        unSelector();
                        printf("Iniciar");
                        belowOption();
                        selector();
                    } else if(selected == 1) {
                        unSelector();
                        printf("Controles");
                        belowOption();
                        selector();
                    } else if(selected == 2) {
                        unSelector();
                        printf("Cr%cditos", 130);
                        belowOption();
                        selector();
                    }
                    break;
                case ENTER_KEY:
                    Beep(2,3);
                    menu = 1;
                    break;
                }
            }
            detectedKey = 0;
        return;
    }

    void startMenu() {

        menuX = 59;
        menuY = 15;
        selected = 0;

        //NOME DO JOGO
        gotoxy(56,12);
        setColor(COLOR_BROWN);
        printf("TIRO");
        gotoxy(61,12);
        setColor(COLOR_WHITE);
        printf("AO");
        gotoxy(64,12);
        setColor(COLOR_LIGHTRED);
        printf("ALVO!");
        for(int x=55; x<70; x++) {
            setColor(COLOR_DARKGREY);
            gotoxy(x,13);
            printf("%c", 196);
        }

        //OPÇÕES
        gotoxy(59,15);
        setColor(COLOR_WHITE);
        printf("Iniciar");
        gotoxy(58,17);
        setColor(COLOR_DARKGREY);
        printf("Controles");
        gotoxy(58,19);
        setColor(COLOR_DARKGREY);
        printf("Cr%cditos", 130);
        gotoxy(57,21);
        setColor(COLOR_DARKGREY);
        printf("Sair do Jogo");
        gotoxy(43,37);
        setColor(COLOR_WHITE);
        printf("/%c = Cima   %c/ = Baixo   %c%c = Selecionar", 92, 92, 60, 217);
        setColor(COLOR_DARKGREY);

        do{
            readKeyboard();
            menuControls();
        }while(menu == 0);
}
