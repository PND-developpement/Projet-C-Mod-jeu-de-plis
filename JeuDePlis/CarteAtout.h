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
	std::string GetValeur() const override { return carteInter->GetValeur(); }

	/*
	* Renvoie la figure
	* @return figure std::string
	*/
	std::string GetFigure() const override { return carteInter->GetFigure(); }

	/*
	* Renvoie la couleur
	* @return couleur std::string
	*/
	std::string GetCouleur() const override { return carteInter->GetCouleur(); }

	/*
	* Renvoie la valeur de l'atout
	* @return valeurAtout int
	*/
	int GetValeurAtout() const { return valeurAtout; }

	//Méthodes
	/*
	* Renvoie le score de la carte mutiplié par la valeur de l atout
	* @return int
	*/
	int GetScoreCarte() override { return carteInter->GetScoreCarte() * valeurAtout; }

	/*
	* Affiche la carte
	*/
	void AfficherCarte() const override { return carteInter->AfficherCarte(); }
};

#endif