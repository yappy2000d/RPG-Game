//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_ENTITY_H
#define FINAL_PROJECT_OOP_ENTITY_H


#include "../GameObject.h"

class Entity: public GameObject {
public:
    Entity(string& name, int level, int hp, int maxHp, int mp, int maxMp, int atk, int mag, int def, int coin, int exp);
    explicit Entity(const fs::path& path);
    void save(const fs::path& path);

    friend ostream& operator<<(ostream& os, const Entity& entity);

protected:
    string name;    // 名稱
    int level;      // 等級
    int coin;       // 擁有的金幣 | 殺死可獲得的金幣
    int exp;        // 當前經驗值 | 殺死可獲得的經驗
    int hp;         // 當前血量
    int maxHp;      // 最大血量
    int mp;         // 當前魔力
    int maxMp;      // 最大魔力
    int atk;        // 物理攻擊力
    int mag;        // 魔法攻擊力
    int def;        // 防禦力
};


#endif //FINAL_PROJECT_OOP_ENTITY_H
