#include <iostream>

#include "game.h"

int main() {
  std::cout << "Waking up...\n"
            << "You found yourself in a dark dungeon...\n"
            << "\"Help!\" You shouted.\n"
            << "But there are only echoes of your own voice...\n"
            << "Let the game begins...\n\n";
  Game game;
  while (!game.is_win() && !game.is_lose()) {
    game.next_round();
  }
  if (game.is_win()) {
    std::cout << "Congratulations! YOU WIN!!\n\n";
  } else {
    std::cout << "You dead... Better luck next time...\n\n";
  }
  return 0;
}
