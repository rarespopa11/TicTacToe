#include "func.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Player.h"
#include <iomanip>
#include <cstdlib>
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;

void resetBuffer(){


    while(_kbhit())
        _getch();
}

int numar(){
   return rand()%3;
}

void winner2p(string a[][3],int n){ //Function to determine the winner of the guest game-mode
short y=2,ymax=3,culoarey=0,ok=1,ymin=1;
char opt[2][20]={"Play again", "Main Menu"};
while(ok==1){
    system("cls");
    if(n==0)
    std::cout<<"Player X wins!\n\n";
    else if(n==1)
        std::cout<<"Player 0 wins!\n\n";
    else if(n==2)
        std::cout<<"It's a draw!\n\n";
    for(short i=0;i<2;i++){
        if(culoarey==i)
            std::cout<<">>"<<opt[i]<<"\n";

        else std::cout<<opt[i]<<"\n";
    }
    gotoxy(0,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=2;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=1;
        }
        break;
    }
     if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(culoarey==0){
                        system("cls");
                        citire(a);
                        gameg2p(a);
                ok=0;
                break;
            }
                else if(culoarey==1){
                    system("cls");
                    citire(a);
                    start(a);
                    ok=0;
                    break;
                }


    }

    }

Sleep(25);

    }

system("cls");
}

void winner(string a[][3],int n){   //Function to deteermine the winner of the Play against AI game mode.
short y=2,ymax=3,culoarey=0,ok=1,ymin=1;
char opt[2][20]={"Play again", "Main menu"};
while(ok==1){
    system("cls");
    if(n==0)
    std::cout<<"Hurray! You won!\n\n";
    else if(n==1)
        std::cout<<"Bad luck, try again?\n\n";
    else if(n==2)
        std::cout<<"It's a draw!\n\n";
    for(short i=0;i<2;i++){
        if(culoarey==i)
            std::cout<<">>"<<opt[i]<<"\n";

        else std::cout<<opt[i]<<"\n";
    }
    gotoxy(0,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=2;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=1;
        }
        break;
    }
     if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(culoarey==0){
                        system("cls");
                        citire(a);
                        meniu(a);
                ok=0;
                break;
            }
                else if(culoarey==1){
                    system("cls");
                    citire(a);
                    start(a);
                    ok=0;
                    break;
                }
                else if(culoarey==2){
                    system("cls");
                    ok=0;
                    break;
                }



    }

    }

Sleep(25);

    }

system("cls");
}

void menu2p(string a[][3]){ //Function for the 2-Player pre-game menu.
    char opt[2][32]={"Enter player names", "Play as guests"};
short y=2, ymax=3,ok=1,c=0,ymin=2,culoarey=0;
while(ok==1){
    system("cls");
    std::cout<<"2 Player mode\n\n";
    for(short i=0;i<2;i++){
        if(culoarey==i)
            std::cout<<">>"<<opt[i]<<"\n";

        else std::cout<<opt[i]<<"\n";
    }
    gotoxy(0,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=2;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=1;
        }
        break;
    }
     if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(culoarey==0){
                        system("cls");
                        getplayerNames(a);
                ok=0;
                return;

            }
                else if(culoarey==1){
                    system("cls");
                    gameg2p(a);
                    ok=0;
                    return;
                }



    }

    }

Sleep(25);

    }

system("cls");
}

