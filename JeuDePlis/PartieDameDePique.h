#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "Joueur.h"
#include <memory>

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
	void AfficherRegles() const override;

	/*
	* Crée le paquet de cartes et les joueurs
	*/
	void InitaliserPartie() override;

	/*
	* Mélange le paquet de cartes et distribue aux joueurs leurs cartes
	*/
	void DistribuerCartes() override;

	/*
	* Lance la partie
	*/
	void LancerPartie() override;

	/*
	* Jouer la partie
	*/
	void JouerPartie() override;

	/*
	* Verifier score des joueurs
	*/
	bool VerifScore() override;

	/*
	* Affiche le vainceur de la partie
	*/
	void AfficherScore() override;

};

#endif
