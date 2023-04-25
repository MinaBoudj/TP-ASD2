#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <time.h>
#include "manif.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// choix aléatoire d'un élément dans l'ensemble passé en paramètre
std::string choisir_prenom(const set<std::string>& s)
{
   int n = s.size(),
       k = rand() % n;

   auto it = s.begin();
   std::advance(it, k);
   return *it;
}

////////////////////////////////////////////////////////////////////////////////
// lecture du fichier des prénoms
void lecture_fichier_prenoms(set<std::string>& ens)
{
   ifstream fin;
   fin.open("nat2021.csv", ios::in);
   string line, mot;

   while (fin >> line)
   {
      istringstream is(line);
      getline(is, mot, ';');
      getline(is, mot, ';');
      ens.insert(mot);
   }
   fin.close();
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
   
   // initialisation du générateur de nombres aléatoires
   srand(time(0));

   // lecture du fichier des prénoms
   set<std::string> ens_prenom;
   lecture_fichier_prenoms(ens_prenom);

   // lecture du fichier des corteges
   ifstream fcor;
   fcor.open("declaration.csv", ios::in);
   std::string line, nom, couleur, str, sujet;
   int taille;
    
    
   getline(fcor, sujet);

   // TODO : création d'un cortège
   vector<Groupe> groupe_;
   Cortege cortege = Cortege("N°1");

  
   while (fcor >> line)
   {
      istringstream is(line);
      getline(is, nom, ';');
      getline(is, couleur, ';');
      getline(is, str, ';');
      taille = stoi(str);

      cout << nom << ';' << couleur << ';' << taille << endl;

      // TODO : création des groupes
      //Personne p1 = Personne(choisir_prenom(ens_prenom));
     
      // appeler choisir_prenom(ens_prenom) pour choisir un prénom
   }
   fcor.close();
   
   Groupe groupe1 = Groupe("Losers", Couleur :: NOIR, 3);
   groupe1.insererPersonne(choisir_prenom(ens_prenom));
   groupe1.insererPersonne(choisir_prenom(ens_prenom));
   groupe1.insererPersonne(choisir_prenom(ens_prenom));

   Groupe groupe2 = Groupe("Winners", Couleur::BLANC, 4);
   groupe2.insererPersonne(choisir_prenom(ens_prenom));
   groupe2.insererPersonne(choisir_prenom(ens_prenom));
   groupe2.insererPersonne(choisir_prenom(ens_prenom));
   groupe2.insererPersonne(choisir_prenom(ens_prenom));


   cortege.insert_Groupe(groupe1);
   cortege.insert_Groupe(groupe2);
   cortege.afficher_cortege();

   // TODO
   Manif manif = Manif(7, 5, cortege);
   manif.leaders();
   manif.simulationEtape();
   manif.afficher_grille();
   return 0;
}
