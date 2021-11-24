#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

extern List* bullet;

void insertBullet();

//Executa a movimentação da bala
void updateBullet();

//Faz o desenho do buraco da bala no Alvo
void bulletHole();

#endif // BULLET_H_INCLUDED
