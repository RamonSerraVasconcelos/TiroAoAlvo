#ifndef TARGET_H_INCLUDED
#define TARGET_H_INCLUDED

extern List* target;

//Cria o Alvo
void insertTarget();

//Componentes do Alvo
//P�xeis vermelhos do alvo
void topTarget(int bufferY);
void bottomTarget(int bufferY);
//P�xel branco do Alvo
void middleTarget(int bufferY);

//Executa a movimenta��o do alvo
void updateTarget();

//Verifica se a bala acertou o alvo
void detectHit();
//Verifica se a bala quase acertou o alvo
void almost(int symbol);

#endif // TARGET_H_INCLUDED
