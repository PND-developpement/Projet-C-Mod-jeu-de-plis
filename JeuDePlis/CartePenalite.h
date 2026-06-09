#ifndef _CARTE_PENALITE_H__
#define _CARTE_PENALITE_H__

#include "CarteDecorator.h"

class CartePenalite : public CarteDecorator
{
private:
	int valeurPenalite;
public:
	//- - - Constructeur - - -
	CartePenalite(std::shared_ptr<CarteInterface> carteInter, int valeurPenalite) : CarteDecorator(std::move(carteInter)), valeurPenalite(valeurPenalite) {}

	//- - - Accesseur - - -
	/*
	* Renvoie la valeur de la Penalite
	* @return valeurPenalite int
	*/
	std::optional<int> GetPenalite() const override { return valeurPenalite; }
};

#endif