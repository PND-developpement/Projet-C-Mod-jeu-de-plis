#ifndef H_PAR_H
#define H_PAR_H
#include "Joueur.h"
#include <vector>
#include <memory>
#include "JeuDeCarte.h"

class Partie{
protected:
	// Atribut 
	unsigned int nombreJoueur; 
	std::vector <std::unique_ptr <Joueur>> listeJoueur;
	std::unique_ptr<JeuDeCartes> pLeJeu;
	unsigned int scoreTotal;
public:
	// Constructeur et Destructeur
	/*
	* Destructeur par défaut
	*/
	~Partie() = default;

	// Methodes

	/*
	* Afficher dans la console les règles du jeu
	*/
	virtual void AfficherRegles() const = 0 ;

	/*
	* Crée le paquet de cartes et les joueurs
	*/
	virtual void InitaliserPartie() = 0;

	/*
	* Mélange le paquet de cartes et distribue aux joueurs leurs cartes
	*/
	virtual void DistribuerCartes() = 0;

	/*
	* permet de donner des cartes à un joueur
	* virtuelle pure car plusieurs jeux de plis sont amenés à donner des cartes (ex : papayoo, certaines versions de la belote)
	* @param interface : Interface, référence const
	*/
	virtual void DonnerCarte(const Interface& interface) = 0;

	/*
	* Lance la partie
	*/
	virtual void LancerPartie() = 0;

	/*
	* Jouer la partie
	* @param interface : Interface, référence const
	*/
	virtual void JouerPartie(const Interface& interface) = 0;

	/*
	* Permet de définir les cartes jouable dans la main du joueur en fonction des cartes en cours de jeu. 
	* Ensuite le joueur ou l'IA joue une carte valide
	* @param carteTable : vector <shared_ptr<CarteInterface>>
	* @param JoueurEnCours : unsigned int
	* @param interface : Interface, référence const
	*/
	virtual std::shared_ptr<CarteInterface> JouerCarte(std::vector<std::shared_ptr<CarteInterface>>& carteTable, unsigned int JoueurEnCours, const Interface& interface) = 0;

	/*
	* Verifier score des joueurs
	*/
	virtual bool VerifScore() = 0;

	/*
	* Affiche le vainceur de la partie
	*/
	virtual void AfficherScore() = 0;

	/*
	* Ajoute le score par celle mis en parametre
	* @param scoreTotal unsigned int
	*/
	void DefinirScoreTotal(unsigned int scoreTotal) { this->scoreTotal = scoreTotal; }

	/*
	* Ajoute le score par celle mis en parametre
	* @return scoreTotal
	*/
	unsigned int ObtenirScoreTotal() const { return scoreTotal; }

};
#endif