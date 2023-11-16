//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_CHARACTER_H
#define FINAL_PROJECT_OOP_CHARACTER_H


#include "../Entity.h"

class Character: public Entity{
public:
    int coin;       // 擁有的金幣
    int attrPoint;  // 剩餘屬性點
    int skillPoint; // 剩餘技能點
};


#endif //FINAL_PROJECT_OOP_CHARACTER_H
