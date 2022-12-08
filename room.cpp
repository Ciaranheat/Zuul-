#include <iostream>
#include <string.h>
#include "room.h"
#inlcude "item.h"

using namespace std;

room :: room(string newname, string newdesc) {

  name = newname;
  description = newdesc;
}

room ::~ room() {

}

string room :: getName() {//gets name for rooms 
  return name;
}

string room :: getDescription() { //gets description for the rooms
  return description;
}

string room :: get Exits() {//gets the exits to the starting room and the directions for other rooms
  string e = " ";

  if (exitMap.find("North") != exitMap.end())
    e = e + "NORTH";

  if (exitMap.find("SOUTH") != exitMap.end())
    e = e + "SOUTH";

  if (exitMap.find("EAST") != exitMap.end())
    e = e + "EAST";

  if (exitMap.find("WEST") != exitMap.end())
    e = e + "WEST";

  return e;
}

string room :: showItems() {//Shows items to the user
  return itemList.showItems();
}

void room :: setItems(int i1, int i2, int i3, int i4, int i5) {//Makes items 
  itemList.showItems(i1,i2,i3,i4,i5); 
}

void room :: setName(string newname) {//Sets name
  name = newname;
}

void room :: setDescription(string newdescription) { //Sets description 
  description = newdescription;
}

void room :: setExit(room* n, room* s, room* e, room* w) { //Sets exit

  if (n != NULL)
    exitMap["NORTH"] = n;
  if (n != NULL)
    exitMap["SOUTH"] = s;
  if (n != NULL)
    exitMap["EAST"] = e;
  if (n != NULL)
    exitMap["WEST"] = w;
  
}

room* room:: goExit(string newExit) { //Goes to exit and stops someone if there is no exit
  if (exitMap.find(newExit) == exitMap.end()) {
    cout << "No exit" << endl;
    return this;
  }
  else {
    return exitMap.find(newExit) -> second;
  }
}

void room :: pickupItem(string itemname, item &playerbucket) {//Picks up item if there is one
  bool find = false;
  for (int i = 0; i <5; i++) {
    if (itemList.itemName[i] == itemname) {
      find = true;
      itemList.deleteItem(itemList.itemName[i]);
      playerbucket.addItem(itemList.itemName[i]);
    }
  }
    if (find == false) {
      cout << "That item does not exist here." << endl;
    }
}

void room :: dropItem(string itemname, item &playerbucket) {//Drops item if you have it 
    bool find = false;
    for (int i = 0; i < 5; i++) {
      if (playerbucket.itemname[i] == itemname) {
	find = true;
	itemList.addItem(itemList.itemName[i]);
	playerbucket.deleteItem(itemList.itemName[i]);
      }
    }

    if (find == false) {
      cout << "You do not have that item in your inventory." << endl; 
    }
  }
