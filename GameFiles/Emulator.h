#ifndef EMULATOR_H
#define EMULATOR_H

#include <stdio.h>
#include <stdlib.h>

// Vars

#define byte unsigned char
#define DISPLAY_W 40
#define DISPLAY_H 30
#define DISPLAY_COEFICIENT 16
#define FPS 15

char Keys;
char lastKeys;
char KeysUp;
char KeysDown;
char** Buffer;
void(*mainUpd)();
void(*mainDraw)();
extern char Keys;
extern char** Buffer;
extern char lastKeys;
extern char KeysUp;
extern char KeysDown;
extern void(*mainUpd)();
extern void(*mainDraw)();

void mainLoop();

// Functions
void drawBack(byte color);
void quit();
long random(long min, long max);

// Your functions
void start();
void end();


#endif
