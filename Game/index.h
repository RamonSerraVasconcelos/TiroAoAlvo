#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED

extern int gameTime, resetTarget, gameplay, targetLimit, obstacleLimit, firedBullet;

//Verifica qual tecla for pressionada e executa uma acao
void controls();

//Atualiza o status do Jogo
void updateStatus();

//Inicia o jogo com todos os requisitos
void startGame();

//Jogo em andamento
void gameInProgress();

//Fim de jogo
void gameOver();

//Jogo vencido
void gameWon();

#endif // CONTROLE_H_INCLUDED
