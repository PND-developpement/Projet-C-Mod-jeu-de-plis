#ifndef _IA_H__
#define _IA_H__

#include "Joueur.h"

class IA : public Joueur
{
public :
	//Constrcuteurs et destructeurs 
	IA();
	IA(std::string pseudoIA);
	IA(IA& parametre);
	IA(IA&& parametre);
	~IA() = default;

	//Méthodes
	virtual std::shared_ptr<Carte> JouerUneCarte() override;
};

#endif