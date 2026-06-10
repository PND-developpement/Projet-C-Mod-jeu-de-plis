#ifndef H_PDDP_H
#define H_PDDP_H
#include "Plis.h"
#include <unordered_map>
#include <memory>
#include "CarteInterface.h"
#include <vector>

class PlisDameDePique : public Plis{
public:

	/*
	* Verif pour qu'elle joueur le plis et gagnant et renvoie la postion de ceux joueur
	* @param carteDuPlis std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>>
	* @return resultatPlis premiere valeur joueur gagnant et deuxieme score du joueur
	*/
	std::vector<int> verifPlis(std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>> carteDuPlis, unsigned int positionPremierJoueur) override;

};

#endif