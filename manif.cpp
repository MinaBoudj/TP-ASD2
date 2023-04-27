#include "manif.hpp"
#include<iostream>


/// @brief constructeur d'une manif vide
/// @param longeur
/// @param largeur
/// @param cortege
Manif :: Manif(int longeur, int largeur, Cortege cortege) : longueur_(longeur), largeur_(largeur), cortege_(cortege){
    grille_.resize(longueur_, std::vector<Personne*>(largeur_, nullptr));
}


/// @brief distructeur
Manif::~Manif(){
    std::cout << "fin" << std::endl;
}

/// @brief recuperer le cortege
/// @return cortege_
Cortege Manif :: get_Cortege(){
    return this->cortege_;
}


/// @brief simulation d'une étape(verifier qu'il y'a au moins une Personne dans la grille)
void Manif :: simulationEtape(){
    if(testFin()){//vérification de la grille non vide
        std::cout << "\nEtape "<< nbEtape++  << " :";
        for(int i = 0; i<1; i++){
            int j = 0;
            while(grille_[i][j] != nullptr){
                grille_[i][j]->setPosition(0,0);
                grille_[i][j] = nullptr;
                j++;
            }
        }
        std::cout << "Fin de simulation : Grille vide : "<< std::endl;
    }else{
        if(nbEtape == 0){ //la premiere etape
            std::cout << "\nEtape "<< nbEtape  << " :";
            std::vector<Groupe> groupes = cortege_.get_groupes();
            iterator it = groupes.begin();
            ListPersonne tmp = it->get_LPersonne();
            nbManifestant = 0;
            while(it != groupes.end() && nbManifestant <= largeur_){
                grille_[longueur_-1][nbManifestant] = &(tmp.premier->info);
                tmp.premier->info.setPosition(longueur_-1, nbManifestant);
                nbManifestant ++;
                tmp.premier = tmp.premier->suivant;
                if(tmp.premier == nullptr){
                    ++it;
                    tmp = (*it).get_LPersonne();
                }
            }
            nbEtape++;
            nbManifestant -- ;
            tmp.premier = tmp.dernier->precedent;
        }else{
            std::cout << "\nEtape "<< nbEtape  << " :" <<std::endl;
            nbEtape++;
            
            //trouver la positiion ou ce trouve la personne suivante à ajouter dans la grille 
            std::vector<Groupe> groupes = cortege_.get_groupes();
            iterator it = groupes.begin();
            ListPersonne tmp = it->get_LPersonne();
            int cpt =0;
            while(it != groupes.end() && cpt < nbManifestant){
                cpt ++;
                tmp.premier = tmp.premier->suivant;
                if(tmp.premier == nullptr){
                    ++it;
                    tmp = (*it).get_LPersonne();
                }
            }
            if(grille_[0][0] != nullptr){//verifier que etape == largeur-1 pour sortir les personnes
                // sortir les personnes de la derniere ligne de la manif
                int nbligne = nbManifestant/largeur_; 
                nbManifestant = nbManifestant - largeur_;
                for(int i = 0; i<nbligne; i++){
                    int j=0;
                    while(grille_[i][j] != nullptr){
                        grille_[i][j]->setPosition(0,0);
                        grille_[i][j] = grille_[i+1][j];
                        grille_[i+1][j] = nullptr;
                        j++;
                    }
                }
                if(nbManifestant <=largeur_)
                    nbManifestant = 0;
            }else{
                // avancer les personnes de la grille
                for(int i = 0; i<longueur_-1; i++){
                    for(int j=0; j<largeur_; j++){
                        grille_[i][j] = grille_[i+1][j];
                        grille_[i+1][j] = nullptr;
                    }
                }
                
            }
            //ajouter les personnes si y'en a encore
            cpt =0;
            while(it != groupes.end() && cpt < largeur_){
                grille_[longueur_-1][cpt] = &(tmp.premier->info);
                tmp.premier->info.setPosition(longueur_-1, nbManifestant);
                cpt ++;
                nbManifestant++;
                tmp.premier = tmp.premier->suivant;
                if(tmp.premier == nullptr){
                    ++it;
                    tmp = (*it).get_LPersonne();
                }
            }
        }
    }
}



/// @brief tester si c'est la fin de la manif; quand la grille est vide donc plus personne dans le cortege
/// @return true si tous les groupes du cortege on défilé, false sinon
bool Manif :: testFin(){
    //return cortege_.get_groupes().size() == 0;
    return nbManifestant == 0 ;
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

/// @brief 
void  Manif :: leaders(){
    int i =0;
    if(cortege_.get_groupes().size() == 0){//pas de manifestant 
        std::cout << "Erreur : cortege vide" << std::endl;
    }else{
        std::vector<Groupe> groupes = cortege_.get_groupes();
        std::cout << "Leaders :: " ;
        for (auto it = groupes.begin(); it != groupes.end(); ++it) {
            std::cout << (*it).getleader().getName() << ", ";
        }
        std::cout << std::endl;
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
    std::cout << std::endl;
    for(int i=0; i<longueur_; i++){
        std::cout << " " ;
        for(int j=0; j<largeur_; j++){
            if(grille_[i][j]== nullptr)
                std::cout << "- ";
            else{
                Groupe* groupe = get_Groupe(grille_[i][j]->getId());
                std::cout << grille_[i][j]->getName()[0] << " " ;

                //groupe->getCouleur().afficher(std::cout, grille_[i][j]->get_initial());
            }
        }
        std::cout << std::endl;;
    }
    
}