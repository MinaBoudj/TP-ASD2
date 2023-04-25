#include "personne.hpp"
#include<iostream>

using namespace std; 

int Personne :: id = 1;
Personne :: Personne(string name){
    this->name = name;
    this->identifiant = id;
    id++;
    this->position.x = 0;
    this->position.y = 0;
}

string Personne :: getName() const{
    return this->name;
}

int Personne :: getId() const{
    return this->identifiant;
}

Position Personne :: getPosition() const{
    return this->position;
}

void Personne :: afficherPersonne(){
    cout << "Nom : " << getName() << ", id : " << getId() << ", position : " << getPosition().x << "," << getPosition().y <<endl;
}

