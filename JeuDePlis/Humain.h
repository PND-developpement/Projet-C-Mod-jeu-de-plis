#ifndef _HUMAIN_H__
#define _HUMAIN_H__

#include "Joueur.h"

class Humain : public Joueur
{
public:
	//Constrcuteurs et destructeurs 
	Humain();
	Humain(std::string pseudoJoueur);
	Humain(Humain& parametre);
	Humain(Humain&& parametre) noexcept;
	~Humain() = default;

	//méthodes
	virtual std::shared_ptr<Carte> JouerUneCarte() override;
};

#endif