#ifndef GROUPE_HPP
#define GROUPE_HPP

#include "personne.hpp"
#include "couleur.hpp"
#include<list>
#include<unordered_map>

//SDA :List(Personne) est le type des Listes de type Personne 
struct maillon{
    Personne info;
    maillon* suivant;
    maillon* precedent;
};

struct ListPersonne{
    maillon* premier;
    maillon* dernier;
    int nb;
};

class Groupe {  
    
    private : 
        std::string nom_groupe;
        Couleur couleur_;
        int taille;
        ListPersonne LPersonne;
        std::unordered_map<int, maillon*> mapPersonne;   //la clé c'est l'id 

    public :
        Groupe(std::string nom, Couleur couleur, int taille);   //création d'un groupe vide
        ~Groupe();  //distruction du groupe
        int gettaille(); //retourne la taille de la liste
        Couleur getCouleur();
        /** accès à une personne à partir de son identifiant
         * précondition : la personne est dans la liste */
        Personne* getPersonne(int id);  

        /** accès au leader
         * précondition : la liste n'est pas vide */
        Personne getleader();

        //insere une personne avec son nom 
        void insererPersonne(std::string nom);  

        //supprime une personne à partir de son identifiant
        void supprimerPersonne(int id); 

        //supprime la premiere personne(leader)
        void suprimerPremierePersonne();
        
        typedef std::list<Personne>::iterator iterator;
        
};

#endif
