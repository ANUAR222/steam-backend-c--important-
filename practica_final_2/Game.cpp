//
// Created by anuar on 11/04/2022.
//

#include "Game.h"

Game::Game(){
    id=0;
    title="  ";
    releaseDate={0,0,0};
    price=0;
    num_tags=0;
    *tags={INDIE};
};
Game::Game(int id2, const string &title2, const Date &releaseDate2, float price2, Tag *tags2, int numTags2){
    id= id2;
    price=price2;
    releaseDate=releaseDate2;
    title=title2;
    tags=new Tag[numTags2];
    for (int j = 0; j < numTags2; ++j) {
        tags[j]= tags2[j];
    }
};
int Game::operator +=(int cant){
return price+=cant;
};
int Game::operator -=(int cant){
return price-=cant;
};
string Game::toString(){
    string x;
    x={"id "+to_string(id)+", Anio "+to_string(releaseDate.getAnio())+", Mes "+to_string(releaseDate.getMes())+", dia "+
       to_string(releaseDate.getDia())+", precio "+to_string(price)+", tags "+to_string(*tags)};
    return x;
};
void Game::setId(int id) {
    Game::id = id;
}
float Game::getPrice()  {
    return price;
}
bool Game::essubcad(string tit,string sub){
        for_each(tit.begin(), tit.end(), [](char & c) {
            c = ::tolower(c);
        });
        for_each(sub.begin(), sub.end(), [](char & c) {
            c = ::tolower(c);
        });
        return tit.find(sub)!=string::npos;
    };
Tag Game::convertiraTag(string tag){
            if(essubcad(tag,"INDIE"))  return Tag::INDIE;
            if(essubcad(tag,"ACTION")) return Tag::ACTION;
            if(essubcad(tag,"ADVENTURE")) return Tag::ADVENTURE;
            if(essubcad(tag,"CASUAL")) return Tag::CASUAL;
            if(essubcad(tag,"SIMULATION")) return Tag::SIMULATION;
            if(essubcad(tag,"RPG")) return  Tag::RPG;
            if(essubcad(tag,"STRATEGY")) return  Tag::STRATEGY;
            if(essubcad(tag,"IS2D")) return  Tag::IS2D;
            if(essubcad(tag,"SPORTS")) return  Tag::SPORTS;
            if(essubcad(tag,"PUZZLE")) return  Tag::PUZZLE;
            if(essubcad(tag,"SHOOTER")) return Tag::SHOOTER;
            if(essubcad(tag,"HORROR")) return Tag::HORROR;
    }
string Game::convertiraString(Tag *tag){
        string tagdef ,tags[3];
        int j;
        for(int i=0;i<num_tags;i++){
            switch (*tag)
            {
                case 0:  tags[i]="INDIE";
                case 1:   tags[i]="ACTION";
                case 2: tags[i]="ADVENTURE";
                case 3:   tags[i]="CASUAL";
                case 4:   tags[i]="SIMULATION";
                case 5: tags[i]="RPG";
                case 6:   tags[i]="STRATEGY";
                case 7: tags[i]="IS2D";
                case 8: tags[i]="SPORTS";
                case 9:   tags[i]="PUZZLE";
                case 10:  tags[i]="SHOOTER";
                case 11: tags[i]="HORROR";
                    for (j ; j < sizeof (tags[i]); ++j) {
                        tagdef[j]=tags[i][j];
                    }
            }
        }
        return tagdef;
    }
void Game::setTitle(std::string &title) {
    Game::title = title;
}

void Game::setReleaseDate(Date &releaseDate) {
    Game::releaseDate = releaseDate;
}

void Game::setPrice(float price) {
    Game::price = price;
}

void Game::setTags(Tag *tags) {
    Game::tags = tags;
}

int Game::getId(){
    return id;
}

string &Game::getTitle(){
    return title;
}

Date &Game::getReleaseDate(){
    return releaseDate;
}


Tag *Game::getTags(){
    return tags;
}



