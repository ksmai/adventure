#include <iostream>
#include <limits>

#include "game.h"
#include "player.h"
#include "room.h"

Game::Game():
  rooms(10),
  monster_rooms(5),
  treasure_rooms(1),
  current_room(&rooms[0]) {
}

bool Game::is_win() const {
  return won;
}

bool Game::is_lose() const {
  return player.is_dead();
}

void Game::next_round() {
  char c;
  std::cout << "What will you do? ";
  std::cin >> c;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  switch (c) {
    case 'W':
    case 'w':
      current_room->go_top(player);
      break;
    case 'A':
    case 'a':
      current_room->go_left(player);
      break;
    case 'S':
    case 's':
      current_room->go_bottom(player);
      break;
    case 'D':
    case 'd':
      current_room->go_right(player);
      break;
    case 'I':
    case 'i':
      won = current_room->inspect(player);
      break;
    default:
      std::cout << "WASD for movement. I for inspect.\n";
  }
}
