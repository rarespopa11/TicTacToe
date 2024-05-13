
#include <windows.h>
#include <conio.h>
#include "func.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main(){
string a[3][3];
citire(a);
srand(time(0));
start(a);



return 0;
}
