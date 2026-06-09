#ifndef H_PDDP_H
#define H_PDDP_H
#include "Plis.h"
#include <unordered_map>
#include <memory>
#include "CarteInterface.h"

class PlisDameDePique : public Plis{
public:

	/*
	* Verfie pour qu'elle joueur le plis et gagnant et renvoie la postion de ceux joueur
	* @param carteDuPlis std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>>
	* @return positionJoueur unsigned int
	*/
	unsigned int verifePlis(std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>> carteDuPlis) override;

};

#endif