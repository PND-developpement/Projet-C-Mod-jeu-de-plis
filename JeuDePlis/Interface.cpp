#include "Interface.h"
#include <iostream>

int Interface::DemanderCarte(const MainJoueur& mainDuJoueur) const {
    int choix = 0;
    int nbCartes = mainDuJoueur.lireCartesMain().GetTaille();

    std::cout << "\n--- A VOTRE TOUR DE JOUER ---" << std::endl;
    AfficherMain(mainDuJoueur);

    while (true) {
        std::cout << "Quelle carte voulez-vous jouer ? (1 a " << nbCartes << ") : ";
        std::cin >> choix;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erreur : Entrez un chiffre." << std::endl;
        }
        else if (choix < 1 || choix > nbCartes) {
            std::cout << "Erreur : Numero invalide." << std::endl;
        }
        else {
            break;
        }
    }

    return choix - 1;
}

void Interface::AfficherMain(const MainJoueur& mainDuJoueur) const {
    std::cout << "Votre main : \n";
    int taille = mainDuJoueur.lireCartesMain().GetTaille();

    for (int i = 0; i < taille; ++i) {
        std::shared_ptr<Carte> c = mainDuJoueur.lireCartesMain().GetCarte(i);
        std::cout << i + 1 << ") [" << c->GetValeur() << " de " << c->GetFigure() << "]\n";
    }
    std::cout << std::endl;
}

void Interface::AfficherTable(const std::vector<std::shared_ptr<Carte>>& cartesAuMilieu) const {
    std::cout << "\n--- CARTES SUR LA TABLE ---" << std::endl;
    if (cartesAuMilieu.empty()) {
        std::cout << "La table est vide, c'est a vous d'ouvrir le pli." << std::endl;
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

void Interface::AfficherGagnantPli(const std::string& nomGagnant) const {
    std::cout << "\n>> " << nomGagnant << " remporte ce pli ! <<" << std::endl;
    std::cout << "------------------------------------------\n" << std::endl;
}

void Interface::AfficherScores(const std::vector<std::string>& nomsJoueurs, const std::vector<int>& scores) const {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "             SCORES ACTUELS               " << std::endl;
    std::cout << "==========================================\n" << std::endl;

    for (size_t i = 0; i < nomsJoueurs.size(); ++i) {
        //  le \t insère une tabulation classique pour espacer un peu
        std::cout << nomsJoueurs[i] << " \t: " << scores[i] << " points" << std::endl;
    }
    std::cout << "==========================================\n" << std::endl;
}