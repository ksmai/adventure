#include <iostream>

#include "treasure_room.h"

bool TreasureRoom::inspect(Player &p) {
  std::cout << "There is a treasure box in the middle of the room.\n";
  std::cout << "Open it? (Y/N) Y\n";
  std::cout << "You found a lot of money in the box!!!\n\n";
  return true;
}

bool TreasureRoom::try_leave(Player &p) {
  return true;
}
