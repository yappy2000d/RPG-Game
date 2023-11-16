//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_GAME_H
#define FINAL_PROJECT_OOP_GAME_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <memory>

#include "include/nlohmann/json.hpp"
#include "GameObject/Entity/Character/Character.h"

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

enum class LoginStatus {
    SUCCESS,
    FAILED
};

class Game {
public:
    Game(const string& username, const string& password);
    LoginStatus login();
    void selectCharacter();

private:
    string username;
    string password;
    unique_ptr<Character> character;
};

#endif //FINAL_PROJECT_OOP_GAME_H
