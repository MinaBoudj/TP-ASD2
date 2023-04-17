#include "manif.hpp"
#include<iostream>

using namespace std;

/// @brief constructeur d'une manif vide
/// @param longueur
/// @param largeur
Manif :: Manif(int longeur, int largeur, Cortege cortege) : longueur_(longeur), largeur_(largeur), grille_(), cortege_(cortege){}


/// @brief distructeur
Manif::~Manif(){
    cout << "fin" << endl;
}

/// @brief simulation d'une étape(verifier qu'il y'a au moins une Personne dans la grille)
void Manif :: simulationEtape(){
    
}