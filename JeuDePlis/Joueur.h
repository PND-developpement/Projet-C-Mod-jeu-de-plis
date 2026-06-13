#ifndef _JOUEUR_H__
#define _JOUEUR_H__

#include <string>
#include <memory>
#include "MainJoueur.h"
#include "CarteInterface.h"
#include "interface.h"


class Joueur
{
protected :
	std::string pseudo; //pseudo du joueur
	int score; //score du joueur 
	int scoreManche; //score du joueur par manche
	std::unique_ptr<MainJoueur> cartes; //la main du joueur

public :
	// - - - constructeurs et destructeur - - - 
	/*
	* constructeur par défaut qui initialise le joueur
	*/
	Joueur();

	/*
	* constructeur de recopie par référence
	* @param rJoueur : Joueur, référence
	*/
	Joueur(const Joueur& rJoueur) noexcept;

	/*
	* Constructeur de recopie avec move
	* @param rJoueur : Joueur
	*/
	Joueur(Joueur&& rJoueur) noexcept;

	/*
	* constructeur de recopie
	* @param pseudo : std::string
	* @param score : int 
	* @param cartes : std::unique_ptr<MainJoueur>
	*/
	Joueur(std::string pseudo, int score, std::unique_ptr<MainJoueur> cartes);

	/*
	* destructeur virtual 
	*/
	virtual ~Joueur();

	// - - - Accesseurs - - - 
	// - accesseurs pseudo - 
	/*
	* permet de lire le pseudo du joueur
	* @return std::string 
	*/
	std::string LirePseudo() const;

	/*
	* permet de modifier le pseudo du joueur
	* @param NouveauPseudo : std::string
	*/
	void ModifierPseudo(std::string NouveauPseudo);

	// - accesseurs score -
	/*
	* permet de lire le score du joueur
	* @return int
	*/
	int LireScore() const;

	/*
	* permet de modifier le score du joueur
	* @param NouveauScore : int
	*/
	void ModifierScore(int NouveauScore);

	/*
	* permet de modifier le score de la manche du joueur
	* @param NouveauScore : int
	*/
	void ModifierScoreManche(int score) { scoreManche = score; }

	/*
	* permet de lire le score de la manche du joueur
	* @return int
	*/
	int LireScoreManche() const { return scoreManche; }

	// - accesseurs cartes - 
	/*
	* permet de modifier le score du joueur
	* @return MainJoueur, pointeur
	*/
	MainJoueur* LireCartes() const;

	/*
	* permet de modifier le score du joueur
	* @param nouvellesCartes : std::unique_ptr<MainJoueur>
	*/
	void ModifierCartes(std::unique_ptr<MainJoueur> nouvellesCartes);

	// - - -Méthodes - - -
	/*
	* permet de jouer une carte qui est dans la main du joueur.
	* virtual pure car une IA ne jouera pas de la même façon qu'un humain
	* le variable parametre permet d'afficher une interface diffrerente si le joueur joue une carte ou la donne
	* @param interface : Interface, référence const
	* @param parametre : std::string
	* @return std::shared_ptr<CarteInterface>
	*/
	virtual std::shared_ptr<CarteInterface> JouerUneCarte(const Interface& interface,std::string parametre) = 0;

	/*
	* permet d'afficher la main du joueur en faisant appelle à la méthode de la classe MainJoueur
	*/
	void AfficherMainDuJoueur() const;

	
};

#endif