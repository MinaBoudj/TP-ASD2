#include "personne.hpp"
#include<iostream>

using namespace std;

Personne :: Personne(string name){
    name = name;
    identifiant = id;
    id++;
    position.x = 0;
    position.y = 0;
}

string Personne :: getName(){
    return name;
}

int Personne :: getId(){
    return identifiant;
}

Position Personne :: getPosition(){
    return position;
}

void Personne :: afficherPersonne(){
    cout << "Name : " << getName() << ", id : " << getId() << ", position : " << getPosition().x << "," << getPosition().y <<endl;
}
