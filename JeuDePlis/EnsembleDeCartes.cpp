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

EnsembleDeCartes::EnsembleDeCartes(const EnsembleDeCartes& ensemble2) noexcept{
	taille = ensemble2.taille;
	size_t boucleAjout;
	for ( boucleAjout = 0; boucleAjout < ensemble2.ensembleDeCarte.size(); boucleAjout++){
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


void EnsembleDeCartes::SupprimerCarte(std::shared_ptr<CarteInterface> carteASupprimer){
	auto it = std::find(ensembleDeCarte.begin(), ensembleDeCarte.end(), carteASupprimer); //on cherche la carte a supprimé dans zl'ensemble de carte
	if (it != ensembleDeCarte.end()) { //si on la trouve, on la supprime puis on décrémente la taille
		ensembleDeCarte.erase(it);
	}
	taille--;
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

//Affiche l'ensemble de carte
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