#include <unistd.h>
#include <windows.h>
#include "list.h"
#include "console.h"
#include "playerName.h"
#include "borders.h"
#include "Menu/index.h"
#include "Menu/gameKeys.h"
#include "Menu/credits.h"
#include "Menu/quitGame.h"
#include "Game/difficulty.h"
#include "Game/index.h"

int main()
{
    //Título do console
    SetConsoleTitle("Tiro ao Alvo!");

    //Remove o scrollbar do console
    removeScrollbar();

    //Define o tamanho do console
    setWindow(125,40);

    //Impede o usuário de extender o console
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    //Receber o nome do jogador
    getPlayerName();
    Beep(2,3);

    //Insere as bordas cinzas na tela
    insertBorders();

    //Esconde o cursor do console
    hideCursor();

    while(1) {
        clearScreen();
        startMenu();
        switch(selected) {
            case 0:
                clearScreen();
                //Selecionador de Dificuldade
                startDifficultyScreen();

                clearScreen();
                //Inicia o jogo
                startGame();

                //Jogo em andamento
                gameInProgress();

                Beep(2,3);
                break;
            case 1:
                //Controles do jogo;
                clearScreen();
                gameKeys();
                invisibleSystemPause();
                Beep(2,3);
                break;
            case 2:
                //Créditos;
                clearScreen();
                credits();
                invisibleSystemPause();
                Beep(2,3);
                break;
            case 3:
                //Sair do jogo
                quitGame();
                break;
        }
    }
    return 0;
}
