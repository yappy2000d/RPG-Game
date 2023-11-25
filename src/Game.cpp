//
// Created by user on 2023/11/15.
//

#include "Game.h"

#include <memory>

Game::Game(const string& username, const string& password) {
    hash<string> hasher;

    this->username = username;
    this->password = to_string(hasher(password));

    // Login
    while(login() == LoginStatus::FAILED) {
        cout << "Login Failed!" << endl;
        cout << "User Name:", cin >> this->username;
        cout << "Password:",  cin >> this->password;
        this->password = to_string(hasher(this->password));
    }
    cout << "Login Success!" << endl;

    selectCharacter();
}

LoginStatus Game::login() {

    fs::path str("./data/Accounts/");

    if(!fs::exists(str / this->username)) {
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

    fs::directory_iterator list(str / this->username / "Characters/");

    vector<fs::path> characters;
    fs::path charPath;

    int i = 0;
    for(auto& p: list) {
        charPath = p.path().filename();
        cout << "[" << i++ << "] " << charPath.string() << endl;
        characters.push_back(charPath);
    }

    int select;
    while(true) {
        cout << "請選擇角色(-1:刪除角色, -2:創建角色): ", cin >> select;
        if(select == -2) {
            createCharacter();
            break;
        } else if(select == -1) {
            // deleteCharacter();
            continue;
        } else {
            try {
                charPath = characters.at(select);
                loadCharacter(charPath);
                break;
            } catch (const out_of_range& e) {
                cout << "輸入錯誤，請重新輸入!" << endl;
                continue;
            }
        }
    }
}

void Game::createCharacter() {
    fs::path str("./data/Accounts/");
    fs::directory_iterator list(str / this->username / "Characters");

    if(distance(list, fs::directory_iterator{}) < 3) {
        cout << "角色名稱: ", cin >> this->username;
        //this->character = std::make_unique<Character> (this->username);
        this->character->save("./data/Accounts/" + this->username + "/Characters/");
    } else {
        cout << "角色數量已達上限!" << endl;
    }
}

void Game::deleteCharacter() {

}

void Game::loadCharacter(const fs::path &charPath) {
    fs::path str("./data/Accounts/");
    fs::path characterPath = str / this->username / "Characters" / charPath / "character.json";
    this->character = std::make_unique<Character> (characterPath);

    cout << *this->character << endl;
}
