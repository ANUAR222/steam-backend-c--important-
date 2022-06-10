//
// Created by anuar on 11/04/2022.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H


#include <iostream>
#include "Game.h"
#include "Date.h"
#include "Review.h"
using namespace std;
enum Gender {FEMALE, MALE, OTHER};
class Review;
class Game;
class User {
    int id;
    string name; // Nombre
    string surname; // Apellido/s
    string email; // Correo electrónico
    Date birthdate; // Fecha de nacimiento
    Gender gender; // Género
    float funds; // Dinero disponible en la cuenta

    int max_games_library; // Tamaño del vector "library"
    int max_wished; // Tamaño del vector "wishlist"
    int max_reviews; // Tamaño del vector "reviews"
    int max_friends; // Tamaño del vector "friends"

    int num_games; // Número de juegos en "library"
    int num_wished; // Número de juegos en "wishlist"
    int num_reviews; // Número de análisis en "reviews"
    int num_friends; // Número de usuarios en "friends"

    Game** library; // La lista de juegos que el usuario
    // tiene en su librería (que ha comprado)

    Game** whishlist; // La lista de juegos que el usuario ha
    // marcado como deseados (no los tiene comprados)

    Review** reviews; // La lista de análisis realizados por el usuario

    User** friends; // Lista de amigos del usuario
public:
    User();
    User(int id2,string name2,string surname2,string email2,Date birthdate2, Gender gender2);
    User(int maxFriends2, int max_games_library2, int numWished2, int numReviews2);
    int operator +=(int cant);
    int operator +(const User &usuario2);
    bool addFunds(float amount);
    bool purchaseGame(Game* game);
    bool addToWishlist(Game* game);
    bool removeFromWishlist(Game* game);
    bool addReview(Review* review);
    bool removeReview(Review* review);
    bool addFriend(User* user);
    bool removeFriend(User* user);
    //metods get
    int get_num_games();
    int get_num_wished();
    int get_num_reviews();
    int get_num_users();
    int get_funds();
    int getId() const;
    const string &getName() const;
    const string &getSurname() const;
    const string &getEmail() const;
    const Date &getBirthdate() const;
    Gender getGender() const;
    float getFunds() const;
    void setName(const string &name);
    void setSurname(const string &surname);
    void setEmail(const string &email);
    void setBirthdate(const Date &birthdate);
    void setGender(Gender gender);
    void setFunds(float funds);
    void setNumGames(int numGames);
    Game **get_library();
    Game **get_whishlist();
    Review **get_reviews();
    User **get_friends();
    ~User();
};


#endif //MAIN_CPP_USER_H
