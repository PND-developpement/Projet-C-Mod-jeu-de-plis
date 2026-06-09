#include "Humain.h"

using namespace std;

//Constrcuteurs et destructeurs 
Humain::Humain() : Joueur(){}

Humain::Humain(std::string pseudoJoueur)
{
	this->pseudo = move(pseudoJoueur);
}

Humain::Humain(Humain& parametre) : Joueur(parametre) {}

Humain::Humain(Humain&& parametre) noexcept : Joueur(move(parametre)) {}


//méthodes rédéfinies
std::shared_ptr<CarteInterface> Humain::JouerUneCarte(const Interface& interface)
{
	int positionCarte = interface.DemanderCarte(*cartes);

	//obtenir la carte : 
	std::shared_ptr<CarteInterface> carteJouee = cartes->ObtenirCarte(positionCarte); //on obtient la carte en fonction de la position choisie

	//On vérifie que la carte ne soit pas null
	if (carteJouee == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul");

	cartes->SupprimerCarteMain(carteJouee); //On la supprime du deck

	return carteJouee; //on la renvoie
}
