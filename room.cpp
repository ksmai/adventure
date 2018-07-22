#include <iostream>

#include "room.h"

Room::Room() {
  adj[Room::Direction::TOP] = nullptr;
  adj[Room::Direction::RIGHT] = nullptr;
  adj[Room::Direction::BOTTOM] = nullptr;
  adj[Room::Direction::LEFT] = nullptr;
}

Room::Room(Room *top, Room *right, Room *bottom, Room* left) {
  adj[Room::Direction::TOP] = top;
  adj[Room::Direction::RIGHT] = right;
  adj[Room::Direction::BOTTOM] = bottom;
  adj[Room::Direction::LEFT] = left;
}

Room::~Room() {
  if (adj[Room::Direction::TOP] != nullptr) {
    adj[Room::Direction::TOP]->set_bottom_room(nullptr);
  }
  if (adj[Room::Direction::RIGHT] != nullptr) {
    adj[Room::Direction::RIGHT]->set_left_room(nullptr);
  }
  if (adj[Room::Direction::BOTTOM] != nullptr) {
    adj[Room::Direction::BOTTOM]->set_top_room(nullptr);
  }
  if (adj[Room::Direction::LEFT] != nullptr) {
    adj[Room::Direction::LEFT]->set_right_room(nullptr);
  }
}

void Room::set_top_room(Room *r) {
  if (adj[Room::Direction::TOP] != r) {
    adj[Room::Direction::TOP] = r;
    if (r) {
      r->set_bottom_room(this);
    }
  }
}

void Room::set_right_room(Room *r) {
  if (adj[Room::Direction::RIGHT] != r) {
    adj[Room::Direction::RIGHT] = r;
    if (r) {
      r->set_left_room(this);
    }
  }
}

void Room::set_bottom_room(Room *r) {
  if (adj[Room::Direction::BOTTOM] != r) {
    adj[Room::Direction::BOTTOM] = r;
    if (r) {
      r->set_top_room(this);
    }
  }
}

void Room::set_left_room(Room *r) {
  if (adj[Room::Direction::LEFT] != r) {
    adj[Room::Direction::LEFT] = r;
    if (r) {
      r->set_right_room(this);
    }
  }
}

bool Room::try_leave() {
  return true;
}

void Room::inspect() {
  std::cout << "There are nothing here\n";
}

Room *Room::go_top() {
  if (!adj[Room::Direction::TOP]) {
    std::cout << "There is only a wall to the top\n";
    return this;
  }
  if (!try_leave()) {
    return this;
  }
  std::cout << "Move to a new room at the top\n";
  return adj[Room::Direction::TOP];
}

Room *Room::go_right() {
  if (!adj[Room::Direction::RIGHT]) {
    std::cout << "There is only a wall to the right\n";
    return this;
  }
  if (!try_leave()) {
    return this;
  }
  std::cout << "Move to a new room on the right\n";
  return adj[Room::Direction::RIGHT];
}

Room *Room::go_bottom() {
  if (!adj[Room::Direction::BOTTOM]) {
    std::cout << "There is only a wall to the bottom\n";
    return this;
  }
  if (!try_leave()) {
    return this;
  }
  std::cout << "Move to a new room at the bottom\n";
  return adj[Room::Direction::BOTTOM];
}

Room *Room::go_left() {
  if (!adj[Room::Direction::LEFT]) {
    std::cout << "There is only a wall to the left\n";
    return this;
  }
  if (!try_leave()) {
    return this;
  }
  std::cout << "Move to a new room on the left\n";
  return adj[Room::Direction::LEFT];
}
