#include "manif.hpp"
#include<iostream>

using namespace std;

/// @brief constructeur d'une manif vide
/// @param longeur
/// @param largeur
/// @param cortege
Manif :: Manif(int longeur, int largeur, Cortege cortege) : longueur_(longeur), largeur_(largeur), grille_(), cortege_(cortege){
    for(int i=0; i<longeur; i++){
        for(int j=0; j<largeur; j++){
            grille_[i][j] = nullptr;
        }
    }
}

/// @brief distructeur
Manif::~Manif(){
    cout << "fin" << endl;
}

/*
/// @brief simulation d'une étape(verifier qu'il y'a au moins une Personne dans la grille)
void Manif :: simulationEtape(){
    if(nbManifestant == 0){//vérification de la grille non vide
        cout << "Erreur : Grille vide" << endl;
    }else{
        //TODO
        if(nbEtape == 0){
            for(int i=0; i<largeur_; i++){
                grille_[longueur_][i] = &(cortege_.get_groupes()[i].get_LPersonne().premier->info);
                cortege_.delete_personne(grille_[longueur_-nbEtape][i]->getId());
                nbManifestant = largeur_;
            }
            nbEtape ++;
        }else{
            if(testFin()){
                    cout << "Fin de la simulation" << endl;
            }else if(longueur_ - nbEtape <= 0){
                //sortir les personnes a la pos 0
                nbManifestant = 0;
            }else{

            }
                for(int i=0; i<largeur_; i++){
                while(cortege_.get_groupes().size() != 0){
                    grille_[longueur_-nbEtape][i] = &(cortege_.get_groupes()[i].get_LPersonne().premier->info);
                    cortege_.delete_personne(grille_[longueur_-nbEtape][i]->getId());
                    nbManifestant ++ ;
                }
                }
                nbEtape++;
            }
            
        }
        
    }
}*/

void Manif::simulationEtape() {
    // Avancer toutes les personnes présentes sur la grille d'un pas en avant
    for (int i = longueur_ - 1; i >= 0; i--) {
        for (int j = largeur_ - 1; j >= 0; j--) {
            if (grille_[i][j] != nullptr) {
                if (i == longueur_ - 1) {
                    // Si la personne est sur la dernière ligne, on la retire de la grille
                    grille_[i][j] = nullptr;
                } else {
                    // Sinon, on la déplace d'un pas en avant
                    grille_[i+1][j] = grille_[i][j];
                    grille_[i][j] = nullptr;
                }
            }
        }
    }
    /*
    // Faire avancer les 5 premières personnes du cortège sur la première ligne
    ListPersonne& LPersonne = cortege_.get_list_personne();
    maillon* p = LPersonne.premier;
    int compteur = 0;
    while (p != nullptr && compteur < 5) {
        // Ajouter la personne sur la grille
        grille_[0][compteur] = &(p->info);
        
        // Avancer le compteur et le pointeur
        compteur++;
        p = p->suivant;
    }
    
    // Si la dernière ligne de la grille est vide, on y ajoute une personne non encore apparue
    if (grille_[longueur_-1][largeur_-1] == nullptr) {
        maillon* personne_non_vue = LPersonne.get_personne_non_vue();
        if (personne_non_vue != nullptr) {
            grille_[longueur_-1][largeur_-1] = &(personne_non_vue->info);
            LPersonne.deplacer_personne_non_vue();
        }
    }*/
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

Personne* Manif :: leaders(){
    Personne* leaders = nullptr;
    int i =0;
    if(cortege_.get_groupes().size() == 0){//pas de manifestant 
        leaders = nullptr;
    }else{
        iterator it = cortege_.get_groupes().begin();
        while(it != cortege_.get_groupes().end()){
            leaders[i] = (*it).getleader();
            ++it;
            i++;
        }
        
    }
    return leaders;
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

void Manif :: affciher_grille(){
    for(int i=0; i<longueur_; i++){
        cout << " " ;
        for(int j=0; j<largeur_; j++){
            if(grille_[i][j]== nullptr)
                cout << "- ";
            else{
                Groupe* groupe = get_Groupe(grille_[i][j]->getId());
                groupe->getCouleur().afficher(cout, grille_[i][j]->getName());
            }
        }
        cout << endl;;
    }
}