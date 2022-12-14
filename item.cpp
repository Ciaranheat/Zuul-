#include <iostream>
#include <string.h>
#include "item.h"

using namespace std;

item :: item() {

  itemName[0] = "Controller";
  itemName[1] = "Phone";
  itemName[2] = "Money";
  itemName[3] = "Laptop";
  itemName[4] = "Keys";

  itemInv[0] = 0;
  itemInv[1] = 0;
  itemInv[2] = 0;
  itemInv[3] = 0;
  itemInv[4] = 0;
  
}

item :: ~item() {

}

void item :: inivItems(int i1, int i2, int i3, int i4, int i5) {
  itemInv[0] = i1;
  itemInv[1] = i2;
  itemInv[2] = i3;
  itemInv[3] = i4;
  itemInv[4] = i5;
}

string item :: showItems() {
  string out = " ";

  for (int i = 0; i < 5; i++) {
    if (itemInv[i] > 0) {
      out = out + " " + itemName[i];
    }
    }
  return out;
}

bool item :: addItem(string newname) {
  for (int i = 0; i < 5; i++) {
    if (itemName[i] == newname) {
	itemInv[i] = 1;
	return true;
      }
  }
    return false;
}

  bool item :: deleteItem(string newname) {
    for  (int i = 0; i < 5; i++) {
      if (itemName[i] == newname) {
	itemInv[i] = 0;
	return true;
      }
    }
    return false;
  }

int item :: itemCount() {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (itemInv[i] >= 1) count ++;
  }
  return count;
}
