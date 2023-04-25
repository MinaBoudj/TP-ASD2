#include "manif.hpp"
#include<iostream>

using namespace std;

/// @brief constructeur d'une manif vide
/// @param longeur
/// @param largeur
/// @param cortege
Manif :: Manif(int longeur, int largeur, Cortege cortege) : longueur_(longeur), largeur_(largeur), cortege_(cortege){
    grille_.resize(longueur_, std::vector<Personne*>(largeur_, nullptr));
    for(int i=0; i<longueur_; i++){
        for(int j=0; j<largeur_; j++){
            grille_[i][j] = nullptr;
        }
    }
}

/// @brief distructeur
Manif::~Manif(){
    cout << "fin" << endl;
}

Cortege Manif :: get_Cortege(){
    return this->cortege_;
}

/// @brief simulation d'une étape(verifier qu'il y'a au moins une Personne dans la grille)
void Manif :: simulationEtape(){
    if(nbManifestant == 0){//vérification de la grille non vide
        cout << "Erreur : Grille vide Fin de la simulation" << endl;
    }else{
        //TODO
        if(nbEtape == 0){ //la premiere etape
            vector<Groupe> groupes = cortege_.get_groupes();
            auto it = groupes.begin();
            maillon* tmp = it->get_LPersonne().premier;
            nbManifestant = 0;
            int cpt = 0;
            while(tmp != nullptr && nbManifestant <= largeur_){
                grille_[longueur_-1][nbManifestant] = &(tmp->info);
                nbManifestant ++;
                tmp = tmp->suivant;
                cpt++;
                if(cpt == (*it).gettaille()){
                    ++it;
                    cpt = 0;
                    tmp = (*it).get_LPersonne().premier;
                }
            }
            nbEtape++;
            nbManifestant -- ;
            cout << "nbManifestant :" << nbManifestant << ", nbEtape : " << nbEtape << endl;
        }else{
            cout << "Etape 2 " << endl;
            //verifier que etape == largeur-1 pour sortir les personnes
            // avancer les personnes 
        }
    }
}


/// @brief tester si c'est la fin de la manif; quand la grille est vide donc plus personne dans le cortege
/// @return true si tous les groupes du cortege on défilé, false sinon
bool Manif :: testFin(){
    return cortege_.get_groupes().size() == 0;
    //nbManifestant == 0
}

/// @brief accés à une personne à partir de son identifiant
/// @param id 
/// @return pointeur vers la personne si elle est dans le cortege, false sinon
Personne* Manif :: getPersonne(int id ){
    return cortege_.getPersonne(id);
}

/// @brief supprimer une personne à partir de son identifiant
/// @param id 
void Manif :: supprimerPersonne(int id){
    cortege_.delete_personne(id);
}

void  Manif :: leaders(){
    int i =0;
    if(cortege_.get_groupes().size() == 0){//pas de manifestant 
        cout << "Erreur : cortege vide" << endl;
    }else{
        vector<Groupe> groupes = cortege_.get_groupes();
        cout << "Leaders :: " ;
        for (auto it = groupes.begin(); it != groupes.end(); ++it) {
            cout << (*it).getleader().getName() << ", ";
        }
        cout << endl;
    }
}

Groupe* Manif :: get_Groupe(int id){
    int i = 0;
    while(i<cortege_.get_groupes().size()){
       if(cortege_.get_groupes()[i].getPersonne(id) != nullptr){
            return &(cortege_.get_groupes()[i]);
        }
        i++;
    }
    return nullptr;
}

void Manif :: afficher_grille(){
    for(int i=0; i<longueur_; i++){
        cout << " " ;
        for(int j=0; j<largeur_; j++){
            if(grille_[i][j]== nullptr)
                cout << "- ";
            else{
                Groupe* groupe = get_Groupe(grille_[i][j]->getId());
                cout << grille_[i][j]->getName()[0] << " " ;
                //groupe->getCouleur().afficher(cout, grille_[i][j]->getName());
            }
        }
        cout << endl;;
    }
}