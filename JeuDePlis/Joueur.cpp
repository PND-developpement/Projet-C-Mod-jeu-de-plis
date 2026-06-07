#include "Joueur.h"
#include <utility>
#include <memory>
#include "EnsembleDeCartes.h"
#include "MainJoueur.h"
#include <string>
using namespace std;

//constructeurs et destructeurs
Joueur::Joueur()
{
	pseudo = "inconnu";
	score = 0;
}

Joueur::Joueur(const Joueur& rJoueur) noexcept
{
	pseudo = rJoueur.pseudo;
	score = rJoueur.score;
	cartes = make_unique<MainJoueur>(*rJoueur.cartes);
}

Joueur::Joueur(Joueur&& rJoueur) noexcept
{
	pseudo = move(rJoueur.pseudo);
	score = rJoueur.score;
	cartes = move(rJoueur.cartes);
}

Joueur::Joueur(string pseudo, int score, unique_ptr<MainJoueur> cartes)
{
	pseudo = move(pseudo);
	this->score = score;
	cartes = move(cartes);
}

Joueur::~Joueur(){}

//accesseurs
std::string Joueur::LirePseudo() const
{
	return pseudo; //On renvoie le pseudo du joueur
}

void Joueur::ModifierPseudo(std::string NouveauPseudo)
{
	pseudo = move(NouveauPseudo); //On modifie le pseudo
}

int Joueur::LireScore() const
{
	return score;
}

void Joueur::ModifierScore(int NouveauScore)
{
	score = NouveauScore;
}

MainJoueur* Joueur::LireCartes() const
{
	return cartes.get();
}

void Joueur::ModifierCartes(std::unique_ptr<MainJoueur> nouvellesCartes){
	cartes = move(nouvellesCartes); //On modifie la main du joueur
}



void Joueur::AfficherMainDuJoueur() const
{
	cartes->AfficherMainJoueur();
}