//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_GAMEOBJECT_H
#define FINAL_PROJECT_OOP_GAMEOBJECT_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <memory>

#include <nlohmann/json.hpp>
#include <Position.hpp>


using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

using std::string;
using std::cout;
using std::endl;

class GameObject {
public:
    GameObject() = default;
    explicit GameObject(const fs::path& path);
    friend ostream& operator<<(ostream& os, const GameObject& obj);

protected:
    string area;
    Position pos;
};


#endif //FINAL_PROJECT_OOP_GAMEOBJECT_H
