#include "groupe.hpp"
#include "couleur.hpp"
#include<iostream>


using namespace std;

Groupe :: Groupe(std::string nom, Couleur couleur, int taille): couleur_(couleur), mapPersonne(){
    nom_groupe = nom;
    taille = taille;
    LPersonne.dernier = nullptr;
    LPersonne.premier = nullptr;
    LPersonne.nb = 0;
}

int Groupe :: gettaille() {  
    return taille;
}

Groupe :: ~Groupe(){
    cout << "fin" << endl;
}

Personne Groupe :: getPersonne(int id){ 
    return mapPersonne.at(id)->info;
}

Personne Groupe :: getleader(){
   return LPersonne.premier->info;
}

void Groupe :: insererPersonne(std::string nom){  
    Personne* p = new Personne(nom);
    maillon* tmp;
    tmp->info = *p;
    tmp->suivant = nullptr;
    tmp->precedent = LPersonne.dernier;
    LPersonne.nb++;
    if(LPersonne.nb == 0 ){//liste vide
        LPersonne.premier = tmp;
        LPersonne.dernier = tmp;
        LPersonne.nb++;
    }else{
        LPersonne.dernier->suivant = tmp;
        LPersonne.dernier = tmp;
        LPersonne.nb++;
    }
    mapPersonne.insert(pair<int,maillon*>(p->getId(),tmp));
}

void Groupe :: supprimerPersonne(int id){  
    //rechercher dans la map
    maillon* tmp = mapPersonne.at(id);
    if(tmp == nullptr)//cas ou la liste vide ou id introuvable
        cout << "Liste vide " << endl;
    else{ 
        if(LPersonne.nb == 1){ //si dans la liste y'a un seul maillon
            LPersonne.dernier = nullptr;
            LPersonne.premier = nullptr;
            LPersonne.nb = 0;
            mapPersonne.erase(id);  //supprimer dans la map
        }else{
            if(LPersonne.premier==tmp){//si c'est la premiere personne
                LPersonne.premier = LPersonne.premier->suivant;
            }else{
                if(tmp->suivant == nullptr){//c'est la derniere personne dans la liste
                    tmp->precedent->suivant = nullptr;
                }else{//une personne au milieu de la liste
                    tmp->precedent->suivant = tmp->suivant;
                    tmp->suivant->precedent = tmp->precedent;
                }
            }
        }
        LPersonne.nb--;
        mapPersonne.erase(id);  //supprimer dans la map
    }
}

void Groupe :: suprimerPremierePersonne(){
    maillon* tmp = LPersonne.premier;
    if(LPersonne.nb == 0)
        cout << "ERREUR : Liste vide " << endl;
    else if(LPersonne.nb == 1){  //si un seul maillon(premier = dernier)
            tmp = LPersonne.premier;
            LPersonne.premier = nullptr;
            LPersonne.dernier = nullptr;
            LPersonne.nb--;  
            mapPersonne.erase(tmp->info.getId()); //suppression dans la map
        }else{  //plus de un maillon
            LPersonne.premier = LPersonne.premier->suivant;
            LPersonne.premier->precedent = nullptr;
            LPersonne.nb--;  
            mapPersonne.erase(tmp->info.getId()); //suppression dans la map
        }
    delete tmp;
}
