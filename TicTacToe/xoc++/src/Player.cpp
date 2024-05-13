#include "Player.h"
using std::string;
using std::cout;
using std::setw;
Player::Player(const string givenName, int wins, int losses, int draws)
{
    name=givenName;
    winCount=wins;
    loseCount=losses;
    drawCount=draws;
}

Player::Player()
{
    name="unnamed";
    winCount=0;
    loseCount=0;
    drawCount=0;
    winlossRatio=0;
}


Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        this->name=other.name;
        this->winCount=other.winCount;
        this->loseCount=other.loseCount;
        this->drawCount=other.drawCount;
        this->winlossRatio=other.winlossRatio;
        }


    return *this;
}
void Player::print()
{
    cout<<std::setw(8)<<"Name: "<<std::setw(8)<<name<<std::setw(15)<<"     Wins: "<<winCount<<std::setw(8)<<"      Losses: "<<loseCount<<std::setw(8)<<"       Draws: "<< drawCount <<std::setw(8)<< "       W/L Ratio: "<<winlossRatio<<"\n";
}
string Player::getName()
{
    return name;
}
int Player::getwinCount()
{
    return winCount;
}
int Player::getloseCount()
{
    return loseCount;
}
int Player::getdrawCount()
{
    return drawCount;
}
float Player::getwinlossRatio()
{
    return winlossRatio;
}
Player::~Player()
{

}
void Player::updateWins()
{
    winCount++;
}
void Player::updateLosses()
{
    loseCount++;
}

void Player::updateDraws()
{
    drawCount++;
}
void Player::updatewlRatio()
{
    if(winCount==0)
        winlossRatio=0;
    else if(loseCount==0)
        winlossRatio=winCount;
    else winlossRatio=float(winCount)/float(loseCount);
}
