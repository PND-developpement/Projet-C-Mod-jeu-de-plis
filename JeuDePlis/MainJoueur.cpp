#include "MainJoueur.h"
#include <utility>
using namespace std;


MainJoueur::MainJoueur() {}

MainJoueur::MainJoueur(const EnsembleDeCartes& CopieCartesMain) : CartesMain(CopieCartesMain) {}

MainJoueur::MainJoueur(EnsembleDeCartes&& CopieCartesMain) : CartesMain(move(CopieCartesMain)) {}

MainJoueur::~MainJoueur() {}

EnsembleDeCartes MainJoueur::lireCartesMain() const
{
	return CartesMain;
}

void MainJoueur::modifierCartesMain(EnsembleDeCartes nouvellesCartesMain)
{
	CartesMain = move(nouvellesCartesMain);
}

void MainJoueur::AjouterCarteMain(shared_ptr<Carte> nouvelleCarte)
{
	CartesMain.ajouterCarte(nouvelleCarte);
}

void MainJoueur::SupprimerCarteMain(shared_ptr<Carte> carte)
{
	CartesMain.supprimerCarte(carte);
}

bool MainJoueur::TrouverCarte(std::shared_ptr<Carte> carte)
{
    const auto& ensemble = CartesMain.getensembleDeCarte();


    for (auto itCarte = ensemble.begin(); itCarte != ensemble.end(); itCarte++)
    {
		if (carte == *itCarte)
			return true;
    }

	return false;
}

void MainJoueur::afficherMainJoueur() const
{

}