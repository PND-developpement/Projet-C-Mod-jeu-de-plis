#include "IA.h"

using namespace std;

//Constrcuteurs et destructeurs 
IA::IA(){}

IA::IA(std::string pseudoIA) 
{ 
	this->pseudo = move(pseudoIA); 
}

IA::IA(IA& parametre) : Joueur(parametre) {}
IA::IA(IA&& parametre) : Joueur(move(parametre)) {}

//Méthodes
std::shared_ptr<Carte> IA::JouerUneCarte()
{
	size_t nbCarteMainJoueur = cartes.lireCartesMain().GetTaille(); //On récupère la taille de l'ensemble de carte

	int positionCarte = rand() % nbCarteMainJoueur + 1; //On choisit une position de carte aléatoirement

	std::shared_ptr<Carte> carte = cartes.ObtenirCarte(positionCarte); //on obtient la carte en fonction de la position choisie

	//On vérifie que la carte ne soit pas null
	if (carte == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul");

	cartes.SupprimerCarteMain(carte); //On la supprime du deck

	return carte; //on la renvoie
}