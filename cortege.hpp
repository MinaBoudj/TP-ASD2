#ifndef CORTEGE_HPP
#define CORTEGE_HPP

#include "groupe.hpp"
#include <vector>


class Cortege {

    private : 
        std::vector<Groupe> groupes_; //vecteur de groupes
        std::string nom_cortege_; //nom du cortege

    public :
        Cortege(std::string nom);   //création d'un cortege vide
        ~Cortege();  //distruction du cortege
        std::vector<Groupe> get_groupes(); //retourne les groupes
        void insert_Groupe(Groupe groupe); //insertion d'un groupe dans le cortege
        void delete_Groupe(std::string nom_groupe); //suppression du groupe à partir de son nom
        Personne* getPersonne(int id); //accés à une personne à partir dans son id
        void delete_personne(int id); //suppresion d'une personne à  partir de son id
        void tri_couleur(); //trier par couleur les groupes 
        void tri_taille(); //trier par taille les groupes

        void afficher_cortege();//afficher les personne du cortege
        
        typedef std::vector<Groupe>::iterator iterator;

};

#endif
