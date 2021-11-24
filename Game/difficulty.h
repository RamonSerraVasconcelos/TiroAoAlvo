#ifndef DIFFICULTY_H_INCLUDED
#define DIFFICULTY_H_INCLUDED

extern int difficulty;
extern List* borders;

    void hoverDifficulty();
    void unHover();
    void aboveDifficulty();
    void belowDifficulty();
    void difficultyControls();
    void startDifficultyScreen();

    void easy();
    void normal();
    void hard();

#endif // DIFFICULTY_H_INCLUDED
