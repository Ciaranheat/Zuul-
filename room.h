#include <iostream>
#include <string.h>
#include <map>
#include "item.h"

using namespace std;

class room {
 public: //Makes the info public to the other classes 
  room(string newname, string newdesc);
  ~room();

  string getName();
  string getDescription();
  string getExits();

  void setName(string);
  void setDescription(string);
  string showItems();
  void pickupItem(string, item& playerbucket);
  void dropItem(string, item& playerbucket);
  void setItems(int,int,int,int,int);
  void setExits(room*n, room* s, room* e, room* w);
  room* goExit(string newExit);

  item itemList;
 private:
  string name;
  string description;

  map<string,room*> exitMap;
  
};
