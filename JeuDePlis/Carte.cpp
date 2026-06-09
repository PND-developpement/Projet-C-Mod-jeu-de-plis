#include "Carte.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

Carte::Carte(){
	valeur = 'rien';
	figure = 'rien';
	couleur = 'rien';
}

Carte::Carte(const Carte& carte2) noexcept{
	valeur = carte2.valeur;
	figure = carte2.figure;
	couleur = carte2.couleur;
}

Carte::Carte(Carte&& carte2) noexcept{
	valeur = carte2.valeur;
	figure = carte2.figure;
	couleur = carte2.couleur;
}

Carte::Carte(shared_ptr<Carte> carte2) noexcept{
	valeur = carte2->valeur;
	figure = carte2->figure;
	couleur = carte2->couleur;

}

Carte::Carte(string valeur, string figure, string couleur) : valeur(valeur),figure(figure),couleur(couleur){
}

Carte::~Carte(){
}

int Carte::ObtenirScoreCarte()
{
	return 0;
}

void Carte::AfficherCarte() const
{
	cout  << "Carte : " << ObtenirValeur() << " de " << ObtenirFigure() << endl;
}
