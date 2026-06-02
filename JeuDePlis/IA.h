#ifndef _IA_H__
#define _IA_H__

#include "Joueur.h"

class IA : public Joueur
{
	IA();
	IA(std::string pseudoIA);
	IA(IA& parametre);
	IA(IA&& parametre);
	~IA();

	


};

#endif