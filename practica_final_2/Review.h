//
// Created by anuar on 11/04/2022.
//

#ifndef MAIN_CPP_COMMENT_H
#define MAIN_CPP_COMMENT_H


#include <iostream>
using namespace std;
#include <cassert>
#include "Game.h"
#include "Date.h"
#include "User.h"
class User;
class Game;
class Review {
        string text;
        bool like;
        Game* game;
        User* author;
public:
    Review();

    Review(const string &text, bool like, Game *game, User *author);

    const string &getText() ;

    bool isLike() ;

    Game *getGame();

    User *getAuthor() ;

    void setText( string &text);

    void setLike(bool like);

    void setGame(Game *game);

    void setAuthor(User *author);
};


#endif //MAIN_CPP_COMMENT_H
