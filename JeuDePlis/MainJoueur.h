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
	//- - - constructeurs et destructeurs - - -

	/*
	* constructeur par défaut
	*/
	MainJoueur();

	/*
	* constructeur par référence
	* @param copieCartesMain : MainJoueur, référence constante
	*/
	MainJoueur(const MainJoueur& CopieCartesMain);

	/*
	* Constructeur de recopie avec move
	* @param CopieCartesMain : MainJoueur
	*/
	MainJoueur(MainJoueur&& CopieCartesMain);

	/*
	* destructeur
	*/
	~MainJoueur();

	//- - - accesseurs - - -
	/*
	* permet de définir la taille de la main ainsi que de l'ensemble de carte
	* @param taille : size_t
	*/
	void DefinirTaille(size_t taille) { this->taille = taille; CartesMain->DefinirTaille(taille); }

	/*
	* permet d'obtenir la taille de la main
	* @return int
	*/
	size_t ObtenirTaille() const { return taille; }

	/*
	* permet d'avoir l'ensemble de carte qui est dans la main
	* @return EnsembleDeCartes
	*/
	EnsembleDeCartes* LireCartesMain() const;

	/*
	* permet de modifier l'ensemble de cartes de la main avec un nouvel ensemble 
	* @param nouvellesCartesMain : EnsembleDeCartes
	*/
	void ModifierCartesMain(EnsembleDeCartes nouvellesCartesMain);

	/*
	* permet d'ajouter une nouvelle carte dans la main en vérifiant bien évidemment que la carte placée en paramètre ne soit pas déjà dans l'ensemble de carte
	* @param nouvelleCarte : std::shared_ptr<CarteInterface>
	*/
	void AjouterCarteMain(std::shared_ptr<CarteInterface> nouvelleCarte);

	/*
	* permet de supprimer une carte de la main en vérifiant bien évidemment que la carte placée en paramètre soit bien dans l'ensemble de carte
	* @param carte : std::shared_ptr<CarteInterface>
	*/
	void SupprimerCarteMain(std::shared_ptr<CarteInterface> carte);

	/*
	* permet de chercher une carte dans la main
	* @param valeur : std::string
	* @param figure : std::string
	* àreturn bool : true or false
	*/
	bool TrouverCarte(std::string valeur, std::string figure);

	/*
	* permet d'obtenir une carte dans la main à une position donnée
	* @param positionCarte : int
	* @return std::shared_ptr<CarteInterface>
	*/
	std::shared_ptr<CarteInterface> ObtenirCarte(int positionCarte);

	/*
	* Afficher la main
	*/
	void AfficherMainJoueur() const;
	

};



#endif 
