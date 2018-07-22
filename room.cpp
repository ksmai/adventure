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
