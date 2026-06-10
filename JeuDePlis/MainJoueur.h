#ifndef H_MJO_H
#define H_MJO_H

#include "EnsembleDeCartes.h"
#include "CarteInterface.h"
#include <memory>
#include <string>

class MainJoueur
{
private:
	std::unique_ptr<EnsembleDeCartes> CartesMain; //L'ensemble de cartes qui composent la main du joueur 
	size_t taille;
public:
	//constructeurs et destructeurs
	MainJoueur();
	MainJoueur(const MainJoueur& CopieCartesMain);
	MainJoueur(MainJoueur&& CopieCartesMain);
	~MainJoueur();

	void DefinirTaille(size_t taille) { this->taille = taille; CartesMain->DefinirTaille(taille); }
	size_t ObtenirTaille() const { return taille; }

	//accesseurs
	EnsembleDeCartes* LireCartesMain() const;
	void ModifierCartesMain(EnsembleDeCartes nouvellesCartesMain);

	void AjouterCarteMain(std::shared_ptr<CarteInterface> nouvelleCarte);
	void SupprimerCarteMain(std::shared_ptr<CarteInterface> carte);
	bool TrouverCarte(std::string valeur, std::string figure);
	std::shared_ptr<CarteInterface> ObtenirCarte(int positionCarte);
	void AfficherMainJoueur() const;
	

};



#endif 
