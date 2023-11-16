//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_ENTITY_H
#define FINAL_PROJECT_OOP_ENTITY_H


#include "../GameObject.h"

class Entity: public GameObject {
public:
    string name;    // 名稱
    int level;      // 等級
    int exp;        // 當前經驗值
    int maxExp;     // 最大經驗值
    int hp;         // 當前血量
    int maxHp;      // 最大血量
    int mp;         // 當前魔力
    int maxMp;      // 最大魔力
    int atk;        // 物理攻擊力
    int mag;        // 魔法攻擊力
    int def;        // 防禦力
};


#endif //FINAL_PROJECT_OOP_ENTITY_H
