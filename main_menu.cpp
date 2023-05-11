#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <cstring>
#include "windows.h"

#include "characters.h"
#include "monsters.h"
#include "battle.h"

using namespace std;

int decision, stop=0, choice, to_menu = 0;
string name_list, fname1="inventory.txt", fname2="inventory1.txt";

//main menu that is visible at the beginning
void main_menu(){

    fstream fs1;
	fs1.open(fname1, ios::in);
	if (!fs1){
		ofstream fout1(fname1);
		if (fout1){
			fout1.close();
		}
	}

	fstream fs2;
	fs2.open(fname2, ios::in);
	if (!fs2){
		ofstream fout2(fname2);
		if (fout2){
			fout2.close();
		}
	}

    character characterObj;
    monsters m1;
    monsters m2;
    monsters m3;
    monsters m4;
    monsters m5;

    while(stop!=1){
        cout << "Welcome in RPG character creator program." << endl;
        cout << "1. Add a new character" << endl;
        cout << "2. Load previously created character" << endl;
        cout << "3. Generate a list with random monsters." << endl;
        cout << "4. Load previously created list of monsters." << endl;
        cout << "5. Start a battle" << endl;
        cout << "6. Check your inventory" << endl;
        cout << "7. Find an item" << endl;
        cout << "8. Rules" << endl;
        cout << "9. Exit" << endl << endl;
        cout << "Choose an action from the list above: ";
        cin >> decision;
        system("CLS");

        switch (decision){
            case 1:
                characterObj.character_add();
                break;
            case 2:
                characterObj.character_load();
                break;
            case 3:
                cout << "Input name of your monsters list: ";
                cin >> name_list;
                cout << endl;
                m1.monster_create(1, name_list);
                m2.monster_create(2, name_list);
                m3.monster_create(3, name_list);
                m4.monster_create(4, name_list);
                m5.monster_create(5, name_list);
                cout << "Your monsters list has been saved successfully!" << endl << endl;
                break;
            case 4:
                cout << "Input monsters list's name you would like to load: ";
                cin >> name_list;
                cout << endl;
                m1.monsters_load(1, name_list);
                m2.monsters_load(2, name_list);
                m3.monsters_load(3, name_list);
                m4.monsters_load(4, name_list);
                m5.monsters_load(5, name_list);
                break;
            case 5: {
                battle<int> startbattle;
                startbattle.startofthebattle();
                break;
            }
            case 6: {
                item i;
                i.inventory();
                break;
            }
            case 7: {
                item i;
                cout<<"Enter the name of the item you are looking for: "<<endl;
                string find, l;
                cin>>find;
                ifstream f ("inventory1.txt");
                int c=0;
                while (getline(f,l)){
                    c++;
                }
                i.itemfind(1,find,c);
                break;
            }
            case 8: {

                while(to_menu!=1){
                    cout << "1. At the beginning of the battle you'll have to choose your character." << endl;
                    cout << "2. Next step is to choose list with monsters. You will fight with each monster from the provided list \n(in each round you'll fight with higher lvl monster)." << endl;
                    cout << "3. After each round you: \n\t-can save your progress. \n\t-will be asked if you want to fight in next round with another monster or if you'd like to \n\tleave battleground." << endl;
                    cout << "4. Each round is divided into to turns: hero, monster." << endl;
                    cout << "5. In each round you can use different type of attack - based on different statistics." << endl;
                    cout << "6. If the statistic, that you decided to attack with, is: \n\t-higher/equal to monster's, you'll deal 10 damage. \n\t-lower than monster's, monster will dodge and counterattack dealing you 5 health points." << endl;
                    cout << "7. In case of monster's turn: it looks the same as it was for player in points \"5.\" and \"6.\" above." << endl;
                    cout << "8. After each fight before saving your character, the program will show you battle history." << endl;
                    cout << "9. After each won fight you obtain an item which you can 'wear' in main menu." << endl;
                    cout << "10. Remember that you must have inventory.txt and inventory1.txt in the folder with game files." << endl;
                    cout << "11. If you want to delete items you can just delete them in inventory files." << endl;
                    cout << "12. All heroes use inventory.txt and inventory1.txt, so if you want to play as different hero, \nyou have to upload his inventory files." << endl;
                    cout << "13. The program is case sensitive." << endl << endl << endl << endl << endl << endl;

                    cout << "Do you want to go back to the main menu? " << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No" << endl;
                    cin >> choice;

                    if(choice==1){
                        to_menu=1;
                        system("CLS");
                    }else {
                        to_menu=0;
                        system("CLS");
                    }

                };
                break;
            }
            case 9: {
                stop = 1;
                cout << "See you later, alligator!" << endl;
                break;
            }
            default: {
                system("CLS");
                cout << "Choose proper action!" << endl << endl;
                break;
            }
        }
        decision = 0;
    }
}
