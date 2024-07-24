# SNAKE 

## 1. DESCRIPTION
Repository contains simple Snake game written in C++ using SFML library. It contains simple GUI and basic game mechanics like eating apples, collecting points and growing snake.
There are 3 levels of difficulty: easy, medium and hard, which can be chosen at the beginning of the game.More difficult levels have higher speed of snake and more points to collect.Also, there is a simple laderboard system, which stores the best scores of 10 players in .txt file.

## 2. REQUIREMENTS
- C++ compiler
- SFML library https://www.sfml-dev.org/ in version 2.5 or above
- CMake and Make

To install SFML library on Ubuntu, run the following commands:
```bash
sudo apt-get install libsfml-dev
```

On Windows you can download the library from the official website and follow the instructions to install it and place it in : 
```bash
C:\lib 
```
But is it needed to modify the CMakeLists.txt file in the build directory to link the library correctly.

## 3. RUNNING THE game
To run the game, you need to compile the code using C++ compiler and link it with SFML library. Go to the directory where you have downloaded the game and run the following commands in build directory:

```bash
cmake ..
make 
./Snake
```
