#ifndef _CARTE_ATOUT_H__
#define _CARTE_ATOUT_H__

#include "CarteDecorator.h"

class CarteAtout : public CarteDecorator
{
private :
	int valeurAtout;
public :
	CarteAtout(std::shared_ptr<CarteInterface> carteInter, int valeurAtout) : CarteDecorator(std::move(carteInter)), valeurAtout(valeurAtout) {}
	//Accesseurs
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
	* Renvoie la valeur de l'atout
	* @return valeurAtout int
	*/
	int ObtenirValeurAtout() const { return valeurAtout; }

	//Méthodes
	/*
	* Renvoie le score de la carte mutiplié par la valeur de l atout
	* @return int
	*/
	int ObtenirScoreCarte() override { return carteInter->ObtenirScoreCarte() * valeurAtout; }

	/*
	* Affiche la carte
	*/
	void AfficherCarte() const override { return carteInter->AfficherCarte(); }
};

#endif