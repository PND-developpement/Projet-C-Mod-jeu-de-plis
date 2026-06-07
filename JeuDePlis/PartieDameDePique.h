#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"

class PartieDameDePique : public Partie{
public:
	// Constructeur et Destructeur

	/*
	* Constructeur qui initaliser le nombre de joueur a 4
	*/
    PartieDameDePique();

	/*
	* Destructeur par défaut
	*/
    ~PartieDameDePique() = default;

	// Methodes

	/*
	* Afficher dans la console les règles du jeu
	*/
	void AfficherRegles() const = 0;

	/*
	* Crée le paquet de cartes et les joueurs
	*/
	void InitaliserPartie() = 0;

	/*
	* Mélange le paquet de cartes et distribue aux joueurs leurs cartes
	*/
	void DistribuerCartes() = 0;

	/*
	* Lance la partie
	*/
	void LancerPartie() = 0;
};

#endif
