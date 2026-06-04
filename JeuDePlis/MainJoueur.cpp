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

void MainJoueur::ModifierCartesMain(EnsembleDeCartes nouvellesCartesMain)
{
	CartesMain = move(nouvellesCartesMain);
}

void MainJoueur::AjouterCarteMain(shared_ptr<Carte> nouvelleCarte)
{
	CartesMain.AjouterCarte(nouvelleCarte);
}

void MainJoueur::SupprimerCarteMain(shared_ptr<Carte> carte)
{
	CartesMain.SupprimerCarte(carte);
}

bool MainJoueur::TrouverCarte(std::shared_ptr<Carte> carte)
{
    const auto& ensemble = CartesMain.GetensembleDeCarte();


    for (auto itCarte = ensemble.begin(); itCarte != ensemble.end(); itCarte++)
    {
		if (carte == *itCarte)
			return true;
    }

	return false;
}

void MainJoueur::AfficherMainJoueur() const
{

}