#ifndef _CARTE_ATOUT_H__
#define _CARTE_ATOUT_H__

#include "CarteDecorator.h"

class CarteAtout : public CarteDecorator
{
private :
	int valeurAtout;
public :
	// - - - Constructeur - - -
	CarteAtout(std::shared_ptr<CarteInterface> carteInter, int valeurAtout) : CarteDecorator(std::move(carteInter)), valeurAtout(valeurAtout) {}
	
	//- - - Accesseur - - -
	/*
	* Renvoie la valeur de l'atout
	* @return valeurAtout int
	*/
	std::optional<int> GetAtout() const override { return valeurAtout; }
};

#endif