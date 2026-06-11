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
	interface.AfficherMainDuJoueur(*cartes);

	size_t nbCarteMainJoueur = cartes->LireCartesMain()->ObtenirTaille(); //On récupère la taille de l'ensemble de carte

	//int positionCarte = rand() % cartes->LireCartesMain()->ObtenirEnsembleDeCarte().size(); //On choisit une position de carte aléatoirement
	int positionCarte = rand() % nbCarteMainJoueur;

	std::shared_ptr<CarteInterface> carteJouee = cartes->ObtenirCarte(positionCarte); //on obtient la carte en fonction de la position choisie

	//On vérifie que la carte ne soit pas null
	if (carteJouee == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul : JouerUneCarte IA");

	cartes->SupprimerCarteMain(carteJouee); //On la supprime du deck

	return carteJouee; //on la renvoie
}
