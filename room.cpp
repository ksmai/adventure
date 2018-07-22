#include "room.h"

Room::Room() {
  adj[static_cast<int>(TOP)] = nullptr;
  adj[static_cast<int>(RIGHT)] = nullptr;
  adj[static_cast<int>(BOTTOM)] = nullptr;
  adj[static_cast<int>(LEFT)] = nullptr;
}

Room::Room(Room *top, Room *right, Room *bottom, Room* left) {
  adj[static_cast<int>(TOP)] = top;
  adj[static_cast<int>(RIGHT)] = right;
  adj[static_cast<int>(BOTTOM)] = bottom;
  adj[static_cast<int>(LEFT)] = left;
}

void Room::set_top_room(Room *r) {
  adj[static_cast<int>(TOP)] = r;
}

void Room::set_right_room(Room *r) {
  adj[static_cast<int>(RIGHT)] = r;
}

void Room::set_bottom_room(Room *r) {
  adj[static_cast<int>(BOTTOM)] = r;
}

void Room::set_left_room(Room *r) {
  adj[static_cast<int>(LEFT)] = r;
}
