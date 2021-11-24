#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef struct player {
    int howMuchTime, ammo, objective, hits, x,y;
    char name[16], body[7];
}Player;

extern Player p;

//Componentes do jogador de forma individual
void hat();
void head();
void arms();
void gun();
void hands();
void legs();
//Todos os componentes do jogador
void printPlayer();

//Limpar jogador
void clearPlayer(int bufferX,int bufferY);

#endif // PLAYER_H_INCLUDED