void gameg2p(string a[][3]){ //Game function for the 2-Player Guest mode.
short y=1, ymax=3,ok=1,c=0,ymin=1,culoarex=0,culoarey=0,x=0,xmin=0,xmax=4,botx=-1,boty=-1,contor=0,act=0;
while(ok==1){
     gotoxy(x,y);
    system("cls");
    std::cout<<"TicTacToe";
    for(short i=0;i<3;i++){
        std::cout<<"\n";
        for(short j=0;j<3;j++){
        if(culoarey==i && culoarex==j){
            textcolor(112);
            std::cout<<a[i][j]<<" ";
            textcolor(7);
        }
        else std::cout<<a[i][j]<<" ";
    }
    }
    gotoxy(x,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=1;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=2;
        }
        break;
    }
 if(GetAsyncKeyState(0x41))//a
    {
        x-=2;
        culoarex--;

        if(x<=xmin){
            x=0;
            culoarex=0;
        }
        break;
    }
 if(GetAsyncKeyState(0x44))//a
    {
        x+=2;
        culoarex++;

        if(x>=xmax){
            x=4;
            culoarex=2;
        }
        break;
    }
    if((a[0][0]=="X" && a[0][1]=="X" && a[0][2]=="X")|| (a[1][0]=="X" && a[1][1]=="X" && a[1][2]=="X") || (a[2][0]=="X" && a[2][1]=="X" && a[2][2]=="X") || (a[0][0]=="X" && a[1][0]=="X" && a[2][0]=="X") || (a[0][1]=="X" && a[1][1]=="X" && a[2][1]=="X") || (a[0][2]=="X" && a[1][2]=="X" && a[2][2]=="X") || (a[0][0]=="X" && a[1][1]=="X" && a[2][2]=="X") || (a[0][2]=="X" && a[1][1]=="X" && a[2][0]=="X"))
       {

        ok=0;
        system("cls");
        winner2p(a,0);

        return;

}   else if((a[0][0]=="0" && a[0][1]=="0" && a[0][2]=="0")|| (a[1][0]=="0" && a[1][1]=="0" && a[1][2]=="0") || (a[2][0]=="0" && a[2][1]=="0" && a[2][2]=="0") || (a[0][0]=="0" && a[1][0]=="0" && a[2][0]=="0") || (a[0][1]=="0" && a[1][1]=="0" && a[2][1]=="0") || (a[0][2]=="0" && a[1][2]=="0" && a[2][2]=="0") || (a[0][0]=="0" && a[1][1]=="0" && a[2][2]=="0") || (a[0][2]=="0" && a[1][1]=="0" && a[2][0]=="0"))
       {

        ok=0;
        system("cls");
        winner2p(a,1);

        return;

       }
    else if(contor==9){
        ok=0;
        system("cls");
        winner2p(a,2);

        return;
        }
    else if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(act==0){
                if(a[culoarey][culoarex]!="X"&& a[culoarey][culoarex]!="0"){
                a[culoarey][culoarex]="X";
                contor+=1;
                act=1;}}
                else if(act==1)
                    if(a[culoarey][culoarex]!="X"&& a[culoarey][culoarex]!="0"){
                a[culoarey][culoarex]="0";
                contor+=1;
                act=0;

                }
break;
    }
    }
Sleep(25);
    }

system("cls");
}

void gotoxy(short x, short y){ //Make the cursor of the console move with the menu selections.
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(h, coord);
}

void textcolor(int color){ //Make the text pretty by changing the background
    static int BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        color + (BACKGROUND << 4));
}

