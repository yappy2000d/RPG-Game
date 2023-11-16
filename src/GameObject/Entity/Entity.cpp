//
// Created by user on 2023/11/15.
//

#include "Entity.h"

#include <utility>

Entity::Entity(string& name, int level, int hp, int maxHp, int mp, int maxMp, int atk, int mag, int def, int coin,
               int exp) :
        name(name), level(level), hp(hp), maxHp(maxHp), mp(mp), maxMp(maxMp), atk(atk), mag(mag), def(def), coin(coin), exp(exp) {}

Entity::Entity(const fs::path& path): GameObject(path) {
    try {
        fstream j_file(path, ios::in);
        json j;

        j_file >> j;
        j_file.close();

        this->name = j["attributes"]["Name"];
        this->level = j["attributes"]["Level"];
        this->exp = j["attributes"]["Exp"];
        this->hp = j["attributes"]["HP"];
        this->mp = j["attributes"]["MP"];
        this->atk = j["attributes"]["ATK"];
        this->mag = j["attributes"]["MAG"];
        this->def = j["attributes"]["DEF"];
        this->maxHp = j["attributes"]["MaxHP"];
        this->maxMp = j["attributes"]["MaxMP"];
        this->coin = j["attributes"]["Coin"];

        vector<int> pos_ (j["location"]["pos"]);
        this->pos = Position(pos_);
    }
    catch (json::exception& e) {
        cout << "Entity error: ";
        cout << e.what() << endl;
    }
}