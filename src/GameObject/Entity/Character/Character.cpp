//
// Created by user on 2023/11/15.
//

#include "Character.h"

Character::Character(std::string& name, int level, int hp, int maxHp, int mp, int maxMp, int atk, int mag, int def,
                     int coin, int exp, int attrPoint, int skillPoint): Entity(name, level, hp, maxHp, mp, maxMp, atk, mag, def, coin, exp), attrPoint(attrPoint), skillPoint(skillPoint) {}

Character::Character(const fs::path& path): Entity(path) {
    try {
        fstream j_file(path, ios::in);
        json j = json::parse(j_file);
        j_file.close();

        this->attrPoint = j["AttrPoint"];
        this->skillPoint = j["SkillPoint"];
    } catch (json::exception& e) {
        cout << "Character error: " << endl;
        cout << e.what() << endl;
        this->attrPoint = 0;
        this->skillPoint = 0;
    }
}

ostream &operator<<(ostream &os, const Character &character) {
    operator<<(os, (const Entity&) character);
    os << "AttrPoint: " << character.attrPoint << endl;
    os << "SkillPoint: " << character.skillPoint << endl;
    return os;
}

