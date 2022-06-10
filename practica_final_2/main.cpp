#include <iostream>
#include <cassert>
#include "User.h"
#include "Date.h"
#include "Game.h"
#include "Review.h"
#include "GameList.h"
#include "UserList.h"

using namespace std;

int main(){
    User diego_huerta(1, "Diego", "Huerta", "diego@huerta.com", Date(10, 12, 1994), MALE);
    User elsa_reina(2, "Elsa", "Reina", "elsa@reina.com", Date(3, 6, 1987), FEMALE);
    User sandra_tellez(3, "Sandra", "Téllez", "sandra@tellez.com", Date(23,7,2003), FEMALE);
    User jose_contreras(4, "Jose Manuel", "Contreras", "jose@contreras.com", Date(26,5,1996), MALE);
    User jorge_ocasio(5, "Jorge", "Ocasio", "jorge@ocasio.com", Date(27,7,1996), MALE);
    User ainhoa_elizondo(6, "Ainhoa", "Elizondo", "ainhoa@elizondo.com", Date(18,4,1959), FEMALE);

    Tag ds[2] = {ACTION, ADVENTURE};
    Tag a3[2] = {ACTION, SHOOTER};
    Tag pp[2] = {PUZZLE, INDIE};
    Tag bl[2] = {IS2D, ADVENTURE};
    Tag er[2] = {ACTION, ADVENTURE};
    Tag aoe[1] = {STRATEGY};

    Game death_stranding(1, "Death Stranding", Date(30,3,2022), 39.99, ds, 2);
    Game arma_iii(2, "Arma III", Date(13,9,2013), 27.99, a3, 2);
    Game patricks_parabox(3, "Patrick'sParabox", Date(29,3,2022), 16.79, pp, 2);
    Game blasphemous(4, "Blasphemous", Date(10,9,2019), 24.99, bl, 2);
    Game elden_ring(5, "Elden Ring", Date(25,2,2022), 59.99, er, 2);
    Game age_of_empires(6, "Age of Empires IV", Date(28,10,2021), 59.99, aoe, 1);
    diego_huerta.addFunds(150);
    elsa_reina.addFunds(20);
    sandra_tellez.addFunds(150);
    jose_contreras.addFunds(150);
    jorge_ocasio.addFunds(150);
    ainhoa_elizondo.addFunds(500);

    assert(diego_huerta.purchaseGame(&arma_iii));
    assert(diego_huerta.purchaseGame(&blasphemous));
    assert(diego_huerta.addToWishlist(&elden_ring));
    assert(diego_huerta.addToWishlist(&arma_iii)==false);

    assert(elsa_reina.purchaseGame(&elden_ring)==false);

    assert(ainhoa_elizondo.purchaseGame(&death_stranding));
    assert(ainhoa_elizondo.purchaseGame(&arma_iii));
    assert(ainhoa_elizondo.purchaseGame(&patricks_parabox));
    assert(ainhoa_elizondo.purchaseGame(&blasphemous));
    assert(ainhoa_elizondo.purchaseGame(&elden_ring));
    assert(ainhoa_elizondo.purchaseGame(&age_of_empires));

    Review review1("¡Juegazoooo!", true, &elden_ring, &ainhoa_elizondo);
    Review review2("Caca de la vaca... -.-!", false, &patricks_parabox, &ainhoa_elizondo);
    Review review3("No está mal...¡para haberlo pirateado!:P", true, &arma_iii, &diego_huerta);

    assert(ainhoa_elizondo.addReview(&review1));
    assert(ainhoa_elizondo.addReview(&review2));
    assert(diego_huerta.addReview(&review3)); //no entiendo porque diego_huertano podria añadir una review si a comprado el Arama III//
    assert(diego_huerta.addReview(&review1)==false);
	
    char *car;
    int num;
	Game **juego2;
    GameList juego("games.txt"); 
juego.find("Blas", 2002, 2030,juego2 , num);
    juego.add(&death_stranding);
    return 0;
}
