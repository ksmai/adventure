#include <algorithm>
#include <random>

#include "monster.h"

Monster::Monster() {
  std::random_device dev;
  std::mt19937 mt(dev());
  std::uniform_int_distribution<int> rand_hp(MIN_HP, MAX_HP);
  std::uniform_int_distribution<int> rand_atk(MIN_ATK, MAX_ATK);
  hp = rand_hp(mt);
  atk = rand_atk(mt);
}

void Monster::receive_damage(int dmg) {
  hp = std::max(0, hp - dmg);
}

int Monster::get_damage() const {
  return atk;
}

bool Monster::is_dead() const {
  return hp <= 0;
}

int Monster::get_hp() const {
  return hp;
}
