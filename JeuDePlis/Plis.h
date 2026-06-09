#ifndef H_PLI_H
#define H_PLI_H
#include <unordered_map>
#include "CarteInterface.h"
#include <memory>
class Plis{
public :
	//Destructeur

	/*
	* Destructeur par defaut
	*/
	~Plis() = default;
	
	//Méthodes

	/*
	* Verfie pour qu'elle joueur le plis et gagnant et renvoie la postion de ceux joueur
	* @param carteDuPlis std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>>
	* @return positionJoueur unsigned int
	*/
	virtual unsigned int verifePlis(std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>> carteDuPlis) = 0;

};
#endif 