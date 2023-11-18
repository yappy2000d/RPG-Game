//
// Created by user on 2023/11/15.
//

#include "Character.h"

Character::Character(std::string& name, int level=1, int hp=100, int maxHp=100, int mp=50, int maxMp=50, int atk=10, int mag=10, int def=10,
                     int coin=0, int exp=0, int attrPoint=0, int skillPoint=0): Entity(name, level, hp, maxHp, mp, maxMp, atk, mag, def, coin, exp), attrPoint(attrPoint), skillPoint(skillPoint) {}

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

void Character::save(const fs::path& path) {
    Entity::save(path);
    cout << "Character save" << endl;
//    json j;
//    j["AttrPoint"] = this->attrPoint;
//    j["SkillPoint"] = this->skillPoint;
//
//    fstream j_file(path, ios::out);
//    j_file << j;
//    j_file.close();

}

ostream &operator<<(ostream &os, const Character &character) {
    operator<<(os, (const Entity&) character);
    os << "AttrPoint: " << character.attrPoint << endl;
    os << "SkillPoint: " << character.skillPoint << endl;
    return os;
}

