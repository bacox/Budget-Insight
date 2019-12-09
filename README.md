# Budget-Insight

| Branch           | Build Status                                                                                                                                      |
|------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| Default (Master) | [![CircleCI](https://circleci.com/gh/bacox/Budget-Insight.svg?style=svg)](https://circleci.com/gh/bacox/Budget-Insight)                           |
| Develop          | [![CircleCI](https://circleci.com/gh/bacox/Budget-Insight/tree/develop.svg?style=svg)](https://circleci.com/gh/bacox/Budget-Insight/tree/develop) |

## Deps
Install Catch2
```
git clone https://github.com/catchorg/Catch2.git
cd Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install
```

Install libsqlite3-dev
```
sudo apt-get install libsqlite3-dev
```

### To Build
```
mkdir -p build && cd build
cmake .. 
make
```
