#inlcude <iostream>
#include <string.h>
#include "item,h"

using namespace std;

item :: item() {

  itemname[0] = "Controller";
  itemname[1] = "Phone";
  itemname[2] = "Money";
  itemname[3] = "Laptop";
  itemname[4] = "Keys";

  iteminv[0] = 0;
  iteminv[1] = 0;
  iteminv[2] = 0;
  iteminv[3] = 0;
  iteminv[4] = 0;
  
}

item :: ~item() {

}

void item :: inivitems(int i1, int i2, int i3, int i4, int i4) {
  iteminv[0] = i1;
  iteminv[1] = i2;
  iteminv[2] = i3;
  iteminv[3] = i4;
  iteminv[4] = i5;
}

string item :: showitems() {
  string out = " ";

  for (int i = 0; i < 5; i++) {
    if (iteminv[i] > 0) {
      out = out + " " + itemname[i];
    }
    }
  return out;
}

bool item :: additem(string newname) {
  for (int i = 0; i < 5; i++) {
    if (itemname[i] = newname) {
	iteminv[i] = 1;
	return true;
      }
  }
    return false;
}

  bool item :: deleteitem(string newname) {
    for  (int i = 0; i < 5; i++) {
      if (itemname[i] = newname) {
	iteminv[i] = 0;
	return true;
      }
    }
    return false;
  }

int item :: itemcount() {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (iteminv[i] >= 1) count ++;
  }
  return count;
}
