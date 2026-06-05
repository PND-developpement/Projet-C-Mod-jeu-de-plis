#include "Interface.h"
#include <iostream>

int Interface::DemanderCarte(const MainJoueur& mainDuJoueur) const {
    int choix = 0;
    int nbCartes = mainDuJoueur.lireCartesMain().GetTaille();

    std::cout << "\n--- A VOTRE TOUR DE JOUER ---" << std::endl;
    mainDuJoueur.AfficherMainJoueur();

    while (true) {
        std::cout << "Quelle carte voulez-vous jouer ? (1 a " << nbCartes << ") : ";
        std::cin >> choix;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); //au cas ou il y a des erreurs de frappe pour enlever tt ce qui peut poser probleme dans le buffer
            std::cout << "Erreur : Entrez un chiffre." << std::endl;
        }
        else if (choix < 1 || choix > nbCartes) {
            std::cout << "Erreur : Numero invalide." << std::endl;
        }
        else {
            break;
        }
    }

    return choix - 1;//pour avoir l'index exacte
}

void Interface::AfficherTable(const std::vector<std::shared_ptr<Carte>>& cartesAuMilieu) const {
    std::cout << "\n--- CARTES SUR LA TABLE ---" << std::endl;
    if (cartesAuMilieu.empty()) {
        std::cout << "La table est vide, vous ouvrez le pli." << std::endl;
    }
    else {
        for (const auto& carte : cartesAuMilieu) {
            std::cout << "[" << carte->GetValeur() << " de " << carte->GetFigure() << "] ";
        }
        std::cout << std::endl;
    }
}

void Interface::AfficherMessage(const std::string& message) const {
    std::cout << message << std::endl;
}