//
// Created by anuar on 11/04/2022.
//

#ifndef MAIN_CPP_VIDEO_H
#define MAIN_CPP_VIDEO_H


#include <iostream>
using namespace std;
#include <cassert>
#include "Date.h"
#include "Review.h"
#include <algorithm>
class Date;
class Review;
enum Tag{INDIE, ACTION,ADVENTURE, CASUAL, SIMULATION, RPG, STRATEGY, IS2D, SPORTS, PUZZLE, SHOOTER,HORROR};
class Game {
    int id;
    string title;
    Date releaseDate;
    float price;
    Tag *tags;
    int num_tags;
public:
    Game();

    Game(int id2, const string &title2, const Date &releaseDate2, float price2, Tag *tags2, int numTags2);

    string &getTitle();

     Date &getReleaseDate();

    string toString();

    int getId() ;
    
    float getPrice();
    int operator+=(int cant);
    int operator-=(int cant);
    Tag *getTags();
    Tag convertiraTag(string tag);
    string convertiraString(Tag *tag);
    bool essubcad(string tit,string sub);
    void setId(int id) ;

    void setTitle( std::string &title) ;

    void setReleaseDate( Date &releaseDate);

    void setPrice(float price);

    void setTags(Tag *tags);

};

#endif //MAIN_CPP_VIDEO_H
