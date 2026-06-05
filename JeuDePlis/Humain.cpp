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
std::shared_ptr<Carte> Humain::JouerUneCarte()
{
	//L'idée ici est de demander une carte et de récupérer sa position 

	//int positionCarte = demanderUneCarte()

	//obtenir la carte : 
	//std::shared_ptr<Carte> carte = cartes.ObtenirCarte(positionCarte); //on obtient la carte en fonction de la position choisie

	//On vérifie que la carte ne soit pas null
	//if (carte == nullptr)
	//	throw std::invalid_argument("Erreur : pointeur est nul");

	//cartes.SupprimerCarteMain(carte); //On la supprime du deck

	//return carte; //on la renvoie


	return nullptr;
} //J'ai mis cette fonction en commentaire en attendant de développer la méthode de demande de carte dans un deck