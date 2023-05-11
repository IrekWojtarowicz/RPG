#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "windows.h"

#include "interface.h"
#include "characters.h"
#include "monsters.h"
#include "battle.h"
#include "list.h"
#include "items.h"
using namespace std;

void main_menu();

int main(){
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 725, TRUE);
    srand(time(0)); // giving the random number generator a seed based on the current time
    main_menu();
}
