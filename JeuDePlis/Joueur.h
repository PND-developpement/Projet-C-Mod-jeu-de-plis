#ifndef _JOUEUR_H__
#define _JOUEUR_H__

#include <string>
#include "MainJoueur.h"
#include "Carte.h"
#include <memory>
#include "CarteInterface.h"

class Joueur
{
protected :
	std::string pseudo;
	int score;
	std::unique_ptr<MainJoueur> cartes;

public :
	//constructeurs et destructeurs
	
	Joueur();
	Joueur(const Joueur& rJoueur) noexcept;
	Joueur(Joueur&& rJoueur) noexcept;
	Joueur(std::string pseudo, int score, std::unique_ptr<MainJoueur> cartes);
	virtual ~Joueur();

	//accesseurs
	std::string LirePseudo() const;
	void ModifierPseudo(std::string NouveauPseudo);

	int LireScore() const;
	void ModifierScore(int NouveauScore);

	MainJoueur* LireCartes() const;
	void ModifierCartes(std::unique_ptr<MainJoueur> nouvellesCartes);

	//Méthodes
	virtual std::shared_ptr<CarteInterface> JouerUneCarte() = 0; //virtual pure car une IA ne jouera pas de la même façon qu'un humain ? 

	void AfficherMainDuJoueur() const;
};

#endif