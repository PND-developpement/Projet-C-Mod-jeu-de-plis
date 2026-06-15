#ifndef _IA_H__
#define _IA_H__

#include "Joueur.h"
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
	/*
	* Cette méthode permet de jouer une carte aléatoirement pour un IA 
	* Nous suprimons cette carte de la main du joueur une fois qu'elle est jouée
	* @param interface : référence Interface, const
	* @param parametre : std::string
	* @return std::shared_ptr<CarteInterface>
	*/
	std::shared_ptr<CarteInterface> JouerUneCarte(const Interface& interface, std::string parametre) override;
};

#endif