//
// Created by anuar on 11/04/2022.
//

#include <iostream>
#include <cassert>
#include "User.h"
using namespace std;
User::User(){
    id=0;
    name="  ";
    surname="  ";
    email="test@gmail.com";
    gender=OTHER;
    birthdate={0,0,0};
    num_games=0;
    num_wished=0;
    num_reviews=0;
    num_friends=0;
    max_games_library=0;
    max_wished=0;
    num_wished=0;

};
User::User(int id2,string name2,string surname2,string email2,Date birthdate2, Gender gender2) {
    id=id2;
    name=name2;
    surname=surname2;
    email=email2;
    gender=gender2;
    birthdate=birthdate2;
    funds=0;
    num_wished=0;
    num_games=0;
    num_reviews=0;
    num_friends=0;
    max_wished=4;
    max_games_library=4;
    max_friends=4;
    max_reviews=4;
    library= new Game *[max_games_library];
    whishlist= new Game *[max_wished];
    reviews=new Review*[max_reviews];
    friends= new User *[max_friends];
for (int i = 0; i < max_games_library; ++i) {
        library[i]=0;
    }
    for (int i = 0; i < max_wished; ++i) {
        whishlist[i]=0;
    }
    for (int i = 0; i < max_reviews; ++i) {
        reviews[i]=0;
    }
    for (int i = 0; i < max_friends; ++i) {
        friends[i]=0;
    }
}
int User::operator+=(int cant) {
    funds+=cant;
    return funds;
};
int User::operator +(const User &usuario2){
    return this->funds+usuario2.funds;
};
User::User(int maxFriends2, int max_games_library2, int numWished2, int numReviews2){
    if (max_games_library2>=4 && numWished2>=4 && numReviews2>=4 && maxFriends2>=4){
        library= new Game *[max_games_library2];
        whishlist= new Game *[numWished2];
        reviews=new Review*[numReviews2];
        friends= new User *[maxFriends2];
    }
}
int User::get_num_games(){
    return num_games;
};
int User::get_num_wished(){
    return num_wished;
};
int User::get_num_reviews(){
    return num_reviews;
};
int User::get_num_users(){
    return id;
};
int User::get_funds(){
    return funds;
};
Game ** User::get_library(){
    return library;
};
Game **User::get_whishlist(){
    return whishlist;
};
Review **User::get_reviews(){
    return reviews;
};
User **User::get_friends(){
    return friends;
};
bool User::addFunds(float amount) {
    if (amount>0){
        funds=funds+amount;
        return true;
    }
    else{
        return false;
    }
};
bool User::purchaseGame(Game *game) {
    bool x= true;
    Game **library2;
    for (int i = 0; i <= num_games; ++i) {
        if (game==whishlist[i] || game == library[i] || game->getPrice()>funds){
            x= false;
        }
    }
    if (num_games==max_games_library){
        max_games_library=max_games_library*2;
        library2=new Game *[max_games_library];
        for (int j = 0; j < num_games; ++j) {
            library2[j]=library[j];
        }
        library=new Game *[max_games_library];
        library=library2;
	delete [] library2;
    }
    if (x){
        library[num_games]= game;
        funds-=game->getPrice();
        num_games++;
    }
    return x;
}
bool User::addToWishlist(Game* game){
    bool x= true;
    Game** whislist2;
    whislist2= new Game *[max_wished];
    for (int i = 0; i < max_games_library; ++i) {
        if (game == whishlist[i] || game== library[i] ){
            x= false;
        }
    }
        if (num_wished==max_wished){
            max_wished++;
            whislist2=new Game *[max_wished];
            for (int j = 0; j < max_wished; ++j) {
                whislist2[j]=whishlist[j];
            }
            whishlist=new Game *[max_wished];
                whishlist=whislist2;
		delete [] whislist2;
        }

    if (x){
        whishlist[num_wished]=game;
        num_wished++;
    }
    return x;
};
bool User::removeFromWishlist(Game* game) {
    bool x = true;
    Game** whislist2;
    for (int i = 0; i < max_wished; ++i) {
        if (game != whishlist[i]) {
            x = false;
            num_wished--;
        }
    }
    if (num_wished<=max_wished/2){
        max_wished=max_wished/2;
        whislist2=new Game *[max_wished];
        for (int j = 0; j < max_wished; ++j) {
            whislist2[j]=whishlist[j];
        }
        whishlist=new Game *[max_wished];
        whishlist=whislist2;
	delete [] whislist2;
    }
    if (x) {
        for (int i = 0; i < max_wished; ++i) {
            if (game==whishlist[i]){
                whishlist[i]=NULL;
            }
            else if (whishlist[i] == NULL) {
                whishlist[i] = whishlist[i + 1];
            }
        }
    }
    return x;
}
bool User::addReview(Review* review){
    bool x= true;
    for (int i = 0; i < num_games; ++i) {
        if(library[i]==review->getGame() && id==review->getAuthor()->id){
            x= true;
            break;
        } else{
            x=false;
        }
    }
    if (x){
        reviews[num_reviews]=review;
        num_reviews++;
    }
    return x;

};
bool User::removeReview(Review *review) {
    bool x;
    for (int i = 0; i < max_games_library; ++i) {
        if(review[i].getAuthor()->name==name && library[i]==review->getGame()){
            if (reviews[i]==review){
                reviews[i]=reviews[i+1];
                x=true;
            } else{
                 x=false;
            }
        }
    }
    return x;
};
bool User::addFriend(User* user){
    *friends=user;
    return true;
};
bool User::removeFriend(User* user){
    bool x;
    for (int i = 0; i < max_friends; ++i) {
        if(friends[i]==user){
            friends=NULL;
            x=true;
        }else{
            x=false;
        }
    }
    return x;
}

User::~User() {

}

void User::setName(const string &name) {
    User::name = name;
}

void User::setSurname(const string &surname) {
    User::surname = surname;
}

void User::setEmail(const string &email) {
    User::email = email;
}

void User::setBirthdate(const Date &birthdate) {
    User::birthdate = birthdate;
}

void User::setGender(Gender gender) {
    User::gender = gender;
}

void User::setFunds(float funds) {
    User::funds = funds;
}

void User::setNumGames(int numGames) {
    num_games = numGames;
}

int User::getId() const {
    return id;
}

const string &User::getName() const {
    return name;
}

const string &User::getSurname() const {
    return surname;
}

const string &User::getEmail() const {
    return email;
}

const Date &User::getBirthdate() const {
    return birthdate;
}

Gender User::getGender() const {
    return gender;
}

float User::getFunds() const {
    return funds;
}
