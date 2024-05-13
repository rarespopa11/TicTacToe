#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Player.h"
#include <iomanip>
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;

void resetBuffer();

int numar();

void Leaderboard(string a[][3]);

void winSort(string a[][3]);

void wlratioSort(string a[][3]);

void gotoxy(short x, short y);

void game2p(string a[][3],string PlayerX, string Player0);

void citire(string a[][3]);

void gameg2p(string a[][3]);

void start(string a[][3]);

void meniu(string a[][3]);

void textcolor(int color);

void getplayerNames(string a[][3]);

void checkplayerList(short winner, string PlayerX, string Player0);

void winner2player(string a[][3], short winner, string PlayerX, string Player0);

#endif // FUNC_H_INCLUDED
