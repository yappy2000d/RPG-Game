//
// Created by user on 2023/11/15.
//

#include "Game.h"

Game::Game(const string& username, const string& password) {
    hash<string> hasher;

    this->username = username;
    this->password = to_string(hasher(password));

    // Login
    if(login() == LoginStatus::SUCCESS) {
        cout << "Login Success!" << endl;
    } else {
        cout << "Login Failed!" << endl;
        exit(0);
    }

    selectCharacter();
}

LoginStatus Game::login() {

    fs::path str("./data/Accounts/");

    if(!fs::exists(str / username)) {
        return LoginStatus::FAILED;
    }

    fstream j_file(str / this->username / "config.json", ios::in);
    json j;

    j_file >> j;
    j_file.close();

    return j["password"] == this->password ? LoginStatus::SUCCESS : LoginStatus::FAILED;
}

void Game::selectCharacter() {
    fs::path str("./data/Accounts/");

    fs::directory_iterator list(str / username / "Characters/");

    vector<fs::path> characters;
    fs::path characterPath;

    int i = 0;
    for(auto& p: list) {
        characterPath = p.path().filename();
        cout << "[" << i++ << "] " << characterPath << endl;
        characters.push_back(characterPath);
    }

    // 去除 . 和 .. 的路徑
    //characters.erase(characters.begin(), characters.begin() + 3);

    int select;
    while(true) {
        cout << "請選擇角色(-1:刪除角色, -2:創建角色): ", cin >> select;
        if(select == -2) {
            break;
        } else if(select == -1) {
            // deleteCharacter();
            continue;
        } else {
            try {
                characterPath = characters.at(select);
                cout << characters.size() << endl;
                cout << "選擇角色: " << characterPath << endl;
                break;
            } catch (const out_of_range& e) {
                cout << "輸入錯誤，請重新輸入!" << endl;
                continue;
            }
        }
    }
}
