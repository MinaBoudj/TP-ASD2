#ifndef GROUPE_HPP
#define GROUPE_HPP

#include "personne.hpp"
#include<list>

//SDA :List(Personne) est le type des Listes de type Personne 

class Groupe {  
    private : 
        std::string nom_groupe;
        std::string couleur;
        int taille;
        std::list<Personne> LPersonne;

    public :
        Groupe(std::string nom, std::string couleur, int taille);   //création d'un groupe vide
        ~Groupe();  //distruction du groupe
        int gettaille(); //retourne la taille de la liste

        /** accès à une personne à partir de son identifiant
         * précondition : la personne est dans la liste */
        Personne getPersonne(int id);  

        /** accès au leader
         * précondition : la liste n'est pas vide */
        Personne getleader();

        void insererPersonne(std::string nom);   //insere une personne avec son nom 
        void supprimerPersonne(int id); //supprime une personne à partir de son identifiant
        void suprimerPremierePersonne(); //supprime la premiere personne(leader)
        typedef std::list<Personne>::iterator iterator;
};

#endif
