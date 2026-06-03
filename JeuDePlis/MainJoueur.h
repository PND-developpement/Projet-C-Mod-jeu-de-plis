#ifndef H_MJO_H
#define H_MJO_H

#include "EnsembleDeCartes.h"
#include "Carte.h"
#include <memory>

class MainJoueur
{
private:
	EnsembleDeCartes CartesMain;

public:
	//constructeurs et destructeurs
	MainJoueur();
	MainJoueur(const EnsembleDeCartes& CopieCartesMain);
	MainJoueur(EnsembleDeCartes&& CopieCartesMain);
	~MainJoueur();

	//accesseurs
	EnsembleDeCartes lireCartesMain() const;
	void modifierCartesMain(EnsembleDeCartes nouvellesCartesMain);

	void AjouterCarteMain(std::shared_ptr<Carte> nouvelleCarte);
	void SupprimerCarteMain(std::shared_ptr<Carte> carte);
	bool TrouverCarte(std::shared_ptr<Carte> carte);
	void afficherMainJoueur() const;

};



#endif // !H_MJO_H
