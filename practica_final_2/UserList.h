//
// Created by anuar on 17/05/2022.
//

#ifndef DATE_H_USERLIST_H
#define DATE_H_USERLIST_H
const int MAX_USERS=1000;
const int MAX_REVIEWS=2000;
#include "User.h"
#include "Game.h"
#include "GameList.h"
#include "iostream"
using namespace std;
class UserList {
     int current_size;
     User* list[MAX_USERS];
     int number_of_reviews;
     Review* reviews[MAX_REVIEWS];
public:
    UserList();
    UserList(char *users_file_path, char *reviews_file_path, GameList &games);

    bool dump(string users_file_path, string reviews_file_path);

    int getCurrentSize() const;

    User *const *getList() const;

    int getNumberOfReviews() const;

    Review *const *getReviews() const;

    void setCurrentSize(int currentSize);

    void setNumberOfReviews(int numberOfReviews);

	~UserList();
};


#endif //DATE_H_USERLIST_H
