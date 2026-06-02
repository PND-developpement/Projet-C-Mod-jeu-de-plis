#ifndef _JOUEUR_H__
#define _JOUEUR_H__

#include <string>
#include "MainJoueur.h"

class Joueur
{
protected :
	std::string pseudo;
	int score;
	MainJoueur cartes;

public :
	//constructeurs et destructeurs

	Joueur();
	Joueur(const Joueur& rJoueur);
	Joueur(Joueur&& rJoueur);
	Joueur(std::string pseudo, int score, MainJoueur cartes);
	~Joueur();

	//accesseurs
	std::string LirePseudo() const;
	void ModifierPseudo(std::string NouveauPseudo);

	int LireScore() const;
	void ModifierScore(int NouveauScore);

	MainJoueur LireCartes() const;
	void ModifierCartes(MainJoueur nouvellesCartes);

	//Méthodes

};

#endif