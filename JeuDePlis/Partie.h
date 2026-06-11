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
	unsigned int scoreTotal;
public:
	// Constructeur et Destructeur
	/*
	* Destructeur par défaut
	*/
	~Partie() = default;

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
	* permet de donner des cartes à un joueur
	* @param interface : Interface, référence const
	*/
	virtual void DonnerCarte(const Interface& interface) = 0;

	/*
	* Lance la partie
	*/
	virtual void LancerPartie() = 0;

	/*
	* Jouer la partie
	* @param interface : Interface, référence const
	*/
	virtual void JouerPartie(const Interface& interface) = 0;

	/*
	* Verifier score des joueurs
	*/
	virtual bool VerifScore() = 0;

	/*
	* Affiche le vainceur de la partie
	*/
	virtual void AfficherScore() = 0;

	/*
	* Ajoute le score par celle mis en parametre
	* @param scoreTotal unsigned int
	*/
	void DefinirScoreTotal(unsigned int scoreTotal) { this->scoreTotal = scoreTotal; }

	/*
	* Ajoute le score par celle mis en parametre
	* @return scoreTotal
	*/
	unsigned int ObtenirScoreTotal() const { return scoreTotal; }

};
#endif