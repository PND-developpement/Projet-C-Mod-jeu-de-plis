#include "Joueur.h"
#include <utility>
using namespace std;

//constructeurs et destructeurs
Joueur::Joueur()
{
	pseudo = "inconnu";
	score = 0;
}

Joueur::Joueur(const Joueur& rJoueur)
{
	pseudo = rJoueur.pseudo;
	score = rJoueur.score;
	cartes = rJoueur.cartes;
}

Joueur::Joueur(Joueur&& rJoueur) noexcept
{
	pseudo = move(rJoueur.pseudo);
	score = rJoueur.score;
	cartes = move(rJoueur.cartes);
}

Joueur::Joueur(std::string pseudo, int score, MainJoueur cartes)
{
	pseudo = move(pseudo);
	score = score;
	cartes = move(cartes);
}

Joueur::~Joueur(){}

//accesseurs
std::string Joueur::LirePseudo() const
{
	return pseudo;
}

void Joueur::ModifierPseudo(std::string NouveauPseudo)
{
	pseudo = move(NouveauPseudo);
}

int Joueur::LireScore() const
{
	return score;
}

void Joueur::ModifierScore(int NouveauScore)
{
	score = NouveauScore;
}

MainJoueur Joueur::LireCartes() const
{
	return cartes;
}

void Joueur::ModifierCartes(MainJoueur nouvellesCartes)
{
	cartes = move(nouvellesCartes);
}