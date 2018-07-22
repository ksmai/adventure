#ifndef __ROOM_H__
#define __ROOM_H__
#include <unordered_map>

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

protected:
  std::unordered_map<Direction, Room *, EnumClassHash> adj;
};

#endif
