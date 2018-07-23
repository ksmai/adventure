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
  rooms[0].set_right_room(&rooms[1]);
  rooms[1].set_right_room(&rooms[2]);
  rooms[1].set_top_room(&monster_rooms[0]);
  rooms[2].set_right_room(&rooms[3]);
  rooms[2].set_top_room(&rooms[5]);
  rooms[3].set_right_room(&monster_rooms[2]);
  rooms[3].set_top_room(&monster_rooms[3]);
  rooms[4].set_left_room(&monster_rooms[3]);
  rooms[4].set_bottom_room(&monster_rooms[2]);
  rooms[5].set_top_room(&rooms[7]);
  rooms[5].set_left_room(&rooms[6]);
  rooms[6].set_bottom_room(&monster_rooms[0]);
  rooms[7].set_right_room(&rooms[8]);
  rooms[7].set_left_room(&monster_rooms[4]);
  rooms[9].set_right_room(&monster_rooms[4]);
  rooms[9].set_bottom_room(&treasure_rooms[0]);
  monster_rooms[0].set_left_room(&monster_rooms[1]);
  monster_rooms[1].set_top_room(&treasure_rooms[0]);
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
      current_room = current_room->go_top(player);
      break;
    case 'A':
    case 'a':
      current_room = current_room->go_left(player);
      break;
    case 'S':
    case 's':
      current_room = current_room->go_bottom(player);
      break;
    case 'D':
    case 'd':
      current_room = current_room->go_right(player);
      break;
    case 'I':
    case 'i':
      won = current_room->inspect(player);
      break;
    default:
      std::cout << "WASD for movement. I for inspect.\n";
  }
}
