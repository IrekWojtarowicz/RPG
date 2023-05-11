#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "monsters.h"
#include "interface.h"

monsters::monsters (string n, string p, int l, int ex, int mex, int h, int s, int d, int e, int i, int c) {
name = n;
profession = p;
level=l;
experience=ex;
maxexperiencelvl=mex;
health=h;
statistics[0] = s;
statistics[1] = d;
statistics[2] = e;
statistics[3] = i;
statistics[4] = c;
}

monsters::~monsters(){
}


//used to generate random values of each statistic
void monsters::stats_generator(int j){

string monstertype[11]={"Dragon","Orc","Vampire","Goblin","Ghoul","Harpy","Demon","Basilisk","Troll","Zombie","Skeleton"};
int no = rand() % 10;
name = monstertype[no];
profession = "Monster";
level = 0+j;
maxexperiencelvl = level*10;
experience = rand() % 11 + (level-1)*10;
health = 100;
statistics[j,0]=rand() % 11 + (level+2);
statistics[j,1]=rand() % 11 + (level+2);
statistics[j,2]=rand() % 11 + (level+2);
statistics[j,3]=rand() % 11 + (level+2);
statistics[j,4]=rand() % 11 + (level+2);
};

//used to save freshly generated list of monsters
void monsters::monsters_save(int j, string name_list){

    string filename = name_list + to_string(j) + ".txt";
            ofstream file_save(filename.c_str(), ios::app);
                    file_save << name << endl;
                    file_save << profession << endl;
                    file_save << level << endl;
                    file_save << experience << endl;
                    file_save << maxexperiencelvl << endl;
                    file_save << health << endl;
                for (int i=0; i<5; i++){
                    file_save << statistics[j,i] << endl;
                }
            file_save.close();

}

//used to load data connected to the monsters from a file
int monsters::monsters_load(int j, string monsters_name){
    string text;
    int flag;
    string filename = monsters_name + to_string(j) + ".txt";
            fstream file_load;
            file_load.open(filename.c_str(), ios::in);
            if(file_load.good()==true){ //checking whether requested file with information about character exists

                        file_load>>name;
                        file_load>>profession;
                        file_load>>level;
                        file_load>>experience;
                        file_load>>maxexperiencelvl;
                        file_load>>health;

                        for(int i=0; i<5; i++){ //used to read 5 different statistics
                            getline(file_load, text);
                            file_load>>statistics[i];
                        };
                        simple_display();
                        flag = 1;
            }else {
                cout << "Such list doesn't exist :c" << endl << endl;
                flag = 0;
            }
            file_load.close();
    return flag;
}

//used in the process of creating monsters
void monsters::monster_create(int j, string name_list){
    stats_generator(j);
    simple_display();
    monsters_save(j, name_list);
}
