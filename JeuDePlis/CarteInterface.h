#ifndef _CARTE_INTERFACE_H__
#define _CARTE_INTERFACE_H__

#include <string>
#include <optional>

class CarteInterface
{
public :
	//Destructeur
	virtual ~CarteInterface() = default;

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
	* renvoie la valeur de l'atout
	* @return int
	*/
	virtual std::optional<int> GetAtout() const { return std::nullopt; }

	/*
	* renvoie la valeur de la penalité
	* @return int
	*/
	virtual std::optional<int> GetPenalite() const { return std::nullopt; }

	/*
	* Affiche la carte
	*/
	virtual void AfficherCarte() const = 0;
};

#endif
