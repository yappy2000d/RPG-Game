//
// Created by user on 2023/11/15.
//

#include "GameObject.h"
GameObject::GameObject(const fs::path& path) {
    try {
        fstream j_file(path, ios::in);
        json j;

        j_file >> j;
        j_file.close();

        this->area = j["location"]["area"];
        vector<int> pos_ (j["location"]["pos"]);
        this->pos = Position(pos_);
    }
    catch (json::exception& e) {
        cout << "GameObject error: ";
        cout << e.what() << endl;
    }
}