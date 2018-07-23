#ifndef __MONSTER_ROOM_H__
#define __MONSTER_ROOM_H__

#include "room.h"
#include "player.h"
#include "monster.h"

class MonsterRoom: public Room {
  Monster monster;

public:
  virtual bool try_leave(Player &player);
  virtual bool inspect(Player &player);
};

#endif
