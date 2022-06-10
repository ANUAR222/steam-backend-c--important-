//
// Created by anuar on 17/05/2022.
//

#include "UserList.h"
UserList::UserList(char *users_file_path, char *reviews_file_path, GameList &games){
    int n1,n2,id;
    User *usuario;
    Review *reviw;
    string nombre,apellid,email,tag ,text,genero;
    Gender gner;
    bool like;
    Date cumple;
    ifstream f,l;
    char temp[100];
    f.open(users_file_path);
    l.open(reviews_file_path);
    GameList n;
    n2=n.Numfilas(reviews_file_path);
    n1=n.Numfilas(users_file_path);
    if (f.is_open()) {
        cout << "failed to open " << users_file_path << '\n';
    } else {
        for (int i = 0; i < n1; ++i) {
            f.getline(temp,100,';');
            id= atoi(temp);
            f.getline(temp,100,';');
            nombre=temp;
            f.getline(temp,100,';');
            apellid=temp;
            f.getline(temp,100,';');
            email=temp;
            f.getline(temp,100,'/');
            cumple.setDia(atoi(temp));
            f.getline(temp,100,'/');
            cumple.setMes(atoi(temp));
            f.getline(temp,100,';');
            cumple.setAnio(atoi(temp));
            f.getline(temp,100,';');
            tag=temp;
	    if (n.essubcad(genero,"MALE")){ gner=MALE;}//es muy especifica para hacer una función//
            if (n.essubcad(genero,"FEMALE")){gner=FEMALE;} 
            if (n.essubcad(genero,"OTHER")){ gner=OTHER;}
            usuario=new User(id,nombre,apellid,email,cumple,gner);
            list[current_size]=usuario;
            current_size++;
        }
    }
        if (l.is_open()) {
            cout << "failed to open " << users_file_path << '\n';
        } else {
            for (int i = 0; i < n1; ++i) {
                l.getline(temp,100,';');
                text= temp;
                l.getline(temp,100,';');
                like=temp;
                reviw=new Review(text,like,games.getFirstBlock()->list[games.getFirstBlock()->current_size],usuario);
                reviews[i]=reviw;
            }

    }
        l.close();
        f.close();
	delete usuario;
	delete reviw;
}
bool UserList::dump(string users_file_path, string reviews_file_path){
    fstream f;
    fstream l;
    GameList n;
    int sf;
    int sl;
    sf=n.Numfilas((char *)(users_file_path.c_str()));
    sl=n.Numfilas((char *)(reviews_file_path.c_str()));
    f.open(users_file_path);
    l.open(reviews_file_path);
    if (!f.is_open()) {
        cout << "failed to open "<<'\n';
    } else {
        for (int i = 0; i < sf; ++i) {
            f<<to_string(list[i]->getId())<<";"<<list[i]->getName()
            <<";"<<list[i]->getSurname()<<";"<<list[i]->getEmail()<<";"<<
            to_string(list[i]->getBirthdate().getAnio())<<";"<<
            to_string(list[i]->getBirthdate().getMes())<<";"<<
            to_string(list[i]->getBirthdate().getDia())<<endl;
        }
    }
    if (!l.is_open()) {
        cout << "failed to open "<<'\n';
    } else {
        for (int i = 0; i < sf; ++i) {
            l<<list[i]->getId()<<";"<<reviews[i]->getText()<<reviews[i]->isLike();
        }
    }
    f.close();
    l.close();
    return true;
};
UserList::UserList(){
    this->current_size=0;
    *list=NULL;
    this->number_of_reviews=0;
    *reviews=NULL;
}


int UserList::getCurrentSize() const {
    return current_size;
}

User *const *UserList::getList() const {
    return list;
}

int UserList::getNumberOfReviews() const {
    return number_of_reviews;
}

Review *const *UserList::getReviews() const {
    return reviews;
}

void UserList::setCurrentSize(int currentSize) {
    current_size = currentSize;
}

void UserList::setNumberOfReviews(int numberOfReviews) {
    number_of_reviews = numberOfReviews;
};
UserList::~UserList() {
delete [] list;
delete [] reviews;
}
