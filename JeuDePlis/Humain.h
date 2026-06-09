#ifndef _HUMAIN_H__
#define _HUMAIN_H__

#include "Joueur.h"

class Humain : public Joueur
{
public:
	//- - - Constrcuteurs et destructeur - - -
	Humain();
	Humain(std::string pseudoJoueur);
	Humain(Humain& parametre);
	Humain(Humain&& parametre) noexcept;
	~Humain() = default;

	// - - - Méthode - - -
	/*
	* Cette méthode permet de jouer une carte en utilisant l'interface pour demander à l'utilisateur la carte qu'il souhaite jouer
	* Nous suprimons cette carte de la main du joueur une fois qu'elle est jouée
	* @param interface : référence Interface, const
	* @return std::shared_ptr<CarteInterface>
	*/
	std::shared_ptr<CarteInterface> JouerUneCarte(const Interface& interface) override;
};

#endif