void meniu(string a[][3]){  //game function for playing against AI
short y=1, ymax=3,ok=1,c=0,ymin=1,culoarex=0,culoarey=0,x=0,xmin=0,xmax=4,botx=-1,boty=-1,contor=0;
while(ok==1){
     gotoxy(x,y);
    system("cls");
    std::cout<<"TicTacToe";
    for(short i=0;i<3;i++){
        std::cout<<"\n";
        for(short j=0;j<3;j++){
        if(culoarey==i && culoarex==j){
            textcolor(112);
            std::cout<<a[i][j]<<" ";
            textcolor(7);
        }
        else std::cout<<a[i][j]<<" ";
    }
    }
    gotoxy(x,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=1;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=2;
        }
        break;
    }
 if(GetAsyncKeyState(0x41))//a
    {
        x-=2;
        culoarex--;

        if(x<=xmin){
            x=0;
            culoarex=0;
        }
        break;
    }
 if(GetAsyncKeyState(0x44))//a
    {
        x+=2;
        culoarex++;

        if(x>=xmax){
            x=4;
            culoarex=2;
        }
        break;
    }
    if((a[0][0]=="X" && a[0][1]=="X" && a[0][2]=="X")|| (a[1][0]=="X" && a[1][1]=="X" && a[1][2]=="X") || (a[2][0]=="X" && a[2][1]=="X" && a[2][2]=="X") || (a[0][0]=="X" && a[1][0]=="X" && a[2][0]=="X") || (a[0][1]=="X" && a[1][1]=="X" && a[2][1]=="X") || (a[0][2]=="X" && a[1][2]=="X" && a[2][2]=="X") || (a[0][0]=="X" && a[1][1]=="X" && a[2][2]=="X") || (a[0][2]=="X" && a[1][1]=="X" && a[2][0]=="X"))
     {

        ok=0;
        system("cls");
        winner(a,0);

        return;

}   else if((a[0][0]=="0" && a[0][1]=="0" && a[0][2]=="0")|| (a[1][0]=="0" && a[1][1]=="0" && a[1][2]=="0") || (a[2][0]=="0" && a[2][1]=="0" && a[2][2]=="0") || (a[0][0]=="0" && a[1][0]=="0" && a[2][0]=="0") || (a[0][1]=="0" && a[1][1]=="0" && a[2][1]=="0") || (a[0][2]=="0" && a[1][2]=="0" && a[2][2]=="0") || (a[0][0]=="0" && a[1][1]=="0" && a[2][2]=="0") || (a[0][2]=="0" && a[1][1]=="0" && a[2][0]=="0"))
    {

        ok=0;
        system("cls");
        winner(a,1);

        return;

       }
    else if(contor==5){
        ok=0;
        system("cls");
        winner(a,2);

        return;
        }
    else if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}

                if(a[culoarey][culoarex]!="X"&& a[culoarey][culoarex]!="0"){
                a[culoarey][culoarex]="X";
                contor+=1;
                if(contor<5)
                while(1==1){
                botx=numar();
                boty=numar();
                if(a[boty][botx]!="X" && a[boty][botx]!="0")
                    {a[boty][botx]="0";

                    break;}
                }
                }
break;
    }
    }
Sleep(25);
    }

system("cls");
}

void citire(string a[][3]) { //initialize the matrix
a[0][0]="1";
a[0][1]="2";
a[0][2]="3";
a[1][0]="4";
a[1][1]="5";
a[1][2]="6";
a[2][0]="7";
a[2][1]="8";
a[2][2]="9";
}

void afisare(string a[][3]){ //printing the matrix
    for (int i=0;i<3;i++)
{
    std::cout<<"\n";
    for(int j=0;j<3;j++)
        std::cout<<" "<<a[i][j];
}
}

void start(string a[][3]){ //main menu function
char opt[4][32]={"Play against AI", "2-Player Mode", "Leaderboard","Exit"};
short y=2, ymax=6,ok=1,c=0,ymin=2,culoarey=0;
while(ok==1){
    system("cls");
    std::cout<<"--> MAIN MENU <--\n\n";
    for(short i=0;i<4;i++){
        if(culoarey==i)
            std::cout<<">>"<<opt[i]<<"\n";

        else std::cout<<opt[i]<<"\n";
    }
    gotoxy(0,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=2;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=5;
            culoarey=3;
        }
        break;
    }
     if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(culoarey==0){
                        system("cls");
                        meniu(a);
                ok=0;
                return;

            }
                else if(culoarey==1){
                    system("cls");
                    menu2p(a);
                    ok=0;
                    return;
                }
                else if(culoarey==2){
                    system("cls");
                    Leaderboard(a);
                    ok=0;
                    return;
                }
                else if(culoarey==3){
                 system("cls");
                ok=0;
                return;
                }


    }

    }

Sleep(25);

    }

system("cls");
}

