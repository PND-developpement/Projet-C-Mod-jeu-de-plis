#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "Joueur.h"
#include <memory>

class PartieDameDePique : public Partie{
public:
	// Constructeur et Destructeur

	/*
	* Constructeur qui initaliser le nombre de joueur a 4
	*/
    PartieDameDePique();

	/*
	* Destructeur par défaut
	*/
    ~PartieDameDePique() = default;

	// Methodes

	/*
	* Afficher dans la console les règles du jeu
	*/
	void AfficherRegles() const override;

	/*
	* Crée le paquet de cartes et les joueurs
	*/
	void InitaliserPartie() override;

	/*
	* Mélange le paquet de cartes et distribue aux joueurs leurs cartes
	*/
	void DistribuerCartes() override;

	/*
	* dans cette classe, nous allons utliser cette méthode pour appliquer la règle selon laquelle chaque joueur
	* donne 3 cartes au joueur à sa gauche (ici, se sera le joueur suivant dans la liste des joueurs de la partie)
	* Ainsi, chaque joueur choisit trois cartes, elles sont retitrées de sa main puis ajoutées à la main d'un autre autre joueur de la partie.
	* @param interface : Interface, référence const
	*/
	void DonnerCarte(const Interface& interface) override;

	/*
	* Lance la partie
	*/
	void LancerPartie() override;

	/*
	* Jouer la partie
	* @param interface : Interface, référence constante
	*/
	void JouerPartie(const Interface& interface) override;


	/*
	* Permet de définir les cartes jouable dans la main du joueur en fonction des cartes en cours de jeu.
	* Ensuite le joueur ou l'IA joue une carte valide
	* @param carteTable : vector <shared_ptr<CarteInterface>>
	* @param JoueurEnCours : unsigned int
	* @param interface : Interface, référence const
	*/
	std::shared_ptr<CarteInterface> JouerCarte(std::vector<std::shared_ptr<CarteInterface>>& carteTable, unsigned int JoueurEnCours, const Interface& interface) override;

	/*
	* vérifie que les deux cartes ont la même figure ou non
	* @param carte1 : std::shared_ptr<CarteInterface>, référence const
	* @param carte2 : std::shared_ptr<CarteInterface>, référence const
	* @return bool : true or false
	*/
	bool FigureCarteEgal(const std::shared_ptr<CarteInterface>& carte1, const std::shared_ptr<CarteInterface>& carte2) { return carte1->ObtenirFigure() == carte2->ObtenirFigure(); }


	/*
	* Verifier score des joueurs
	*/
	bool VerifScore() override;

	/*
	* Affiche le vainceur de la partie
	*/
	void AfficherScore() override;

};

#endif
