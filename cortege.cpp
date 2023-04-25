#include "cortege.hpp"
#include<iostream>
#include<algorithm>

using namespace std;

/// @brief constructeur d'un cortege vide
/// @param nom 
Cortege :: Cortege(std::string nom): nom_cortege_(nom){}


/// @brief distructeur
Cortege::~Cortege(){
}
///@brief retourne les groupes
vector<Groupe> Cortege :: get_groupes(){
    return groupes_;
}

/// @brief insertion d'un groupe dans le cortege
/// @param groupe 
void Cortege :: insert_Groupe(Groupe groupe){
    groupes_.push_back(groupe);
}

/// @brief suppression du groupe à partir de son nom
/// @param nom_groupe 
void Cortege ::delete_Groupe(string nom_groupe){
    //auto it = find(groupes_.begin(), groupes_.end(), nom_groupe);
   auto it = find_if(groupes_.begin(), groupes_.end(), [nom_groupe](Groupe& groupe){
        return groupe.get_nom() == nom_groupe;
    });


    if (it != groupes_.end()){
        cout << "Groupe trouver : Suppresion"<< endl;
        groupes_.erase(it);
    }else
        cout << "Ce groupe n'est pas dans le cortege\n";
    
} 

/// @brief accés à une personne à partir dans son id; renvoie l'@ de la personne si elle existe, nullptr sinon
/// @param id    
Personne* Cortege :: getPersonne(int id){
    for (auto groupe : groupes_) {
        if (groupe.getPersonne(id) != nullptr)
            return groupe.getPersonne(id);
    }
    return nullptr; 
}

/// @brief suppresion d'une personne à  partir de son id
/// @param id 
void Cortege :: delete_personne(int id){
    iterator it  = groupes_.begin();
    bool trouver = false;
    while(it != groupes_.end() && trouver){
        if(it->getPersonne(id) != nullptr)
            trouver = true;
        else
            it++;
    }
    if(trouver)
        it->supprimerPersonne(id);
    else    
        cout << "La personne n'est dans aucun groupe du cortège" << endl;
} 


/// @brief trie par taille les groupes du cortège
void Cortege :: tri_taille(){
    sort(groupes_.begin(), groupes_.end(), []( Groupe& g1,  Groupe& g2){
            return g1.gettaille() < g2.gettaille();
    });
}



/// @brief trie par couleur les groupes du cortège
void Cortege :: tri_couleur(){
    sort(groupes_.begin(), groupes_.end(), []( Groupe& g1,  Groupe& g2){
            return g1.getCouleur().nom() < g2.getCouleur().nom();
    });
}


void Cortege :: afficher_cortege(){
    cout << endl;
    iterator it = groupes_.begin();
    while(it != groupes_.end()){
        (*it).afficher_groupe();
        cout << endl;
        ++it;
    }
}

