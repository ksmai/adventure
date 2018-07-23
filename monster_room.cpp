#include <iostream>

#include "monster_room.h"
#include "player.h"

bool MonsterRoom::inspect(Player &player) {
  if (!monster.is_dead()) {
    std::cout << "You found a monster hiding in the dark!\n\n";
    player.attack(monster);
    std::cout << "You attacked the monster!\n";
    std::cout << "Monster's remaining HP: " << monster.get_hp() << '\n';
    if (monster.is_dead()) {
      std::cout << "The monster died!\n";
    } else {
      player.defend(monster);
      std::cout << "The monster counter-attacked you!\n";
      std::cout << "Your HP is now " << player.get_hp() << '\n';
      if (!player.is_dead()) {
        std::cout << "The monster went into the dark\n\n";
      }
    }
  } else {
    std::cout << "There is a dead monster on the floor.\n\n";
  }
  return false;
}

bool MonsterRoom::try_leave(Player &player) {
  if (monster.is_dead()) {
    return true;
  } else {
    std::cout << "A monster jumped out from the dark!\n\n";
    std::cout << "You were attacked!\n";
    player.defend(monster);
    std::cout << "Your HP is now " << player.get_hp() << '\n';
    if (!player.is_dead()) {
      std::cout << "You counter-attacked!\n";
      player.attack(monster);
      std::cout << "Monster's remaining HP: " << monster.get_hp() << '\n';
      if (monster.is_dead()) {
        std::cout << "The monster died.\n\n";
      } else {
        std::cout << "The monster fleed into the dark.\n\n";
      }
    }
    return false;
  }
}
