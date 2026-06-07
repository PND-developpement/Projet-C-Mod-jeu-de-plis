#ifndef H_PAR_H
#define H_PAR_H
#include "Joueur.h"
#include <vector>
#include <memory>
#include "JeuDeCarte.h"

class Partie{
protected:
	// Atribut 
	unsigned int nombreJoueur; 
	std::vector <std::unique_ptr <Joueur>> listeJoueur;
	std::unique_ptr<JeuDeCartes> pLeJeu;
public:
	// Constructeur et Destructeur

	/*
	* Destructeur par défaut
	*/
	virtual ~Partie() = default;

	// Methodes

	/*
	* Afficher dans la console les règles du jeu
	*/
	virtual void AfficherRegles() const = 0 ;

	/*
	* Crée le paquet de cartes et les joueurs
	*/
	virtual void InitaliserPartie() = 0;

	/*
	* Mélange le paquet de cartes et distribue aux joueurs leurs cartes
	*/
	virtual void DistribuerCartes() = 0;

	/*
	* Lance la partie
	*/
	virtual void LancerPartie() = 0;

};
#endif