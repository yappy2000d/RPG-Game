//
// Created by user on 2023/11/15.
//

#include "Character.h"

Character::Character(std::string& name, int level, int hp, int maxHp, int mp, int maxMp, int atk, int mag, int def,
                     int coin, int exp, int attrPoint, int skillPoint): Entity(name, level, hp, maxHp, mp, maxMp, atk, mag, def, coin, exp), attrPoint(attrPoint), skillPoint(skillPoint) {}

void Character::printInfo() {
    cout << "Name: " << this->name << endl;
    cout << "Level: " << this->level << endl;
    cout << "HP: " << this->hp << "/" << this->maxHp << endl;
    cout << "MP: " << this->mp << "/" << this->maxMp << endl;
    cout << "ATK: " << this->atk << endl;
    cout << "MAG: " << this->mag << endl;
    cout << "DEF: " << this->def << endl;
    cout << "Coin: " << this->coin << endl;
    cout << "Exp: " << this->exp << endl;
    cout << "AttrPoint: " << this->attrPoint << endl;
    cout << "SkillPoint: " << this->skillPoint << endl;

    cout << "Area: " << this->area << endl;
    cout << "Position: " << this->pos.x << ", " << this->pos.y << endl;
}

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








