#include "MainJoueur.h"
#include <utility>
#include <stdexcept>
#include <memory>
#include <string>

using namespace std;

//COnstructeurs et destructeurs
MainJoueur::MainJoueur() {
	taille = 0;
	CartesMain = make_unique<EnsembleDeCartes>();
}

MainJoueur::MainJoueur(const MainJoueur& CopieCartesMain) : taille(CopieCartesMain.taille){
	CartesMain = make_unique<EnsembleDeCartes>(*CopieCartesMain.CartesMain);
}

MainJoueur::MainJoueur(MainJoueur&& CopieCartesMain) : taille(CopieCartesMain.taille),CartesMain(move(CopieCartesMain.CartesMain)) {
	CopieCartesMain.taille = 0;
}

MainJoueur::~MainJoueur() {}

//accesseurs
EnsembleDeCartes* MainJoueur::LireCartesMain() const
{
	return CartesMain.get(); //On renvoie la main du joueur
}

void MainJoueur::ModifierCartesMain(EnsembleDeCartes nouvellesCartesMain)
{
	CartesMain = make_unique<EnsembleDeCartes>(move(nouvellesCartesMain)); //On modifie la valeur
}

void MainJoueur::AjouterCarteMain(shared_ptr<CarteInterface> nouvelleCarte)
{
	//On vérifie que la carte en paramètre ne soit pas null
	if (nouvelleCarte == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul");

	//On vérifie qu'elle ne soit pas déjà présente dans la main du joueur
	if (TrouverCarte(nouvelleCarte))
		throw std::logic_error("Carte déjà présente dans la main du joueur");
	CartesMain->AjouterCarte(nouvelleCarte); //On l'ajoute à la main
}

void MainJoueur::SupprimerCarteMain(shared_ptr<CarteInterface> carte)
{
	//On vérifie que la carte en paramètre ne soit pas null
	if (carte == nullptr)
		throw std::invalid_argument("Erreur : pointeur est nul");

	//On vérifie qu'elle soit présente dans la main du joueur
	if (!TrouverCarte(carte))
		throw std::logic_error("Carte déjà présente dans la main du joueur");

	CartesMain->SupprimerCarte(carte); //On la supprime de la main
}

bool MainJoueur::TrouverCarte(std::shared_ptr<CarteInterface> carte)
{
    const auto& ensemble = CartesMain->ObtenirEnsembleDeCarte();

	//Boucle permettant de rechercher la carte dans la main du joueur avec un itérateur
    for (auto itCarte = ensemble.begin(); itCarte != ensemble.end(); itCarte++)
    {
		if (carte == *itCarte)
			return true;
    }

	return false; //On renvoie "false" si la carte n'est as présente dans la main.
}

bool MainJoueur::TrouverCarte(string valeur, string figure)
{
	bool trouver = false;
	const auto& ensemble = CartesMain->ObtenirEnsembleDeCarte();

	//Boucle permettant de rechercher la carte dans la main du joueur avec un itérateur
	for (auto itCarte = ensemble.begin(); itCarte != ensemble.end(); itCarte++)
	{
		if (valeur == itCarte->get()->ObtenirValeur() && figure == itCarte->get()->ObtenirFigure()) {
			trouver = true;
		}
			
	}
	return trouver;
}

std::shared_ptr<CarteInterface> MainJoueur::ObtenirCarte(int positionCarte)
{
	return CartesMain->ObtenirEnsembleDeCarte().at(positionCarte); //On renvoie la carte à la position donnée en paramètre de la fonction dans la main du joueur
} //utilisé la méthode "GetCarte(unsigned int position)" de la classe ENsembleDeCartes ! 

void MainJoueur::AfficherMainJoueur() const
{
	CartesMain->AfficherEnsembleDeCarte();
}