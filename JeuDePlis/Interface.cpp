#include "Interface.h"
#include <iostream>

/*void Interface::AfficherMainJoueur(const MainJoueur& mainDuJoueur) const
{
    size_t nbCartesMainJoueur = mainDuJoueur.lireCartesMain()->GetTaille();

    std::cout << "Votre main : \n";

    for (int positionCarte = 0; positionCarte < nbCartesMainJoueur; ++positionCarte)
    {
        std::shared_ptr<CarteInterface> carteJoueur = mainDuJoueur.lireCartesMain()->GetCarte(positionCarte);
        std::cout << "(" << positionCarte + 1 << ") [" << carteJoueur->GetValeur() << " de " << carteJoueur->GetFigure() << "]\n";
    }
    std::cout << std::endl;
}
*/
void Interface::AfficherCarte(std::vector<std::shared_ptr<CarteInterface>> ensembleCarte)
{
    size_t nbCartesMainJoueur = ensembleCarte->GetTaille();

    std::cout << "Votre main : \n";

    for (int positionCarte = 0; positionCarte < nbCartesMainJoueur; ++positionCarte)
    {
        std::shared_ptr<CarteInterface> carteJoueur = mainDuJoueur.lireCartesMain()->GetCarte(positionCarte);
        std::cout << "(" << positionCarte + 1 << ") [" << carteJoueur->GetValeur() << " de " << carteJoueur->GetFigure() << "]\n";
    }
    std::cout << std::endl;
}

int Interface::DemanderCarte(const MainJoueur& mainDuJoueur) const {
    int positionCarte = 0;
    size_t nbCartes = mainDuJoueur.lireCartesMain()->GetTaille();

    std::cout << "\n- - - A VOTRE TOUR DE JOUER - - -" << std::endl;
    AfficherMainJoueur(mainDuJoueur);

    while (true) 
    {
        std::cout << "Quelle carte voulez-vous jouer ? (1 a " << nbCartes << ") : ";
        std::cin >> positionCarte;

        if (std::cin.fail()) {
            //std::cin.clear();
            //std::cin.ignore(10000, '\n');
            std::cout << "Erreur : Entrez un chiffre." << std::endl;
        }
        else if (positionCarte < 1 || positionCarte > nbCartes) {
            std::cout << "Erreur : Numero invalide." << std::endl;
        }
        else {
            break;
        }
    }

    return positionCarte - 1;
}

void Interface::AfficherTable(const std::vector<std::shared_ptr<CarteInterface>>& cartes) const 
{
    std::cout << "\n- - - CARTES SUR LA TABLE - - -" << std::endl;

    if (cartes.empty())
        std::cout << "La table est vide." << std::endl;
    else 
    {
        for (auto carteEnCours = cartes.begin(); carteEnCours != cartes.end(); carteEnCours++)
            std::cout << "[" << (*carteEnCours)->GetValeur() << " de " << (*carteEnCours)->GetFigure() << "] ";
        std::cout << std::endl;
    }
}

void Interface::AfficherMessage(const std::string& message) const { std::cout << message << std::endl;}

void Interface::AfficherGagnantPli(const std::string& nomGagnant) const 
{
    std::cout << "\n>> " << nomGagnant << " remporte ce pli ! <<" << std::endl;
    std::cout << "------------------------------------------\n" << std::endl;
}

void Interface::AfficherScores(const std::vector<std::string>& nomsJoueurs, const std::vector<int>& scores) const {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "             SCORES ACTUELS               " << std::endl;
    std::cout << "==========================================\n" << std::endl;

    for (size_t boucleNomJoueur = 0; boucleNomJoueur < nomsJoueurs.size(); ++boucleNomJoueur)
    {
        //  le \t insère une tabulation classique pour espacer un peu
        std::cout << nomsJoueurs[boucleNomJoueur] << " \t: " << scores[boucleNomJoueur] << " points" << std::endl;
    }
    std::cout << "==========================================\n" << std::endl;
}
