//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_GAME_H
#define FINAL_PROJECT_OOP_GAME_H

#include "GameObject/Entity/Character/Character.h"

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

enum class LoginStatus {
    FAILED,
    SUCCESS
};

class Game {
public:
    Game(const string& username, const string& password);
    LoginStatus login();
    void selectCharacter();
    void createCharacter();
    void deleteCharacter();
    void loadCharacter(const fs::path& path);

private:
    string username;
    string password;
    unique_ptr<Character> character;
};

#endif //FINAL_PROJECT_OOP_GAME_H
