#include "groupe.hpp"
#include<iostream>


using namespace std;

Groupe :: Groupe(std::string nom, std::string couleur, int taille){
    nom_groupe = nom;
    couleur = couleur;
    taille = taille;
}

int Groupe :: gettaille() {  
    return taille;
}

Groupe :: ~Groupe(){
    cout << "fin" << endl;
}

Personne Groupe :: getPersonne(int id){
   iterator it = LPersonne.begin();
   bool trouver = false;
   while(trouver && it != LPersonne.end()){
        if((*it).getId() == id)
            trouver = true;
        it++;
   }
   return *it;
}

Personne Groupe :: getleader(){
    iterator it = LPersonne.begin();
    return *it;
}

void Groupe :: insererPersonne(std::string nom){
    Personne p = Personne(nom);
    LPersonne.push_back(p);
}

void Groupe :: supprimerPersonne(int id){
    //LPersonne.remove(getPersonne(id));
}

void Groupe :: suprimerPremierePersonne(){
    LPersonne.pop_front();
}
