#ifndef MANIF_HPP
#define MANIF_HPP

#include "cortege.hpp"

class Manif {
    private :
        int largeur_; 
        int longueur_; 
        int nbManifestant = -1; //nombre de personne dans la grille
        int nbEtape = 0;
        std::vector<std::vector<Personne*>> grille_; 
        Cortege cortege_;    //le cortege de la manif

    public :
        Manif(int longeur, int largeur, Cortege cortege); //création de la manif
        ~Manif();  //distruction de la manif
        Cortege get_Cortege();
        void simulationEtape(); //simulation d'une étape(verifier qu'il y'a au moins une Personne dans la grille)
        bool testFin(); //quand la grille est vide
        Personne* getPersonne(int id); //accès à une personne à partir de son identifiant
        Groupe* get_Groupe(int id); //accés au groupe de la personne
        void supprimerPersonne(int id); //suppression d’une personne à partir de son identifiant
        void leaders(); //accès à l’ensemble des leaders en train de défiler
        void afficher_grille();//afficher la grille de la maniff
        typedef std::vector<Groupe>::iterator iterator;

};

#endif
