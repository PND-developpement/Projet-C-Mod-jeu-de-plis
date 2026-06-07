#ifndef _IA_H__
#define _IA_H__

#include "Joueur.h"
#include "CarteInterface.h"
#include <memory>

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
	std::shared_ptr<CarteInterface> JouerUneCarte() override;
};

#endif