#include "groupe.hpp"
#include "couleur.hpp"
#include<iostream>


using namespace std;

Groupe :: Groupe(std::string nom, Couleur couleur, int taille): nom_groupe(nom),couleur_(couleur),taille_(taille), mapPersonne(){
    couleur.creer(couleur.nom());
    LPersonne.dernier = nullptr;
    LPersonne.premier = nullptr;
    LPersonne.nb = 0;
}

int Groupe :: gettaille() {  
    return this->taille_;
}

Couleur Groupe :: getCouleur(){
    return this->couleur_;
}

string Groupe :: get_nom(){
    return this->nom_groupe;
}

ListPersonne Groupe :: get_LPersonne(){
    return LPersonne;
}

Groupe :: ~Groupe(){
}

Personne* Groupe :: getPersonne(int id){ //demander si dans la map il renvoie nullptr s'il l trouve pas
    auto it = mapPersonne.find(id);
    if (it != mapPersonne.end()) {
        return &mapPersonne.at(id)->info;
    } else {
        return nullptr;
    }
}


Personne Groupe :: getleader(){
    return LPersonne.premier->info;
}

void Groupe :: insererPersonne(std::string nom){ 
    Personne p =  Personne(nom);    
    maillon* tmp = new maillon;
    tmp->info = p;
    tmp->suivant = nullptr;
    tmp->precedent = LPersonne.dernier;
    if(LPersonne.nb == 0 ){//liste vide
        LPersonne.premier = tmp;
        LPersonne.dernier = tmp;
        LPersonne.nb++;
    }else{
        LPersonne.dernier->suivant = tmp;
        LPersonne.dernier = tmp;
        LPersonne.nb++;
    }
    mapPersonne.insert(pair<int,maillon*>(p.getId(),tmp));
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
    //delete tmp;
}

void Groupe :: afficher_groupe(){
    maillon* tmp = LPersonne.premier;
    cout << "Groupe " << nom_groupe << " : "  << endl;
    while(tmp != nullptr){
        tmp->info.afficherPersonne();
        tmp = tmp->suivant;
    }
    
}