//
// Created by anuar on 17/05/2022.
//

#ifndef DATE_H_GAMELIST_H
#define DATE_H_GAMELIST_H
#include "Game.h"
#include "fstream"
const int BLOCK_MAX_SIZE = 10;
using namespace std;
class Game;
 struct Block {
     Game* list[BLOCK_MAX_SIZE];
     int current_size;
     Block* next;
     };
class GameList {
    Block* firstBlock;
    Block* lastBlock;
    int numero_filas;
public:
    GameList();
    GameList(char *file_path);
    int Numfilas (char *file_path);
    bool add(Game* game);
    bool essubcad(string tit,string sub);
    bool find(string title, int year_start, int year_end, Game** &results, int &num_results);
    bool dump(char *file_path);
    Block *getFirstBlock() const;
    Block *getLastBlock() const;;
    ~GameList();
};


#endif //DATE_H_GAMELIST_H
