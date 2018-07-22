#ifndef __ROOM_H__
#define __ROOM_H__
#include <unordered_map>

class Room {
public:
  enum Direction {
    TOP, RIGHT, BOTTOM, LEFT
  };

  Room();
  Room(Room *top, Room *right, Room *bottom, Room *left);

  void set_top_room(Room *r);
  void set_right_room(Room *r);
  void set_bottom_room(Room *r);
  void set_left_room(Room *r);

protected:
  std::unordered_map<int, Room *> adj;
};

#endif
