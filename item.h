#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string.h>

using namespace std;

class item{
 public :
  item();
  item~();

  void inivitems(int, int, int, int, int);
  string showitems();
  bool addItem(steing newname);
  bool deleteitem(string newname);
  int itemcount();

  int iteminv[5];

  string itemname[5];

};

#endif
