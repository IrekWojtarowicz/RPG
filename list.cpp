#include <iostream>

#include "list.h"

using namespace std;

  TsingleList::TsingleList(){
    head = tail = NULL;
    cnt = 0;
  }
  TsingleList::~TsingleList(){
    lst_el * el;
    while(head){
      el = head->next;
      delete head;
      head = el;
    }
  }
  //returning size
  unsigned TsingleList::size(){
    return cnt;
  }
  //adding element at the front of the list
  lst_el * TsingleList::push_head(lst_el * el){
    el->next = head;
    head = el;
    if(!tail) tail = head;
    cnt++;
    return head;
  }
  //adding element at the end of the list
  lst_el * TsingleList::push_tail(lst_el * el){
    if(tail) tail->next = el;
    el->next = NULL;
    tail = el;
    if(!head) head = tail;
    cnt++;
    return tail;
  }
  //adding element el1 after element el2
  lst_el * TsingleList::insert(lst_el * el1, lst_el * el2){
    el1->next = el2->next;
    el2->next = el1;
    if(!(el1->next)) tail = el1;
    cnt++;
    return el1;
  }
  //deleting first element of the table
  lst_el * TsingleList::rmHead(){
    lst_el * el;
    if(head){
      el = head;
      head = head->next;
      if(!head) tail = NULL;
      cnt--;
      return el;
    } else return NULL;
  }
  //deleting last element of the list
  lst_el * TsingleList::rmTail(){
    lst_el * el;
    if(tail){
      el=tail;
      if(el==head) head = tail = NULL;
      else{
        tail = head;
        while(tail->next != el) tail = tail->next;
        tail->next = NULL;
      }
      cnt--;
      return el;
    } else return NULL;
  }
  //deleting e1 element of the list
  lst_el * TsingleList::erase(lst_el * el){
    lst_el * el1;
    if(el == head) return rmHead();
    else{
      el1 = head;
      while(el1->next  != el) el1 = el1->next;
      el1->next = el->next;
      if(!(el1->next)) tail = el1;
      cnt--;
      return el;
    }
  }
  //returning nth element of the list
  lst_el * TsingleList::index(int n){
    lst_el * el;
    if((!n) || (n>cnt)) return NULL;
    else if(n == cnt) return tail;
    else{
      el = head;
      while(--n) el = el->next;
      return el;
    }
  }
  //methods used to display data stored in the list
  void TsingleList::showKeys(){
    lst_el * el;
    if(!head) cout << "List is empty." << endl;
    else{
      el = head;
      while(el){
        cout<<el->key<<"";
        el = el->next;
      }
      cout<<endl;
    }
  }
  void TsingleList::showNames(){
    lst_el * el;
    if(!head) cout << "List is empty." << endl;
    else{
      el=head;
      while(el){
        cout<<el->name<<""<<endl;
        el=el->next;
      }
      cout<<endl;
    }
  }
  void TsingleList::showElements(){
    lst_el * el;
    if(!head) cout << "List is empty." << endl;
    else{
      el=head;
      while(el){
        cout<<"Name: "<<el->name<<", key: "<<el->key<<endl;
        el=el->next;
      }
      cout<<endl;
    }
  }
