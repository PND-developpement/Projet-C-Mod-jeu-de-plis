#ifndef H_PAR_H
#define H_PAR_H
#include "Joueur.h"
#include <vector>
#include <memory>

class Partie{
protected:
	// Atribut 
	int nombreJoueur;
	std::vector <std::unique_ptr <Joueur>> listeJoueur;
public:
	// Constructeur et Destructeur

	Partie() = default;
	~Partie() = default;

	// Methodes

	virtual void AfficherRegles() = 0;
	virtual void InitaliserPartie() = 0;
	virtual void DistribuerCartes() = 0;
	virtual void LancerPartie() = 0;


};
#endif