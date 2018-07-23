#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "monster.h"

class Player {
  int hp;
  int atk;
  static const int FULL_HP = 100;
  static const int INITIAL_ATK = 5;

public:
  Player();
  void attack(Monster &monster) const;
  void defend(const Monster &monster);
  void receive_damage(int dmg);
  bool is_dead() const;
  int get_hp() const;
};

#endif
