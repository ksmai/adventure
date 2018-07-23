#ifndef __MONSTER_H__
#define __MONSTER_H__

class Monster {
  int hp;
  int atk;
  static const int MIN_HP = 5;
  static const int MAX_HP = 25;
  static const int MIN_ATK = 1;
  static const int MAX_ATK = 5;

public:
  Monster();
  void receive_damage(int dmg);
  int get_damage() const;
  bool is_dead() const;
  int get_hp() const;
};

#endif
