#ifndef __GAME_H__
#define __GAME_H__

#include <vector>

#include "room.h"
#include "monster_room.h"
#include "treasure_room.h"
#include "player.h"

class Game {
  bool won;
  Player player;
  std::vector<Room> rooms;
  std::vector<MonsterRoom> monster_rooms;
  std::vector<TreasureRoom> treasure_rooms;
  Room *current_room;

public:
  Game();
  bool is_lose() const;
  bool is_win() const;
  void next_round();
};

#endif
