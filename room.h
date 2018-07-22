#ifndef __ROOM_H__
#define __ROOM_H__

#include <unordered_map>

#include "player.h"

class Room {
private:
  struct EnumClassHash {
    template <typename T>
    int operator()(T t) const {
      return static_cast<int>(t);
    }
  };
public:
  enum class Direction {
    TOP, RIGHT, BOTTOM, LEFT
  };

  Room();
  Room(Room *top, Room *right, Room *bottom, Room *left);
  ~Room();

  void set_top_room(Room *r);
  void set_right_room(Room *r);
  void set_bottom_room(Room *r);
  void set_left_room(Room *r);

  virtual bool try_leave(Player &p);
  virtual bool inspect(Player &p);

  Room *go_top(Player &p);
  Room *go_right(Player &p);
  Room *go_bottom(Player &p);
  Room *go_left(Player &p);

protected:
  std::unordered_map<Direction, Room *, EnumClassHash> adj;
};

#endif
