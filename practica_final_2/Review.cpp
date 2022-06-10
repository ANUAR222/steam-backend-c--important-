//
// Created by anuar on 11/04/2022.
//

#include "Review.h"


Review::Review(){
    text= "  ";
    like= false;
};

const std::string &Review::getText()  {
    return text;
}

bool Review::isLike()  {
    return like;
}

Game *Review::getGame()  {
    return game;
}

User *Review::getAuthor() {
    return author;
}

void Review::setText(string &text) {
    Review::text = text;
}

void Review::setLike(bool like) {
    Review::like = like;
}

void Review::setGame(Game *game) {
    Review::game = game;
}

void Review::setAuthor(User *author) {
    Review::author = author;
}

Review::Review(const string &text2, bool like2, Game *game2, User *author2){
    text= text2;
    like=like2;
    game=game2;
    author=author2;
}
