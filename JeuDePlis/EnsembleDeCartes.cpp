#include "EnsembleDeCartes.h"
#include "CarteInterface.h"
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>
#include <utility>
#include <iostream>

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
		ensembleDeCarte.push_back(ensemble2.ensembleDeCarte[boucleAjout]);
	}
}

EnsembleDeCartes::EnsembleDeCartes(EnsembleDeCartes&& ensemble2) noexcept : taille(ensemble2.taille),ensembleDeCarte(move(ensemble2.ensembleDeCarte)){
}

void EnsembleDeCartes::AjouterCarte(std::shared_ptr<CarteInterface> carte){
	if (ensembleDeCarte.size() < taille) {
		ensembleDeCarte.push_back(carte);
	}
	else{
		throw invalid_argument("Ensemble plein");
	}
}

/*
void EnsembleDeCartes::AjouterCarte(CarteInterface& carte){
	if (ensembleDeCarte.size() < taille) {
		shared_ptr<CarteInterface> ncarte = make_shared<CarteInterface>(carte);
		ensembleDeCarte.push_back(ncarte);
	}
	else {
		throw invalid_argument("Ensemble plein");
	}
}
*/

void EnsembleDeCartes::SupprimerCarte(std::shared_ptr<CarteInterface> carteASupprimer){
	auto it = std::find(ensembleDeCarte.begin(), ensembleDeCarte.end(), carteASupprimer);
	if (it != ensembleDeCarte.end()) {
		ensembleDeCarte.erase(it);
	}
	taille--;
}

void EnsembleDeCartes::TrieCarte(std::string typedetrie){
	
}

void EnsembleDeCartes::MelangeAleatoireCarte() {
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 rng(seed); // Permet le melange des cartes aleatoirement
	shuffle(ensembleDeCarte.begin(), ensembleDeCarte.end(), rng);
}

std::shared_ptr<CarteInterface> EnsembleDeCartes::ObtenirCarte(unsigned int position) const
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
void EnsembleDeCartes::AfficherEnsembleDeCarte() const
{
	for (int positionCarte = 0; positionCarte < ensembleDeCarte.size(); ++positionCarte)
	{
		std::shared_ptr<CarteInterface> carteJoueur = ObtenirCarte(positionCarte);
		cout << "(" << positionCarte << ")";
		carteJoueur->AfficherCarte();
		cout << endl;
	}
	cout << endl;
}