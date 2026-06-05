#include "EnsembleDeCartes.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>
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
		shared_ptr<Carte> carte = make_shared<Carte>(ensembleDeCarte[boucleAjout]);
		ensembleDeCarte.push_back(carte);
	}
}

EnsembleDeCartes::EnsembleDeCartes(EnsembleDeCartes&& ensemble2) noexcept{
	taille = ensemble2.taille;
	size_t boucleAjout;
	for (boucleAjout = 0; boucleAjout < taille; boucleAjout++) {
		shared_ptr<Carte> carte = make_shared<Carte>(ensembleDeCarte[boucleAjout]);
		ensembleDeCarte.push_back(carte);
	}
	ensemble2.~EnsembleDeCartes();
}

EnsembleDeCartes::~EnsembleDeCartes(){
	taille = 0;
	ensembleDeCarte.clear();
}

void EnsembleDeCartes::AjouterCarte(std::shared_ptr<Carte> carte){
	if (ensembleDeCarte.size() < taille) {
		ensembleDeCarte.push_back(carte);
	}
	else{
		throw invalid_argument("Ensemble plein");
	}
}

void EnsembleDeCartes::AjouterCarte(Carte& carte){
	if (ensembleDeCarte.size() < taille) {
		shared_ptr<Carte> ncarte = make_shared<Carte>(carte);
		ensembleDeCarte.push_back(ncarte);
	}
	else {
		throw invalid_argument("Ensemble plein");
	}
}

void EnsembleDeCartes::SupprimerCarte(std::shared_ptr<Carte> carteASupprimer){
	auto it = std::find(ensembleDeCarte.begin(), ensembleDeCarte.end(), carteASupprimer);
	if (it != ensembleDeCarte.end()) {
		ensembleDeCarte.erase(it);
	}
}

void EnsembleDeCartes::TrieCarte(std::string typedetrie){
	
}

void EnsembleDeCartes::MelangeAleatoireCarte(){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(ensembleDeCarte.begin(), ensembleDeCarte.end(), default_random_engine(seed));
}

std::shared_ptr<Carte> EnsembleDeCartes::GetCarte(unsigned int position) const 
{

	return ensembleDeCarte.at(position);
}

/*
* ********** autre méthode pour get carte
* méthode 1
Carte& EnsembleDeCartes::GetCarte(unsigned int position) const{
	Carte ncarte(ensembleDeCarte[position]);
	return ncarte;
}
* méthode 2 :
Carte& EnsembleDeCartes::getCarte(unsigned int position) const
{
	return *(ensembleDeCarte.at(position));
}
*/


/*
vector<const std::shared_ptr<Carte>> EnsembleDeCartes::GetensembleDeCarte() const{
	vector<const std::shared_ptr<Carte>> constensembleDeCarte;
	size_t boucleAjout;
	for ( boucleAjout = 0; boucleAjout < ensembleDeCarte.size(); boucleAjout++){
		shared_ptr<Carte> const carte = make_shared<Carte>(ensembleDeCarte[boucleAjout]);
		constensembleDeCarte.push_back(carte);
	}

	return constensembleDeCarte;
}
*/
void EnsembleDeCartes::AfficherCarte() const{
	// ajouter interface
}