void getplayerNames(string a[][3]) //2-Player mode function for getting player names from input
{
    string PlayerX,Player0;
    std::cout<<"Enter player X's name\n";
    resetBuffer();
    getline(std::cin,PlayerX);
    system("cls");
    std::cout<<"Enter player 0's name\n";
    resetBuffer();
    getline(std::cin,Player0);
    game2p(a,PlayerX,Player0);

}
void game2p(string a[][3],string PlayerX, string Player0) //game function for 2-Player mode
{
 resetBuffer();
 while(GetAsyncKeyState(VK_RETURN)){}
short y=1, ymax=3,ok=1,c=0,ymin=1,culoarex=0,culoarey=0,x=0,xmin=0,xmax=4,botx=-1,boty=-1,contor=0,act=0;
while(ok==1){
     gotoxy(x,y);
    system("cls");
    std::cout<<"TicTacToe";
    for(short i=0;i<3;i++){
        std::cout<<"\n";
        for(short j=0;j<3;j++){
        if(culoarey==i && culoarex==j){
            textcolor(112);
            std::cout<<a[i][j]<<" ";
            textcolor(7);
        }
        else std::cout<<a[i][j]<<" ";
    }
    }
    gotoxy(x,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=1;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=2;
        }
        break;
    }
 if(GetAsyncKeyState(0x41))//a
    {
        x-=2;
        culoarex--;

        if(x<=xmin){
            x=0;
            culoarex=0;
        }
        break;
    }
 if(GetAsyncKeyState(0x44))//a
    {
        x+=2;
        culoarex++;

        if(x>=xmax){
            x=4;
            culoarex=2;
        }
        break;
    }
    if((a[0][0]=="X" && a[0][1]=="X" && a[0][2]=="X")|| (a[1][0]=="X" && a[1][1]=="X" && a[1][2]=="X") || (a[2][0]=="X" && a[2][1]=="X" && a[2][2]=="X") || (a[0][0]=="X" && a[1][0]=="X" && a[2][0]=="X") || (a[0][1]=="X" && a[1][1]=="X" && a[2][1]=="X") || (a[0][2]=="X" && a[1][2]=="X" && a[2][2]=="X") || (a[0][0]=="X" && a[1][1]=="X" && a[2][2]=="X") || (a[0][2]=="X" && a[1][1]=="X" && a[2][0]=="X"))
       {

        ok=0;
        system("cls");
        checkplayerList(0,PlayerX,Player0);
        winner2player(a,0,PlayerX,Player0);
        return;

}   else if((a[0][0]=="0" && a[0][1]=="0" && a[0][2]=="0")|| (a[1][0]=="0" && a[1][1]=="0" && a[1][2]=="0") || (a[2][0]=="0" && a[2][1]=="0" && a[2][2]=="0") || (a[0][0]=="0" && a[1][0]=="0" && a[2][0]=="0") || (a[0][1]=="0" && a[1][1]=="0" && a[2][1]=="0") || (a[0][2]=="0" && a[1][2]=="0" && a[2][2]=="0") || (a[0][0]=="0" && a[1][1]=="0" && a[2][2]=="0") || (a[0][2]=="0" && a[1][1]=="0" && a[2][0]=="0"))
       {

        ok=0;
        system("cls");
        checkplayerList(1,PlayerX,Player0);
        winner2player(a,1,PlayerX,Player0);
        return;

       }
    else if(contor==9){
        ok=0;
        system("cls");
        checkplayerList(2,PlayerX,Player0);
        winner2player(a,2,PlayerX,Player0);
        return;
        }
    else if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(act==0){
                if(a[culoarey][culoarex]!="X"&& a[culoarey][culoarex]!="0"){
                a[culoarey][culoarex]="X";
                contor+=1;
                act=1;}}
                else if(act==1)
                    if(a[culoarey][culoarex]!="X"&& a[culoarey][culoarex]!="0"){
                a[culoarey][culoarex]="0";
                contor+=1;
                act=0;

                }
break;
    }
    }
