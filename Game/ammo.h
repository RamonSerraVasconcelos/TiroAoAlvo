#ifndef AMMO_H_INCLUDED
#define AMMO_H_INCLUDED

extern List* collectableAmmo;

//Cria a lista da municao coletavel
void insertCA();
//Insere uma municao coletável a lista
void newCA();
//Imprime municao coletavel na tela
void printCA();
//Detectar se o jogador coletou munição
void detectCA();

#endif // AMMO_H_INCLUDED
