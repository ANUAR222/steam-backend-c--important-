//
// Created by anuar on 17/05/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameList.h"
GameList::GameList(){
    firstBlock=NULL;
    lastBlock=NULL;
};
int GameList::Numfilas (char *file_path){
    FILE *ptr_file; int c=0,n=0;char l;
    ptr_file = fopen(file_path,"rt");
    if (ptr_file == NULL)
    {
        puts("Error: No se encontró el archivo.");

    }
    while((c = fgetc(ptr_file)) != EOF){
        if( c == '\n')
            n++;
        putchar(c);
    }
    fclose(ptr_file);
    return n;

}
GameList::GameList(char *file_path){
    char temp[100];
    char aux;
    Game* pjuego;
    int id,day,month,year,numtags,x,numfila;
    float precio;
    string titulo,TAGs;
    string();
    Tag tag,*tags;
    Date* relase;
    ifstream f;
    firstBlock=new Block;
    lastBlock=nullptr;
    lastBlock=firstBlock;
    firstBlock->current_size=0;
    numero_filas= Numfilas(file_path);
    f.open(file_path);
    //LEER EL ARCHIVO:
    for (int i = 0; i < numero_filas; ++i){
        f.getline(temp,100,';');
        id=atoi(temp);
        f.getline(temp,100,';');
        titulo=temp;
        f.getline(temp,100,'/');
        day= atoi(temp);
        f.getline(temp,100,'/');
        month= atoi(temp);
        f.getline(temp,100,';');
        year= atoi(temp);
        f.getline(temp,100,';');
        precio= atof(temp);
        f.getline(temp,100,';');
        numtags= atoi(temp);
        tags=new Tag[numtags];
        for (int j = 0; j < numtags; ++j) {
            if (numtags-1==j){
                f.getline(temp,100,'\n');
                TAGs=temp;
            } else{
                f.getline(temp,100,',');
                TAGs=temp;
            }
            tags[j]=pjuego->convertiraTag(TAGs);
        }
        relase=new Date(day,month,year);
        pjuego=new Game(id, titulo, *relase, precio,tags, numtags);
        lastBlock->list[lastBlock->current_size]=pjuego;
        lastBlock->current_size++;
        if(lastBlock->current_size==10){
            lastBlock->next=new Block;
            lastBlock=lastBlock->next;
            lastBlock->current_size=0;
        }
    }
    f.close();
    delete relase;
    delete pjuego;
};

bool GameList::add(Game *game) {
    bool x;
    if (lastBlock->current_size==10){
        lastBlock->next=new Block;
        lastBlock=lastBlock->next;
        lastBlock->current_size=0;
        lastBlock->list[lastBlock->current_size]=game;
        lastBlock->current_size++;
        x= true;
    } else{
        lastBlock->list[lastBlock->current_size]=game;
	lastBlock->current_size++;
        x= true;

    }

    return x;
}

bool GameList::essubcad(string tit,string sub){
    for_each(tit.begin(), tit.end(), [](char & c) {
        c = ::tolower(c);
    });
    for_each(sub.begin(), sub.end(), [](char & c) {
        c = ::tolower(c);
    });
    return tit.find(sub)!=string::npos;
};
bool GameList::find(string title, int year_start, int year_end, Game** &results, int &num_results){
    bool x= true;
    int numresult=0;
    results=new Game*[100];
    for (int k = 0; k < lastBlock->current_size; ++k) {
        if (essubcad(title," ")) {
            if (essubcad(lastBlock->list[k]->getTitle(),title)) {
                results[numresult]= firstBlock->list[k];
                numresult++;
            }
        }
	else if (year_end!=-1 && year_start!=-1){
            if (year_start<lastBlock->list[k]->getReleaseDate().getAnio() && year_end>lastBlock->list[k]->getReleaseDate().getAnio()){
                results[numresult]= firstBlock->list[k];
                numresult++;
            }
        }else if (year_end==-1){
            if (year_start<lastBlock->list[k]->getReleaseDate().getAnio()){
                results[numresult]= firstBlock->list[k];
                numresult++;
            }
        }
    } 
    num_results=numresult;
    return x;
}
bool GameList::dump(char *file_path){/*usar con cuidado da errores de segmentacion*/
    fstream f;
	int j=0;
    numero_filas= Numfilas(file_path);
    f.open(file_path);    
    if (!f.is_open()) {
        return false;
    } else {
    lastBlock=firstBlock;
    for (int i = 0; i < numero_filas; ++i) {
 	if(i==9){
            lastBlock=lastBlock->next;
		j=0;
        }
        f<<lastBlock->list[j]->getId()<<";"<<lastBlock->list[i]->getTitle()<<
                to_string(lastBlock->list[j]->getReleaseDate().getDia())<<"/"<<
                to_string(lastBlock->list[j]->getReleaseDate().getMes())<<"/"<<
                to_string(lastBlock->list[j]->getReleaseDate().getAnio())<<";"<<
                to_string(lastBlock->list[i]->getPrice())<<";"<<lastBlock->list[i]
		->convertiraString(lastBlock->list[j]->getTags())<<endl;
		j++;
    }
    }
f.close();
    return true;
}

Block *GameList::getFirstBlock() const {
    return firstBlock;
}

Block *GameList::getLastBlock() const {
    return lastBlock;
}

GameList::~GameList() {
Block *aux;
for(int i;aux!=NULL;i++){
aux=lastBlock;
delete lastBlock;
aux=lastBlock->next;
}
}

