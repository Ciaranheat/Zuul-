#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string.h>

using namespace std;

class item{
 public :
  item();
  ~item();

  void inivItems(int, int, int, int, int);
  string showItems();
  bool addItem(string newname);
  bool deleteItem(string newname);
  int itemCount();

  int itemInv[5];

  string itemName[5];

};

#endif
