#ifndef _CARTE_DECORATOR_H__
#define _CARTE_DECORATOR_H__

#include "CarteInterface.h"
#include <memory>

class CarteDecorator : public CarteInterface
{
protected :
	std::shared_ptr<CarteInterface> carteInter;
public :
	CarteDecorator(std::shared_ptr<CarteInterface> carte) : carteInter(std::move(carte)) {}

	/*
	* Renvoie la valeur
	* @return valeur std::string
	*/
	std::string ObtenirValeur() const override { return carteInter->ObtenirValeur(); }

	/*
	* Renvoie la figure
	* @return figure std::string
	*/
	std::string ObtenirFigure() const override { return carteInter->ObtenirFigure(); }

	/*
	* Renvoie la couleur
	* @return couleur std::string
	*/
	std::string ObtenirCouleur() const override { return carteInter->ObtenirCouleur(); }

	/*
	* Affiche la carte
	*/
	void AfficherCarte() const override { return carteInter->AfficherCarte(); }
};

#endif