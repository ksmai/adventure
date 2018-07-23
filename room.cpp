#include <iostream>

#include "room.h"
#include "player.h"

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

bool Room::try_leave(Player &p) {
  return true;
}

bool Room::inspect(Player &p) {
  std::cout << "There are nothing here\n";
  int dmg = 5;
  std::cout << "You lost " << dmg << " HP looking around\n";
  p.receive_damage(dmg);
  std::cout << "Your remaining HP: " << p.get_hp() << "\n\n";
  return false;
}

Room *Room::go_top(Player &p) {
  if (!adj[Room::Direction::TOP]) {
    std::cout << "There is only a wall to the top\n\n";
    return this;
  }
  if (!try_leave(p)) {
    return this;
  }
  std::cout << "Move to a new room at the top\n\n";
  return adj[Room::Direction::TOP];
}

Room *Room::go_right(Player &p) {
  if (!adj[Room::Direction::RIGHT]) {
    std::cout << "There is only a wall to the right\n\n";
    return this;
  }
  if (!try_leave(p)) {
    return this;
  }
  std::cout << "Move to a new room on the right\n\n";
  return adj[Room::Direction::RIGHT];
}

Room *Room::go_bottom(Player &p) {
  if (!adj[Room::Direction::BOTTOM]) {
    std::cout << "There is only a wall to the bottom\n\n";
    return this;
  }
  if (!try_leave(p)) {
    return this;
  }
  std::cout << "Move to a new room at the bottom\n\n";
  return adj[Room::Direction::BOTTOM];
}

Room *Room::go_left(Player &p) {
  if (!adj[Room::Direction::LEFT]) {
    std::cout << "There is only a wall to the left\n\n";
    return this;
  }
  if (!try_leave(p)) {
    return this;
  }
  std::cout << "Move to a new room on the left\n\n";
  return adj[Room::Direction::LEFT];
}
