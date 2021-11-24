#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "list.h"
#include "console.h"
#include "Menu/quitGame.h"
#include "Game/player.h"

char ch;
int c;

void getPlayerName() {

        gotoxy(54,11);
        setColor(COLOR_DARKGREY);
        printf("BEM-VINDO AO JOGO");

        //NOME DO JOGO
        gotoxy(56,13);
        setColor(COLOR_BROWN);
        printf("TIRO");
        gotoxy(61,13);
        setColor(COLOR_WHITE);
        printf("AO");
        gotoxy(64,13);
        setColor(COLOR_LIGHTRED);
        printf("ALVO!");

        setColor(COLOR_DARKGREY);
        gotoxy(45,16);
        printf("Antes de come%carmos, insira seu nome:", 135);

        gotoxy(53,17);
        printf("%c", 218); //diagonal superior esquerdo
        gotoxy(72,17);
        printf("%c", 191); //diagonal superior direito
        for(int x=54; x<72; x++) {
            gotoxy(x,17);
            printf("%c", 196); //horizontal superior
        }

        gotoxy(53,18);
        printf("%c", 179); //vertical meio esquerdo
        gotoxy(72,18);
        printf("%c", 179); //vertical meio direito

        for(int x=54; x<72; x++) {
            gotoxy(x,19);
            printf("%c", 196); //horizontal inferior
        }
        gotoxy(53,19);
        printf("%c", 192); //diagonal inferior esquerdo
        gotoxy(72,19);
        printf("%c", 217); //diagonal inferior direito

        setColor(COLOR_WHITE);
        gotoxy(45,37);
        printf("%c%c = Confirmar   ESC = Sair do Jogo", 60, 217);
        gotoxy(55,18);
        while((ch = getch()) != 13){
            if(ch != 8){
                if(ch == 27) {
                    hideCursor();
                        system("@cls||clear");
                        setColor(COLOR_WHITE);
                        gotoxy(54,17);
                        printf("Jogo Finalizado! ");
                        usleep(999999);
                        usleep(500000);
                        system("@cls||clear");
                        setColor(COLOR_DARKGREY);
                        exit(0);
                }
                if(ch != 32 && ch != 33 && ch != 34 && ch != 35 && ch != 36 && ch != 37 && ch != 38 && ch != 39 && ch != 40 && ch != 41 && ch != 42 && ch != 43 && ch != 44 && ch != 45 && ch != 46 && ch != 47 && ch != 48 && ch != 49 && ch != 50 && ch != 51 && ch != 52 && ch != 53 && ch != 54 && ch != 55 && ch != 56 && ch != 57 && ch != 58 && ch != 59 && ch != 60 && ch != 61 && ch != 62 && ch != 63 && ch != 64 && ch != 91 && ch != 92 && ch != 93 && ch != 94 && ch != 95 && ch != 96 && ch != 123 && ch != 124 && ch != 125 && ch != 126 && ch != 239){
                    putchar(ch);
                    if( c < 15){
                        p.name[c] = ch;
                        c++;
                    }else{
                        putchar('\b');
                        putchar('\0');
                        putchar('\b');
                    }
                }
            }else if(c >= 1  && ch == 8){
                putchar('\b');
                putchar('\0');
                putchar('\b');
                c--;
                p.name[c]=' ';
            }else if (c == 0) {
                memset(p.name,0,sizeof(p.name));
            }
        }
}
