/*
Ciaran McErlean
Period 6
12/16/22
Zuul project
Way to win:
go west then south for first item 
go back to start then go east then south for next two items
go bact to start then go north then east for last item 
go back to start 
 */

#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;
//Sets map and items
void setMap(vector<room*>* roomList, room* &currentRoom, item &playerBucket);
void setItem(vector<item*>* itemList);


int main() {
  
  vector<room*>* roomList = new vector<room*>;
  room* currentRoom;
  string input;
  string in;
  item playerBucket;
  int moveCount = 0;

  cout << "Welcome to my game: Zuul! The objective of the game is to find all the items in the school and bring them back to the original room, you lose if you take over 100 turns" << endl;

  setMap(roomList, currentRoom, playerBucket);

  while(moveCount <= 100) {//Sets all the buttons and gets the inputs from user along with ending the game 
  cout << endl;
  cout << currentRoom -> getName() << endl;
  cout << currentRoom -> getDescription() << endl;
  cout << "There are exits: " << endl;
  cout << currentRoom -> getExits() << endl;
  cout << endl;

  cout << "Items in the room: " << currentRoom -> showItems() << endl;
  cout << "Items in inventory: " << playerBucket.showItems() << endl;
  cout << endl;

  cout << "Where do you want to do? [North, South, West, East, DROP, PICKUP, QUIT]: ";
  cin >> input;

  if (input == "PICKUP" || input == "Pickup" || input == "pickup") {
    cout << "Enter the name of the item you want to pickup: ";
    cin >> in;
    currentRoom -> pickupItem(in, playerBucket);
  }
  if (input == "DROP" || input == "Drop" || input == "drop") {
    cout << "Enter the name of the item you want to drop: ";
    cin >> in;
    currentRoom -> dropItem(in, playerBucket);
  }


  if (input == "QUIT" || input == "Quit" || input == "quit") {
    exit(1);
  }

  if (input == "NORTH" || input == "SOUTH" || input == "EAST" || input == "WEST") {
    currentRoom = currentRoom -> goExit(input);
    moveCount++;
  }
  if (playerBucket.itemCount() == 5 && currentRoom -> getName() == "Cafetria" && moveCount <= 100) {
    cout << "Congrats you won!" << endl;
    exit(0);
  }
  
}
cout << "sorry you took over 100 try's you lost" << endl;
return 0;
}

void setMap(vector<room*>* roomList, room* &currentRoom, item &playerBucket) {//All the rooms and there names, and descriptions 
  room* r1 = new room("Cafetria", "The starting room, you can go anywhere");
  roomList -> push_back(r1);

  room* r2 = new room("HallWay1", "You are in hall way 1, you can go east for the math class, or north for hall way 5: ");
  roomList -> push_back(r2);

  room* r3 = new room("HallWay2", "You are in hall way 2, you can go north for the bathroom, or south for the science class: ");
  roomList -> push_back(r3);

  room* r4 = new room("HallWay3", "You are in hall way 3, it is a dead end: ");
  roomList -> push_back(r4);

  room* r5 = new room("HallWay4", "You are in hall way 4, you can go north into Lit&Comp class, west to the gym, and south to CS class: ");
  roomList -> push_back(r5);

  room* r6 = new room("Hallway5", "You are in hall way 5, you can go north to go outside: ");
  roomList -> push_back(r6);

  room* r7 = new room("Math", "You are in the math class, there is no where else to go: ");
  roomList -> push_back(r7);

  room* r8 = new room("Outside", "You are outside, you can go east and go to the field: ");
  roomList -> push_back(r8);

  room* r9 = new room("Field", "You are at the field, there is no where else you can go; ");
  roomList -> push_back(r9);

  room* r10 = new room("Bathroom", "You are in the bathroom, there is no where else to go: ");
  roomList -> push_back(r10);
  
  room* r11 = new room("Science", "you are in the science classroom, there is no where to go: ");
  roomList -> push_back(r11);

  room* r12 = new room("Lit and Comp", "you are in the Lit&Comp class, there is no where to go: ");
  roomList -> push_back(r12);

  room* r13 = new room("GYM", "You are in gym class, there is no where for you to go: ");
  roomList -> push_back(r13);

  room* r14 = new room("CS", "You are in Computer Science class, you can go west into CAD class: ");
  roomList -> push_back(r14);

  room* r15 = new room("CAD", "You are in CAD class, there is no where for you to go: ");
  roomList -> push_back(r15);

  //setting the exits (N,S,E,W)
 
  r1 -> setExits(r2, r4, r3, r5);
  r2 -> setExits(r6, r1, r7, NULL);
  r3 -> setExits(r10, r11, NULL, r1);
  r4 -> setExits(r1, NULL, NULL, NULL);
  r5 -> setExits(r12, r14, r1, r13);
  r6 -> setExits(r8, r5, NULL, NULL);
  r7 -> setExits(NULL, NULL, NULL, r2);
  r8 -> setExits(NULL, r6, r9, NULL);
  r9 -> setExits(NULL, NULL, NULL, r8);
  r10 -> setExits(NULL, r3, NULL, NULL);
  r11 -> setExits(r3, NULL, NULL, NULL);
  r12 -> setExits(NULL, r5, NULL, NULL);
  r13 -> setExits(NULL, NULL, r5, NULL);
  r14 -> setExits(r5, NULL, NULL, r15);
  r15 -> setExits(NULL, NULL, r14, NULL);

  //Setting Items
  r7 -> setItems(1,0,0,0,0);
  r11 -> setItems(0,0,1,1,0);
  r14 ->setItems(0,1,0,0,0);
  playerBucket.inivItems(0,0,0,0,1);

  //sets starting room
  currentRoom = r1;
		      
}