Sleep(25);
    }

system("cls");
}
void winner2player(string a[][3], short winner, string PlayerX, string Player0) //function to determine the winner of 2-Player mode
{
    short y=2,ymax=3,culoarey=0,ok=1,ymin=1;
char opt[2][20]={"Play again", "Main Menu"};
while(ok==1){
    system("cls");
    if(winner==0)
    std::cout<<"Player "<<PlayerX<<" wins!\n\n";
    else if(winner==1)
        std::cout<<"Player "<< Player0<<" wins!\n\n";
    else if(winner==2)
        std::cout<<"It's a draw!\n\n";
    for(short i=0;i<2;i++){
        if(culoarey==i)
            std::cout<<">>"<<opt[i]<<"\n";

        else std::cout<<opt[i]<<"\n";
    }
    gotoxy(0,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=2;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=3;
            culoarey=1;
        }
        break;
    }
     if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(culoarey==0){
                        system("cls");
                        citire(a);
                        game2p(a,PlayerX,Player0);
                ok=0;
                break;
            }
                else if(culoarey==1){
                    system("cls");
                    citire(a);
                    start(a);
                    ok=0;
                    break;
                }


    }

    }

Sleep(25);

    }

system("cls");
}
void checkplayerList(short winner, string PlayerX, string Player0) //checks if players already exist, if not adds them to the player list
{
    string filename="playerList.txt";
    int totalPlayers;
    bool noPlayers;
    bool pxExists=false;
    bool p0Exists=false;
    string name;
    int wins,losses,draws;
    float wlratio;
    ifstream playerListin;
    playerListin.open(filename.c_str());
    playerListin>>totalPlayers;
    playerListin.close();
    ofstream playerListout;
    if(totalPlayers==0)
    {
    noPlayers=true;
    totalPlayers=2;
    }
    Player *p= new Player[totalPlayers+1];
    Player px;
    Player p0;
    if(noPlayers==true)
    {
        if(winner==0)
        {
            p[0]=Player(PlayerX,1,0,0);
            p[1]=Player(Player0,0,1,0);
        }
        else if(winner==1)
        {
            p[0]=Player(PlayerX,0,1,0);
            p[1]=Player(Player0,1,0,0);
        }
        else if(winner==2)
        {
            p[0]=Player(PlayerX,0,0,1);
            p[1]=Player(Player0,0,0,1);
        }
        playerListout.open(filename);
        playerListout<<totalPlayers<<"\n";
        playerListout<<p[0].getName()<<"\n"<<p[0].getwinCount()<<"\n"<<p[0].getloseCount()<<"\n"<<p[0].getdrawCount()<<"\n"<<p[0].getwinlossRatio()<<"\n";
        playerListout<<p[1].getName()<<"\n"<<p[1].getwinCount()<<"\n"<<p[1].getloseCount()<<"\n"<<p[1].getdrawCount()<<"\n"<<p[1].getwinlossRatio()<<"\n";
        playerListout.close();
    }
    else
    {
        playerListin.open("playerList.txt");
        playerListin>>totalPlayers;
        for(int i=0;i<totalPlayers;i++)
        {
            playerListin>>name;
            playerListin>>wins;
            playerListin>>losses;
            playerListin>>draws;
            playerListin>>wlratio;
            p[i]=Player(name,wins,losses,draws);
        }
        playerListin.close();
        for(int i=0;i<totalPlayers;i++)
            if(PlayerX==p[i].getName())
            {
                if(winner==0)
                {
                p[i].updateWins();
                p[i].updatewlRatio();
                pxExists=true;
                break;
                }
                else if(winner==1)
                {
                    p[i].updateLosses();
                    p[i].updatewlRatio();
                    pxExists=true;
                    break;
                }
                else if(winner==2)
                    {
                    p[i].updateDraws();
                    pxExists=true;
                    break;
                    }
            }
        for(int i=0;i<totalPlayers;i++)
            if(Player0==p[i].getName())
            {
                if(winner==0)
                {
                p[i].updateLosses();
                p[i].updatewlRatio();
                p0Exists=true;
                break;
                }
                else if(winner==1)
                {
                    p[i].updateWins();
                    p[i].updatewlRatio();
                    p0Exists=true;
                    break;
                }
                else if(winner==2)
                    {
                    p[i].updateDraws();
                    p0Exists=true;
                    break;
                    }
            }
            playerListout.open("playerList.txt");
            if(pxExists==true && p0Exists==true)
            {
                playerListout<<totalPlayers<<"\n";
                for(int i=0;i<totalPlayers;i++)
                {
                    playerListout<<p[i].getName()<<"\n"<<p[i].getwinCount()<<"\n"<<p[i].getloseCount()<<"\n"<<p[i].getdrawCount()<<"\n"<<p[i].getwinlossRatio()<<"\n";
                }
            }
            else if(pxExists==false && p0Exists==true)
            {
                playerListout<<totalPlayers+1<<"\n";
                for(int i=0;i<totalPlayers;i++)
                {
                    playerListout<<p[i].getName()<<"\n"<<p[i].getwinCount()<<"\n"<<p[i].getloseCount()<<"\n"<<p[i].getdrawCount()<<"\n"<<p[i].getwinlossRatio()<<"\n";
                }
                if(winner==0)
                    playerListout<<PlayerX<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n";
                else if(winner==1)
                    playerListout<<PlayerX<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n";
                else if(winner==2)
                    playerListout<<PlayerX<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n";

            }
            else if(pxExists==true && p0Exists==false)
            {
                playerListout<<totalPlayers+1<<"\n";
                for(int i=0;i<totalPlayers;i++)
                {
                    playerListout<<p[i].getName()<<"\n"<<p[i].getwinCount()<<"\n"<<p[i].getloseCount()<<"\n"<<p[i].getdrawCount()<<"\n"<<p[i].getwinlossRatio()<<"\n";
                }
                if(winner==0)
                    playerListout<<Player0<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n";
                else if(winner==1)
                    playerListout<<Player0<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n";
                else if(winner==2)
                    playerListout<<Player0<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n";

            }
            else if(pxExists==false && p0Exists==false)
            {
                playerListout<<totalPlayers+2<<"\n";
                for(int i=0;i<totalPlayers;i++)
                {
                    playerListout<<p[i].getName()<<"\n"<<p[i].getwinCount()<<"\n"<<p[i].getloseCount()<<"\n"<<p[i].getdrawCount()<<"\n"<<p[i].getwinlossRatio()<<"\n";
                }
                if(winner==0)
                {
                    playerListout<<PlayerX<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n";
                    playerListout<<Player0<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n";
                }
                else if(winner==1)
                {
                    playerListout<<PlayerX<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n";
                    playerListout<<Player0<<"\n"<<1<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n";
                }
                else if(winner==2)
                {
                    playerListout<<PlayerX<<"\n"<<0<<"\n"<<0<<"\n"<<1<<"\n"<<0<<"\n";
                    playerListout<<Player0<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n";
                }
            }
            playerListout.close();
            delete[] p;
        }

    }
