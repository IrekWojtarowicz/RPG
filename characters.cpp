#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

#include "characters.h"



string statistics_name[5]={"Strength", "Dexterity", "Endurance", "Intelligence", "Charisma"};
int ExitFlag=0, decision2;

character::character (string n, string p, int l, int ex, int mex, int h, int s, int d, int e, int i, int c, string ci, int cib, string cis) {
name = n;
profession = p;
level = l;
experience=ex;
maxexperiencelvl=mex;
health=h;
statistics[0] = s;
statistics[1] = d;
statistics[2] = e;
statistics[3] = i;
statistics[4] = c;
charitem = ci;
charitembonus = cib;
charitemstat = cis;
}

character::~character(){
}

//used to create new character
void character::character_add(){
    cout << "Enter your character's name: ";
    cin >> name;

    for (int i=0; i<5; i++){
        cout << "Enter value of " << statistics_name[i] << " (0-10): ";
        cin >> statistics[i];
        while (statistics[i]>10 || statistics[i]<0){
            cout << "You have to use values from 0 to 10!" << endl;
            cout << "Enter value of " << statistics_name[i] << " (0-10): ";
            cin >> statistics[i];
        }
    }


    level = 1;
    experience = 0;
    maxexperiencelvl = 100;
    health = 100;


    //creating objects
    warrior w;
    mage m;
    thief t;
    berserker br;
    bard b;
    guardian g;
    character ch(name, profession, level, experience, maxexperiencelvl, health, statistics[0], statistics[1], statistics[2], statistics[3], statistics[4]);
    choose_profession(ch, w, m, t, br, b, g);
    ch.character_save();
}

//used to save created character
void character::character_save(){
    while (ExitFlag==0){
        cout << endl << "Would you like to save your character?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Option: ";
        cin >> decision2;

        system("CLS");

        switch (decision2){
            case 1:{
                cout << "Your character has been saved successfully!" << endl << endl;
                string filename = name + ".txt";
                ofstream file_save(filename.c_str());
                file_save << name << endl;
                file_save << profession << endl;
                file_save << level<<endl;
                file_save << experience<<endl;
                file_save << maxexperiencelvl<<endl;
                file_save << health<<endl;
                for (int i=0; i<5; i++){
                    file_save << statistics[i] << endl;
                }
                file_save << charitem << endl;
                file_save << charitembonus << endl;
                file_save << charitemstat << endl;
                file_save.close();
                ExitFlag = 1;
                break;}
            case 2:
                cout << "You've abandoned your character's creation process." << endl << endl;
                ExitFlag = 1;
                break;
            default:
                system("CLS");
                ExitFlag=0;
                cout << "Choose proper action!" << endl;
                break;
        }
    }
    decision2 = 0;
    ExitFlag = 0;
}

//used to load data connected to the character from a file
int character::character_load(){
    int flag;
    string character_name, text;
    cout << "Type in character's name that you want to load: ";
    cin >> character_name;
    system("CLS");

    string filename = character_name + ".txt";
    fstream file_load;
    file_load.open(filename.c_str(), ios::in);
    if(file_load.good()==true){ //checking whether requested file with information about character exists

        do{
            file_load>>name;
            file_load>>profession;
            file_load>>level;
            file_load>>experience;
            file_load>>maxexperiencelvl;
            file_load>>health;


            for(int i=0; i<5; i++){
                getline(file_load, text);
                file_load>>statistics[i];
            }

            file_load>>charitem;
            file_load>>charitembonus;
            file_load>>charitemstat;
        }while(!file_load.eof());

        character ch(name, profession, level, experience, maxexperiencelvl, health, statistics[0], statistics[1], statistics[2], statistics[3], statistics[4], charitem, charitembonus, charitemstat);
        ch.character_displayAll();
        flag = 1;

    }else {
        cout << "Such character doesn't exist :c" << endl << endl;
        flag = 0;
    }
    file_load.close();
    return flag;
}

//used to choose profession of a new character
void character::choose_profession(character &ch, warrior &w, mage &m, thief &t, berserker &br, bard &b, guardian &g){
    while(ExitFlag==0){
        cout << endl << "List of all possible professions:" << endl;
        cout << "1. Warrior" << endl;
        cout << "2. Mage" << endl;
        cout << "3. Thief" << endl;
        cout << "4. Berserker" << endl;
        cout << "5. Bard" << endl;
        cout << "6. Guardian" << endl;
        cout << "Choose your profession: ";
        cin >> decision2;


        switch (decision2){
            case 1:
                w.profession(ch);
                ExitFlag=1;
                break;
            case 2:
                m.profession(ch);
                ExitFlag=1;
                break;
            case 3:
                t.profession(ch);
                ExitFlag=1;
                break;
            case 4:
                br.profession(ch);
                ExitFlag=1;
                break;
            case 5:
                b.profession(ch);
                ExitFlag=1;
                break;
            case 6:
                g.profession(ch);
                ExitFlag=1;
                break;
            default:
                system("CLS");
                cout << "Choose proper action!" << endl;
                ExitFlag=0;
                break;
            }
    }
    decision2 = 0;
    ExitFlag = 0;
}

//used to display information about previously created character
void character::character_displayAll(){
        cout << "Info about: " << name << endl;
        cout << "Profession: " << profession << endl;
        cout << "Level: " << level << endl;
        cout << "Experience: "<< experience << "/" << maxexperiencelvl << endl;
        cout << "Health: "<< health << "/" << maxhealth << endl;
        for (int i=0; i<5; i++){
            cout << statistics_name[i] << ": " << statistics[i] << endl;
        }
        if (charitembonus != 0){
            cout << "Item: " << charitem << " + " << charitembonus << " " << charitemstat << endl;
            cout << endl << endl;
        } else {
            cout << "Item: Bare hands (no effect)" << endl;
            cout << endl << endl;
        }
    };

//used to display information about battle history
void character::character_displayHistory(){
        cout << endl;
        cout << "Battle history: " << endl;
        battleHistory.showNames();
        cout << endl << endl;
    };

