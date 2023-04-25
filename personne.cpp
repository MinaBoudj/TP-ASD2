#include "personne.hpp"
#include<iostream>

using namespace std; 

int Personne :: id = 1;
Personne :: Personne(string name){
    name = name;
    identifiant = id;
    id++;
    position.x = 0;
    position.y = 0;
}

string Personne :: getName() const{
    return name;
}

int Personne :: getId() const{
    return identifiant;
}

Position Personne :: getPosition() const{
    return position;
}

void Personne :: afficherPersonne(){
    cout << "Name : " << getName() << ", id : " << getId() << ", position : " << getPosition().x << "," << getPosition().y <<endl;
}

