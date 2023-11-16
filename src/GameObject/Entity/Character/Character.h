//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_CHARACTER_H
#define FINAL_PROJECT_OOP_CHARACTER_H


#include "../Entity.h"

class Character: public Entity{
public:
    Character(string& name, int level, int hp, int maxHp, int mp, int maxMp, int atk, int mag, int def, int coin, int exp, int attrPoint, int skillPoint);
    Character(const fs::path& path);
    int attrPoint;  // 剩餘屬性點
    int skillPoint; // 剩餘技能點

    void printInfo() override;
};


#endif //FINAL_PROJECT_OOP_CHARACTER_H
