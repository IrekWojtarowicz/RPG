#ifndef LAB12_INTERFACE_H
#define LAB12_INTERFACE_H

#include <iostream>
#include <string>
using namespace std;

class attributes_interface{
public:
    int statistics[5];
    string name;
    string statistics_name[5]={"Strength", "Dexterity", "Endurance", "Intelligence", "Charisma"};
    string profession;
    int experience;
    int level;
    int maxexperiencelvl;
    int health;
    int maxhealth = 100;
    string charitem;
    int charitembonus;
    string charitemstat;

    //used to display information in simple form
    virtual void simple_display(){
        cout << "Info about: " << name << endl;
        cout << "Profession: " << profession << endl;
        cout << "Level: " << level << endl;
        cout << "Experience: "<< experience << "/" << maxexperiencelvl << endl;
        cout << "Health: "<< health << "/" << maxhealth << endl;
        for (int i=0; i<5; i++){
            cout << statistics_name[i] << ": " << statistics[i] << endl;
        }
        cout << endl << endl;
    };



    virtual ~attributes_interface(){};
};

class methods_interface{
public:
    virtual void profession()=0;
    virtual ~methods_interface(){};
};


#endif //LAB12_INTERFACE_H
