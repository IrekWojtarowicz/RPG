#ifndef LAB12_MONSTERS_H
#define LAB12_MONSTERS_H
#include "interface.h"
#include "characters.h"

using namespace std;

class monsters : public character{
public:

    monsters(string="",string="",int=0,int=0,int=0,int=0, int=0, int=0, int=0, int=0, int=0);
    ~monsters();

    void monsters_save(int j, string name_list);
    int monsters_load(int j, string monsters_name);
    void stats_generator(int j);
    void monster_create(int j, string name_list);
};

#endif //LAB12_MONSTERS_H
