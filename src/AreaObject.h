//
// Created by user on 2023/11/15.
//

#ifndef FINAL_PROJECT_OOP_AREAOBJECT_H
#define FINAL_PROJECT_OOP_AREAOBJECT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class AreaObject {
public:
    string name;
    string displayName;
    AreaObject *west;
    AreaObject *east;
    AreaObject *north;
    AreaObject *south;

    vector<string> terrain;
};


#endif //FINAL_PROJECT_OOP_AREAOBJECT_H
