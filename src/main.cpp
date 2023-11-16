#include "Game.h"

int main() {
    string username, password;

    cout << "User Name:", cin >> username;
    cout << "Password:",  cin >> password;

    Game myGame = Game(username, password);

    return 0;
}
