#include "Game.h"
#include <memory>

int main() {
    T_Game game(std::make_shared<T_Game_Menu>());
    return 0;
}
