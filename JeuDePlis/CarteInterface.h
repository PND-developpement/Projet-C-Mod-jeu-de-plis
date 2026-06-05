#ifndef _CARTE_INTERFACE_H__
#define _CARTE_INTERFACE_H__

#include <string>

class CarteInterface
{
public :
	//Destructeur
	~CarteInterface() = default;;

	//méthodes
	/*
	* Renvoie la valeur
	* @return valeur std::string
	*/
	virtual std::string GetValeur() const = 0;

	/*
	* Renvoie la figure
	* @return figure std::string
	*/

	virtual std::string GetFigure() const = 0;

	/*
	* Renvoie la couleur
	* @return couleur std::string
	*/
	virtual std::string GetCouleur() const = 0;

	/*
	* renvoie le score de la carte
	*/
	virtual int GetScoreCarte() = 0;

	/*
	* Affiche la carte
	*/
	virtual void AfficherCarte() const = 0;
};

#endif
