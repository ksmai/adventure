#ifndef __TREASURE_ROOM_H__
#define __TREASURE_ROOM_H__

#include "room.h"
#include "player.h"

class TreasureRoom: public Room {
public:
  virtual bool inspect(Player &p);
  virtual bool try_leave(Player &p);
};

#endif
