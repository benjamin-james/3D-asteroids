#ifndef GAME_H
#define GAME_H

#define DEBUG 1 //for now

void render();
void update(double delta);
void setAcceleration(double d);
void joystick(double x, double y);
void init();

#endif
