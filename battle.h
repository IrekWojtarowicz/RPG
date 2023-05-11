#ifndef LAB12_BATTLE_H
#define LAB12_BATTLE_H

#include "characters.h"
#include "list.h"
#include "monsters.h"
#include "interface.h"
#include "items.h"

template <class T>
class battle {

public:
    lst_el * p;
    int start, start2;
    //new entry to list
    void newEntry(TsingleList &list, string log, int &i){
      p = new lst_el;
      p->key=i;
      p->name=log;
      list.push_head(p);
      if (list.size()>10) {
        list.rmTail();
      }
      i++;
    }

    item i;

    void startofthebattle() {
        attributes_interface a;
        string monsters_name, tempString, stat_name;
        cout << "Let's start the battle" << endl;
        character hero;
        monsters monster;

        do {
        start = hero.character_load();
        } while (start != 1);
        cout << endl;

        int stat0bon = 0;
        int stat1bon = 0;
        int stat2bon = 0;
        int stat3bon = 0;
        int stat4bon = 0;
        int healthbon = 0;

        if (hero.charitem == "Sword") {
            stat0bon = hero.charitembonus;
        } else if (hero.charitem == "Bow") {
            stat1bon = hero.charitembonus;
        } else if (hero.charitem == "Helmet") {
            stat2bon = hero.charitembonus;
        } else if (hero.charitem == "Wand") {
            stat3bon = hero.charitembonus;
        } else if (hero.charitem == "Lute") {
            stat4bon = hero.charitembonus;
        } else if (hero.charitem == "Potion") {
            healthbon = hero.charitembonus;
        } else if (hero.charitem == "none") {
        } else {
        }

        do {
        cout << "Input a name of the list with monsters that you'd like to fight with: ";
        cin >> monsters_name;
        start2 = monster.monsters_load(1, monsters_name);
        } while (start2 != 1);

        for (int j = 1; j < 6; j++) {
            int a;
            int am;

            monster.monsters_load(j, monsters_name);
            system("CLS");
            cout << "\tROUND " << j << endl;

                do {
                    hero.character_displayAll();
                    monster.simple_display();
                    cout << "\t Hero turn:" << endl;
                    cout << endl;
                    cout << "Choose your attack" << endl;
                    cout << "1.Strength attack" << endl;
                    cout << "2.Dexterity attack" << endl;
                    cout << "3.Endurance attack" << endl;
                    cout << "4.Intelligence attack" << endl;
                    cout << "5.Charisma attack" << endl;
                    cout << "6.Use your potion to heal" << endl;
                    cin >> a;
                    cout << "\tHero choice: " << a << endl;
                    switch (a) {
                        case 1: {
                            if (hero.statistics[0] + stat0bon >= monster.statistics[0]) {
                                monster.health = monster.health - (10 + stat0bon);
                                cout << "Monster attacked" << endl;
                                a=0;
                            }
                             else {
                                cout << "Monster dodged" << endl;
                                hero.health = hero.health - 5;
                            }
                             break;
                        }
                        case 2: {
                            if (hero.statistics[1] + stat1bon >= monster.statistics[1]) {
                                monster.health = monster.health - (10 + stat1bon);
                                cout << "Monster attacked" << endl;
                            }  else {
                                cout << "Monster dodged" << endl;
                                hero.health = hero.health - 5;
                            }
                            break;
                        }
                        case 3: {
                            if (hero.statistics[2] + stat2bon >= monster.statistics[2]) {
                                monster.health = monster.health - (10 + stat2bon);
                                cout << "Monster attacked" << endl;
                            }  else {
                                cout << "Monster dodged" << endl;
                                hero.health = hero.health - 5;
                            }
                            break;
                        }
                        case 4: {
                            if (hero.statistics[3] + stat3bon >= monster.statistics[3]) {
                                monster.health = monster.health - (10 + stat3bon);
                                cout << "Monster attacked" << endl;
                            }  else {
                                cout << "Monster dodged" << endl;
                                hero.health = hero.health - 5;
                            }
                            break;
                        }
                        case 5: {
                            if (hero.statistics[4] + stat4bon >= monster.statistics[4]) {
                                monster.health = monster.health - (10 + stat4bon);
                                cout << "Monster attacked" << endl;
                            }  else {
                                cout << "Monster dodged" << endl;
                                hero.health = hero.health - 5;
                            }
                            break;
                        }
                        case 6: {
                            if (hero.charitem == "Potion") {
                                hero.health += healthbon;
                            } else {
                                cout << "You don't have a health potion!" << endl;
                            }
                            break;
                        }

                    }


                    hero.character_displayAll();
                    monster.simple_display();
                    cout << "\t Monster turn:" << endl;
                    cout << "Choose your attack" << endl;
                    cout << "1.Strength attack" << endl;
                    cout << "2.Dexterity attack" << endl;
                    cout << "3.Endurance attack" << endl;
                    cout << "4.Intelligence attack" << endl;
                    cout << "5.Charisma attack" << endl;
                    am = rand() % 5 +1;
                    cout <<"\tMonster choice:" << am << endl;

                    switch (am) {
                        case 1: {
                            if (hero.statistics[0] + stat0bon > monster.statistics[0]) {
                                monster.health = monster.health - 5;
                                cout << "Hero dodged" << endl;
                            } else {
                                cout << "Hero attacked" << endl;
                                hero.health = hero.health - 10;
                            }
                            break;
                        }
                        case 2: {
                            if (hero.statistics[1] + stat1bon > monster.statistics[1]) {
                                monster.health = monster.health - 5;
                                cout << "Hero dodged" << endl;
                            }  else {
                                cout << "Hero attacked" << endl;
                                hero.health = hero.health - 10;
                            }
                            break;
                        }
                        case 3: {
                            if (hero.statistics[2] + stat2bon > monster.statistics[2]) {
                                monster.health = monster.health - 5;
                                cout << "Hero dodged" << endl;
                            }  else {
                                cout << "Hero attacked" << endl;
                                hero.health = hero.health - 10;
                            }
                            break;

                        }
                        case 4: {
                            if (hero.statistics[3] + stat3bon > monster.statistics[3]) {
                                monster.health = monster.health - 5;
                                cout << "Hero dodged" << endl;
                            }
                            else {
                                cout << "Hero attacked" << endl;
                                hero.health = hero.health - 10;
                            }
                            break;
                        }
                        case 5: {
                            if (hero.statistics[4] + stat4bon > monster.statistics[4]) {
                                monster.health = monster.health - 5;
                                cout << "Hero dodged" << endl;
                            }  else {
                                cout << "Hero attacked" << endl;
                                hero.health = hero.health - 10;
                            }
                            break;
                        }

                    }


                } while (hero.health > 0 && monster.health > 0);
            if (hero.health <= 0){
                cout << endl;
                cout << "You lost " << endl;
                tempString = "You lost with " + monster.name + ".";
                newEntry(hero.battleHistory, tempString, hero.battleHistoryIterator);
                int losex;
                losex=hero.experience-monster.experience;
                if (losex<0) {
                    hero.maxexperiencelvl = hero.maxexperiencelvl / 1.2 / hero.level;
                    hero.level = hero.level - 1;
                    hero.experience = hero.maxexperiencelvl+losex;

                }
                else {
                    hero.experience=losex;
                }
                hero.health=100;
                hero.character_displayHistory();
                hero.character_save();
                j=7;

            }
            else if(monster.health <= 0){
                cout << endl;
                cout << "You won" << endl;
                tempString = "You won with " + monster.name + ".";
                i.itempool(j);
                newEntry(hero.battleHistory, tempString, hero.battleHistoryIterator);
                int newex;
                newex=hero.experience+monster.experience;
                if (newex>=hero.maxexperiencelvl) {
                    hero.experience = newex % hero.maxexperiencelvl;
                    hero.level = hero.level + 1;
                    hero.maxexperiencelvl = hero.maxexperiencelvl * 1.2 * hero.level;

                }
                else {
                    hero.experience=newex;
                }
                hero.health=100;
                hero.character_displayHistory();
                hero.character_save();
                if (j<5){
                    cout << "Go to the next round" <<endl;
                    cout << "1.Yes" <<endl;
                    cout << "2.No" <<endl;
                    int ch;
                    cin >> ch;
                    if (ch==1){
                        cout << "Loading next monster..." << endl;
                        cout << endl;
                    }
                    else if (ch==2){
                        system("CLS");
                        cout <<"See you next time" << endl;
                        cout << endl;
                        j=7;
                    }
                }
            }
            }
        };
    };
#endif //LAB12_BATTLE_H
