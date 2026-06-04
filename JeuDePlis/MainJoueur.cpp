#include "MainJoueur.h"
#include <utility>
#include <stdexcept>
using namespace std;

//COnstructeurs et destructeurs
MainJoueur::MainJoueur() {}

MainJoueur::MainJoueur(const EnsembleDeCartes& CopieCartesMain) : CartesMain(CopieCartesMain) {}

MainJoueur::MainJoueur(EnsembleDeCartes&& CopieCartesMain) : CartesMain(move(CopieCartesMain)) {}

MainJoueur::~MainJoueur() {}

//accesseurs
EnsembleDeCartes MainJoueur::lireCartesMain() const
{
	return CartesMain; //On renvoie la main du joueur
}

void MainJoueur::ModifierCartesMain(EnsembleDeCartes nouvellesCartesMain)
{
	CartesMain = move(nouvellesCartesMain); //On modifie la valeur
}

void MainJoueur::AjouterCarteMain(shared_ptr<Carte> nouvelleCarte)
{
	//On vérifie que la carte en paramètre ne soit pas null
	if (nouvelleCarte == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul");

	//On vérifie qu'elle ne soit pas déjà présente dans la main du joueur
	if (TrouverCarte)
		throw std::logic_error("Carte déjà présente dans la main du joueur");

	CartesMain.ajouterCarte(nouvelleCarte); //On l'ajoute à la main
	CartesMain.AjouterCarte(nouvelleCarte);
}

void MainJoueur::SupprimerCarteMain(shared_ptr<Carte> carte)
{
	//On vérifie que la carte en paramètre ne soit pas null
	if (carte == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul");

	//On vérifie qu'elle soit présente dans la main du joueur
	if (!TrouverCarte)
		throw std::logic_error("Carte déjà présente dans la main du joueur");

	CartesMain.SupprimerCarte(carte); //On la supprime de la main
}

bool MainJoueur::TrouverCarte(std::shared_ptr<Carte> carte)
{
    const auto& ensemble = CartesMain.GetensembleDeCarte();

	//Boucle permettant de rechercher la carte dans la main du joueur avec un itérateur
    for (auto itCarte = ensemble.begin(); itCarte != ensemble.end(); itCarte++)
    {
		if (carte == *itCarte)
			return true;
    }

	return false; //On renvoie "false" si la carte n'est as présente dans la main.
}

std::shared_ptr<Carte> MainJoueur::ObtenirCarte(int positionCarte)
{
	return CartesMain.GetensembleDeCarte().at(positionCarte); //On renvoie la carte à la position donnée en paramètre de la fonction dans la main du joueur
}

void MainJoueur::AfficherMainJoueur() const
{
	CartesMain.AfficherCarte();
}