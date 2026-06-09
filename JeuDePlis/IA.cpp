#include "IA.h"
#include <memory>
#include "Carte.h"
#include <cstdlib>
#include <stdexcept>
#include <utility>
#include <string>

using namespace std;

//Constrcuteurs et destructeurs 
IA::IA(){}

IA::IA(std::string pseudoIA) 
{ 
	this->pseudo = pseudoIA; 
}

IA::IA(IA& parametre) : Joueur(parametre) {}
IA::IA(IA&& parametre) : Joueur(move(parametre)) {}

//Méthodes
std::shared_ptr<CarteInterface> IA::JouerUneCarte(const Interface& interface)
{
	size_t nbCarteMainJoueur = cartes->lireCartesMain()->GetTaille(); //On récupère la taille de l'ensemble de carte

	int positionCarte = rand() % nbCarteMainJoueur + 1; //On choisit une position de carte aléatoirement

	std::shared_ptr<CarteInterface> carteJouee = cartes->ObtenirCarte(positionCarte); //on obtient la carte en fonction de la position choisie

	//On vérifie que la carte ne soit pas null
	if (carteJouee == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul : JouerUneCarte IA");

	cartes->SupprimerCarteMain(carteJouee); //On la supprime du deck

	return carteJouee; //on la renvoie
}
