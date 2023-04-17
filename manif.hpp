#ifndef MANIF_HPP
#define MANIF_HPP

#include "cortege.hpp"

class Manif {
    private :
        int largeur_;
        int longueur_;
        int nbManifestant = 0;
        std::vector<std::vector<char>> grille_; //pair<Personne,Couleur>>
        Cortege cortege_;    //le cortege de la manif

    public :
        Manif(int longeur, int largeur, Cortege cortege); //création de la manif
        ~Manif();  //distruction de la manif
        void simulationEtape(); //simulation d'une étape(verifier qu'il y'a au moins une Personne dans la grille)
        bool testFin(); //quand la grille est vide
        Personne* getPersonne(); //accès à une personne à partir de son identifiant
        void supprimerPersonne(int id); //suppression d’une personne à partir de son identifiant
        Personne* leaders(); //accès à l’ensemble des leaders en train de défiler

};

#endif
