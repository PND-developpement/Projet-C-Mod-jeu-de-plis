#ifndef H_MJO_H
#define H_MJO_H

#include "EnsembleDeCartes.h"
#include "Carte.h"
#include <memory>

class MainJoueur
{
private:
	EnsembleDeCartes CartesMain; //L'ensemble de cartes qui composent la main du joueur 

public:
	//constructeurs et destructeurs
	MainJoueur();
	MainJoueur(const EnsembleDeCartes& CopieCartesMain);
	MainJoueur(EnsembleDeCartes&& CopieCartesMain);
	~MainJoueur();

	//accesseurs
	EnsembleDeCartes lireCartesMain() const;
	void ModifierCartesMain(EnsembleDeCartes nouvellesCartesMain);

	void AjouterCarteMain(std::shared_ptr<Carte> nouvelleCarte);
	void SupprimerCarteMain(std::shared_ptr<Carte> carte);
	bool TrouverCarte(std::shared_ptr<Carte> carte);
	std::shared_ptr<Carte> ObtenirCarte(int positionCarte);
	void AfficherMainJoueur() const;

};



#endif 
