#include <algorithm>

#include "player.h"
#include "monster.h"

Player::Player(): hp(Player::FULL_HP), atk(Player::INITIAL_ATK) {
}

void Player::attack(Monster &monster) const {
  monster.receive_damage(atk);
}

void Player::defend(const Monster &monster) {
  hp = std::max(0, hp - monster.get_damage());
}

bool Player::is_dead() const {
  return hp <= 0;
}