void Leaderboard(string a[][3]) //Leaderboard menu function
{
    string opt[3]={"Sort by most wins","Sort by best W/L ratio","Back to main menu"};
    short y=2, ymax=4,ok=1,c=0,ymin=2,culoarey=0;
while(ok==1){
    system("cls");
    std::cout<<"--> LEADERBOARD MENU <--\n\n";
    for(short i=0;i<3;i++){
        if(culoarey==i)
            std::cout<<">>"<<opt[i]<<"\n";

        else std::cout<<opt[i]<<"\n";
    }
    gotoxy(0,y);
    while(1==1){
     if(GetAsyncKeyState(0x57))//w
     {
         y--;
         culoarey--;
         if(y<=ymin){
            y=2;
            culoarey=0;}

     break;
     }
    if(GetAsyncKeyState(0x53))//s
    {
        y++;
        culoarey++;

        if(y>=ymax){
            y=4;
            culoarey=2;
        }
        break;
    }
     if (GetAsyncKeyState(VK_RETURN))
            {
                while (GetAsyncKeyState(VK_RETURN)) {}
                if(culoarey==0){
                        system("cls");
                        winSort(a);
                ok=0;
                return;

            }
                else if(culoarey==1){
                    system("cls");
                    wlratioSort(a);
                    ok=0;
                    return;
                }
                else if(culoarey==2){
                    system("cls");
                    start(a);
                    ok=0;
                    return;
                }


    }

    }

Sleep(25);

    }

system("cls");
}
void winSort(string a[][3]) //Filtering leaderboard by wins
{
    bool ok=true;
    while (GetAsyncKeyState(VK_RETURN)){}
    string filename="playerList.txt";
    int totalPlayers;
    string name;
    int wins,losses,draws;
    float wlratio;
    ifstream playerListin;
    playerListin.open(filename.c_str());
    playerListin>>totalPlayers;
    Player* p= new Player[totalPlayers+1];
    for(int i=0;i<totalPlayers;i++)
        {
            playerListin>>name;
            playerListin>>wins;
            playerListin>>losses;
            playerListin>>draws;
            playerListin>>wlratio;
            p[i]=Player(name,wins,losses,draws);
            p[i].updatewlRatio();
        }
    playerListin.close();
    Player temp;
    for(int i=0;i<totalPlayers-1;i++)
        for(int j=i+1;j<totalPlayers;j++)
    {
        if(p[j].getwinCount()>p[i].getwinCount())
        {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    while(ok==true){
    system("cls");
    std::cout<<setw(60)<<"Press the key 'ENTER' to go back\n\n\n";
    for(int i=0;i<totalPlayers;i++)
    {
        std::cout<<std::setw(4)<<i+1<<std::setw(10);
        p[i].print();
    }
    while(1==1){
    if (GetAsyncKeyState(VK_RETURN))
    {
        while(GetAsyncKeyState(VK_RETURN)){}
        ok=0;
        system("cls");
        Leaderboard(a);
        return;
    }
    }
    Sleep(25);
    }
    system("cls");
}
void wlratioSort(string a[][3]) //Filtering leaderboard by WIN/LOSS Ratio
{
    bool ok=true;
    while (GetAsyncKeyState(VK_RETURN)){}
    string filename="playerList.txt";
    int totalPlayers;
    string name;
    int wins,losses,draws;
    float wlratio;
    ifstream playerListin;
    playerListin.open(filename.c_str());
    playerListin>>totalPlayers;
    Player* p= new Player[totalPlayers+1];
    for(int i=0;i<totalPlayers;i++)
        {
            playerListin>>name;
            playerListin>>wins;
            playerListin>>losses;
            playerListin>>draws;
            playerListin>>wlratio;
            p[i]=Player(name,wins,losses,draws);
            p[i].updatewlRatio();
        }
    playerListin.close();
    Player temp;
    for(int i=0;i<totalPlayers-1;i++)
        for(int j=i+1;j<totalPlayers;j++)
    {
        if(p[j].getwinlossRatio()>p[i].getwinlossRatio())
        {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    while(ok==true){
    system("cls");
    std::cout<<setw(60)<<"Press the key 'ENTER' to go back\n\n\n";
    for(int i=0;i<totalPlayers;i++)
    {
        std::cout<<std::setw(4)<<i+1<<std::setw(10);
        p[i].print();
    }
    while(1==1){
    if (GetAsyncKeyState(VK_RETURN))
    {
        while(GetAsyncKeyState(VK_RETURN)){}
        ok=0;
        system("cls");
        Leaderboard(a);
        return;
    }
    }
    Sleep(25);
    }
    system("cls");
}




