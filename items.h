#ifndef LAB15_ITEMS_H
#define LAB15_ITEMS_H

#include <string>
#include <cstdio>
#include <cstdlib>
#include "characters.h"

using namespace std;

struct snode
{   string namee;
    int numberr;
    string statt;
    snode *next;
    snode *prev;
};

struct slist
{
    int length;
    snode *head;
    snode *tail;
};

class item{
public:
    string itemname[7]={"Stick of truth", "Potion","Lute","Wand" ,"Helmet" ,"Bow" ,"Sword"};
    string itemability[7]={"Nothing","Health","Charisma","Intelligence","Endurance", "Dexterity", "Strength"};
    int itembonus;
    int pool;


    virtual void itempool(int j);
    virtual void saveitem(int pool);
    virtual void saveitemname(int pool);
    virtual void itemhero(int it);
    virtual void itemfind(int n, string find, int c);
    virtual void finddisplay(int j, int g, int a);


    virtual void inventory();
    virtual void readFile(slist &list);

};





#endif //LAB15_ITEMS_H
