#ifndef LAB12_CHARACTERS_H
#define LAB12_CHARACTERS_H

#include "interface.h"
#include "list.h"

using namespace std;

class warrior; //endurance
class mage; //intelligence
class thief; //dexterity
class berserker; //strength
class bard; //charisma
class guardian; //endurance and strength

class character : public attributes_interface{
public:
    character(string="", string="", int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, string="", int=0, string="");
    ~character();
    void character_add();
    void character_save();
    int character_load();
    void character_displayAll();
    void character_displayHistory();
    TsingleList battleHistory;
    int battleHistoryIterator = 1;

    friend class warrior;
    friend class mage;
    friend class thief;
    friend class berserker;
    friend class bard;
    friend class guardian;

    void choose_profession(character &ch, warrior &w, mage &m, thief &t, berserker &br, bard &b, guardian &g);
};

class warrior{
public:
    void profession(character &ch){
        ch.profession = "Warrior";
        // bonus endurance points
        ch.statistics[2]+=3;
    }
};

class mage{
public:
    void profession(character &ch){
        ch.profession = "Mage";
        // bonus intelligence points
        ch.statistics[3]+=3;
    }
};

class thief{
public:
    void profession(character &ch){
        ch.profession = "Thief";
        // bonus dexterity points
        ch.statistics[1]+=3;
    }
};

class berserker{
public:
    void profession(character &ch){
        ch.profession = "Berserker";
        // bonus strength points
        ch.statistics[0]+=3;
    }
};

class bard{
public:
    void profession(character &ch){
        ch.profession = "Bard";
        // bonus charisma points
        ch.statistics[4]+=3;
    }
};

class guardian{
public:
    void profession(character &ch){
        ch.profession = "Guardian";
        // bonus endurance and health points
        ch.statistics[2]+=2; //endurance
        ch.statistics[0]+=1; //strength
    }
};

#endif //LAB12_CHARACTERS_H
