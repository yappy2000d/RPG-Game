# RPG-Game
![CMake](https://img.shields.io/badge/CMake3.26.4-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![C++](https://img.shields.io/badge/c++17-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

OOP Final Project

## Run in CodeSpace

```bash
cmake --version
sudo apt remove cmake
cd /opt/
wget https://github.com/Kitware/CMake/releases/download/v3.26.5/cmake-3.26.5-linux-x86_64.sh
chmod +x /opt/cmake-3.26.5-linux-x86_64.sh
sudo bash /opt/cmake-3.26.5-linux-x86_64.sh
sudo ln -s /opt/cmake-3.26.5-linux-x86_64/bin/* /usr/bin
cd /workspaces/RPG-Game/
cmake --version

cmake .
cmake --build .
```
