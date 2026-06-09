#ifndef _CARTE_PENALITE_H__
#define _CARTE_PENALITE_H__

#include "CarteDecorator.h"

class CartePenalite : public CarteDecorator
{
private:
	int valeurPenalite;
public:
	CartePenalite(std::shared_ptr<CarteInterface> carteInter, int valeurPenalite) : CarteDecorator(std::move(carteInter)), valeurPenalite(valeurPenalite) {}
	//Accesseurs
	/*
	* Renvoie la valeur de la Penalite
	* @return valeurPenalite int
	*/
	int GetValeurPenalite() const { return valeurPenalite; }

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

	//Méthodes
	/*
	* Renvoie le score de la parte - la penalite
	* @return int
	*/
	int ObtenirScoreCarte() override { return carteInter->ObtenirScoreCarte() - valeurPenalite; }

	/*
	Affiche la carte
	*/
	void AfficherCarte() const override { return carteInter->AfficherCarte(); }
};

#endif