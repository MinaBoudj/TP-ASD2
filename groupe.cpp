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
    return mapPersonne.at(id);
}

Personne Groupe :: getleader(){
    iterator it = LPersonne.begin();
    return *it;
}

void Groupe :: insererPersonne(std::string nom){   
    Personne p = Personne(nom);
    LPersonne.push_back(p);
    mapPersonne.insert(pair<int,Personne>(p.getId(),p));
}

void Groupe :: supprimerPersonne(int id){   
    mapPersonne.erase(id);  //supprimer dans la map
    //LPersonne.remove_if(getPersonne(id).getId()==id);
    //LPersonne.remove(getPersonne(id));
}

void Groupe :: suprimerPremierePersonne(){  
    mapPersonne.erase(LPersonne.begin()->getId());  //supprimer dans la map 
    LPersonne.pop_front();  //puis dans la liste
}
