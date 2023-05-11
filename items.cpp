#include <sstream>
#include <fstream>
#include "items.h"

void item::itempool(int j) {
    pool=rand() %2+j;
    itembonus= rand() % 5 + (j+2);
    if (pool==0){
        itembonus=0;
    }
    else if(pool==1){
        itembonus=25;
    }
    cout << "You got " << itemname[pool] << " increasing " << itemability[pool] << " by " << itembonus << endl;
    cout << endl;

    //stackable
    string items;
    int c[100];
    int is=0;
    bool check;
    ifstream fin("inventory1.txt");
    if( fin.good() == true ) {
        while (getline(fin, items)) {
            fin >>items;
            //cout<<items<<endl;

            if(items==itemname[pool]){
                c[is]=1;
            }
            else{
                c[is]=0;
            }
            is++;

        }
        int st;
        for (st=0;st<is;st++) {
            //cout << c[st] << ""<< endl;
            if(c[st]==1){
                check=1;
            }
        }
        //cout<<check<<endl;

        switch(check){
            case 1:{
                cout<<"You already have that item"<<endl;
                break;
            }
            case 0:{
                saveitem(pool);
                saveitemname(pool);

                break;
            }
        }
    }
    //

};

void item::saveitem(int pool){
    fstream file;
    file.open( "inventory.txt", ios_base::app );
    if( file.good() == true ) {
        file<<itemname[pool]<<endl;
        file<<itembonus<<endl;
        file<<itemability[pool]<<endl;
        file<<""<<endl;
        file.close();
    }
    else {
        cout << "File access forbidden!" << endl;
    }

};

void item::saveitemname(int pool) {
    fstream file;
    file.open("inventory1.txt", ios_base::app);
    if (file.good() == true) {
        file << itemname[pool] << endl;
        file.close();
    } else {
        cout << "File access forbidden!" << endl;
    }
};

void item::inventory(){
    slist list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;

    readFile(list);
    string m;
    snode *node = list.head;
    for(int i = 0; i < list.length-1; i++)
    {
         int no=i+1;
        cout << no << ". " << node->namee << " " << node->numberr << " " << node->statt << endl;
        m=node->statt;
        node = node->next;



    }
    cout<<endl;
    cout<<"Do you want to add item to your character?"<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.No (back to main menu)"<<endl;
    int cho;
    cin>>cho;
    if(cho==1){
    cout<<endl;
    cout<<"Select item: "<<endl;
    int it;
    cin>>it;
    itemhero(it);
    }
    else if (cho==2){
    system("CLS");
    }

};

void item::readFile(slist &list)
{
    ifstream fin("inventory.txt");
    while(fin.good())
    {
        snode *node = new snode;
        if(list.head == NULL)
        {
            node->prev = NULL;
            node->next = NULL;
            list.head = node;
            list.tail = node;
        }
        else
        {
            list.tail->next = node;
            node->prev = list.head;
            node->next = NULL;
            list.tail = node;
        }
        fin>>node->namee;
        fin>>node->numberr;
        fin>>node->statt;
        list.length++;

        string blankline;
        if(!getline(fin, blankline))
            break;
    }
};

void item::itemhero(int it){
    character ch;
    ch.character_load();

    slist list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;

    readFile(list);
    string m;
    snode *node = list.head;
    for(int i = 0; i < it; i++)
    {

        ch.charitem=node->namee;
        ch.charitembonus=node->numberr;
        ch.charitemstat=node->statt;
        node = node->next;
    }
    cout<<"Loading item"<<endl;
    ch.character_displayAll();
    ch.character_save();
};


void item::itemfind(int n,string find,int c) {
    int line, line_storage[7];
    ifstream file ("inventory1.txt");
    string s;
    bool stop;

    for (int i = 0; i < 7; i++){
        line_storage[i] = (i*4)+1;
    }

    do {
            for (int i = 1; i <= n; i++) {
                getline(file, s);
                if (s == find) {
                    line = i;
                    if (line == 1) {
                        finddisplay(line, line+1, line+2);
                    }
                    else{
                        finddisplay(line_storage[line-1], line_storage[line-1]+1, line_storage[line-1]+2);
                    }
                    stop = 1;
                }
            }

            if (line == 0) {
                if (n == c){
                    cout << "No such item in your inventory" << endl;
                    cout << endl;
                    stop = 1;
                }
                else {
                    itemfind(n + 1, find, c);
                }
            }
    }while(stop=0);
};


void item::finddisplay(int j, int g, int a){
    ifstream file ("inventory.txt");
    string s;
    string c[400];

        for (int i = 1; i <= a; i++) {
            getline(file,c[i]);
            if (i == j){
                cout << c[i-1] << endl;
            }
        }

    cout << "Your item:\n" << c[j] << " increasing " << c[a] << " by " << c[g] << endl;
    cout << endl;
}
