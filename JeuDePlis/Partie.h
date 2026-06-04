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

	Partie() = default;
	~Partie() = default;

	// Methodes

	virtual void AfficherRegles() const = 0 ;
	virtual void InitaliserPartie() = 0;
	virtual void DistribuerCartes() = 0;
	virtual void LancerPartie() = 0;


};
#endif