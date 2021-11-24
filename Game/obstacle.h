#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

extern List* obstacle;

void insertObstacle();

void topObstacle(int bufferY);

void bottomObstacle(int bufferY);

void updateObstacle();

void detectHitObstacle();

#endif // OBSTACLE_H_INCLUDED
