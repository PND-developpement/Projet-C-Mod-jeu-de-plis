#include "EnsembleDeCartes.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;
EnsembleDeCartes::EnsembleDeCartes(){
	taille = 0;
}

EnsembleDeCartes::EnsembleDeCartes(size_t taille) : taille(taille){
}

EnsembleDeCartes::EnsembleDeCartes(const EnsembleDeCartes& ensemble2) noexcept{
	taille = ensemble2.taille;
	size_t boucleAjout;
	for ( boucleAjout = 0; boucleAjout < taille; boucleAjout++){
		shared_ptr<Carte> carte = make_unique<Carte>(ensembleDeCarte[boucleAjout]);
		ensembleDeCarte.push_back(carte);
	}
}

EnsembleDeCartes::EnsembleDeCartes(const EnsembleDeCartes&& ensemble2) noexcept{
	taille = ensemble2.taille;
	size_t boucleAjout;
	for (boucleAjout = 0; boucleAjout < taille; boucleAjout++) {
		shared_ptr<Carte> carte = make_unique<Carte>(ensembleDeCarte[boucleAjout]);
		ensembleDeCarte.push_back(carte);
	}
	ensemble2.~EnsembleDeCartes();
}

EnsembleDeCartes::~EnsembleDeCartes(){
	taille = 0;
	ensembleDeCarte.clear();
}

void EnsembleDeCartes::ajouterCarte(std::shared_ptr<Carte> carte){
	if (ensembleDeCarte.size() < taille) {
		ensembleDeCarte.push_back(carte);
	}
	else{
		throw invalid_argument("Ensemble plein");
	}
}

void EnsembleDeCartes::ajouterCarte(Carte& carte){
	if (ensembleDeCarte.size() < taille) {
		shared_ptr<Carte> ncarte = make_unique<Carte>(carte);
		ensembleDeCarte.push_back(ncarte);
	}
	else {
		throw invalid_argument("Ensemble plein");
	}
}

void EnsembleDeCartes::supprimerCarte(){
	ensembleDeCarte.pop_back();
}

void EnsembleDeCartes::trieCarte(std::string typedetrie){
	
}

void EnsembleDeCartes::melangeAleatoireCarte(){
	
}

Carte& EnsembleDeCartes::getCarte(unsigned int position) const{
	Carte ncarte(ensembleDeCarte[position]);
	return ncarte;
}

std::vector<const std::shared_ptr<Carte>> EnsembleDeCartes::getensembleDeCarte() const{
	return std::vector<const std::shared_ptr<Carte>>();
}

void EnsembleDeCartes::afficherCarte(){
	// ajouter interface
}
