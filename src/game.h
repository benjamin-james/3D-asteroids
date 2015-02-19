#ifndef GAME_H
#define GAME_H

void render();
void update(double delta);
void handleKey(SDL_Keycode key, Uint32 status);
void mouseMoved(int x, int y);

#endif
