#ifndef list_hpp
#define list_hpp

using namespace std;

struct lst_el{
  lst_el * next;
  int key;
  string name;
};

//definition of a singly listed list class
class TsingleList{
  lst_el * head, * tail;
  int cnt;
public:
  TsingleList();
  ~TsingleList();
  //returning size
  unsigned size();
  //adding element at the front of the list
  lst_el * push_head(lst_el * el);
  //adding element at the end of the list
  lst_el * push_tail(lst_el * el);
  //adding element el1 after element el2
  lst_el * insert(lst_el * el1, lst_el * el2);
  //deleting first element of the table
  lst_el * rmHead();
  //deleting last element of the list
  lst_el * rmTail();
  //deleting e1 element of the list
  lst_el * erase(lst_el * el);
  //returning nth element of the list
  lst_el * index(int n);
  //methods used to display data stored in the list
  void showKeys();
  void showNames();
  void showElements();
};

#endif
