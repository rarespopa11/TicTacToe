#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<iomanip>
using std::string;

class Player
{
    string name;
    int winCount;
    int loseCount;
    int drawCount;
    float winlossRatio;

    public:
        Player(const string, int, int,int);
        Player();
        Player& operator=(const Player&);
        ~Player();
        string getName();
        void print();
        int getwinCount();
        int getloseCount();
        int getdrawCount();
        float getwinlossRatio();
        void updateWins();
        void updateLosses();
        void updateDraws();
        void updatewlRatio();

    protected:

    private:
};

#endif // PLAYER_H
