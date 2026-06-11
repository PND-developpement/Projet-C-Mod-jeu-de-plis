#include "Interface.h"
#include <iostream>

void Interface::AfficherMainDuJoueur(const MainJoueur& mainJoueur) const {
    std::cout << "Votre main : \n";

    //on recupere la taille de la main
    size_t taille = mainJoueur.LireCartesMain()->ObtenirTaille();

    // boucle pour afficher chaque carte avec la bonne couleur
    for (size_t i = 0; i < taille; ++i) {
        auto c = mainJoueur.LireCartesMain()->ObtenirCarte(i);

        // On determine la couleur active
        std::string couleurActive = (c->ObtenirCouleur() == "Rouge") ? COULEUR_ROUGE : COULEUR_BLANCHE;

        // Affichage colore
        std::cout << i + 1 << ") ["
            << couleurActive << c->ObtenirValeur() << " de " << c->ObtenirFigure() << RESET_COULEUR
            << "]\n";
    }
    std::cout << std::endl;
}

int Interface::DemanderCarte(const MainJoueur& mainDuJoueur, std::string pseudo) const {
    int positionCarte = 0;
    size_t nbCartes = mainDuJoueur.LireCartesMain()->ObtenirTaille();

    AfficherPseudoJoueur(pseudo);

    AfficherMainDuJoueur(mainDuJoueur);

    while (true)
    {
        std::cout << "Quelle carte voulez-vous jouer ? (1 a " << nbCartes << ") : ";
        std::cin >> positionCarte;

        //on a mis une vérification pour vider le buffer en cas de faute de frappe
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Erreur : Entrez un chiffre." << std::endl;
        }
        else if (positionCarte < 1 || positionCarte > nbCartes) {
            std::cout << "Erreur : Numero invalide." << std::endl;
        }
        else {
            break; // saisie correcte
        }
    }

    //renvoie l'index memoire
    return positionCarte - 1;
}

void Interface::AfficherPseudoJoueur(const std::string& pseudoJoueur) const
{
    std::cout << "\n- - - AU TOUR DE : "
        << COULEUR_VIOLET
        << pseudoJoueur
        << RESET_COULEUR
        << " - - -" << std::endl;
}

void Interface::AfficherTable(const std::vector<std::shared_ptr<CarteInterface>>& cartes) const {
    std::cout << "\n- - - CARTES SUR LA TABLE - - -" << std::endl;

    if (cartes.empty()) {
        std::cout << "La table est vide." << std::endl;
    }
    else
    {
        for (auto carteEnCours = cartes.begin(); carteEnCours != cartes.end(); carteEnCours++)
        {
            //on applique la couleur sur la table
            std::string couleurActive = ((*carteEnCours)->ObtenirCouleur() == "Rouge") ? COULEUR_ROUGE : COULEUR_BLANCHE;

            std::cout << "["
                << couleurActive
                << (*carteEnCours)->ObtenirValeur() << " de " << (*carteEnCours)->ObtenirFigure()
                << RESET_COULEUR
                << "] ";
        }
        std::cout << std::endl;
    }
}

void Interface::AfficherMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

void Interface::AfficherGagnantPli(const std::string& nomGagnant) const {
    std::cout << "\n>> " << nomGagnant << " remporte ce pli !! <<" << std::endl;
    std::cout << "------------------------------------------\n" << std::endl;
}

void Interface::AfficherScores(const std::vector<std::string>& nomsJoueurs, const std::vector<int>& scores) const {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "             SCORES ACTUELS               " << std::endl;
    std::cout << "==========================================\n" << std::endl;

    for (size_t boucleNomJoueur = 0; boucleNomJoueur < nomsJoueurs.size(); ++boucleNomJoueur)
    {
        std::cout << nomsJoueurs[boucleNomJoueur] << " \t: " << scores[boucleNomJoueur] << " points" << std::endl;
    }
    std::cout << "==========================================\n" << std::endl;
}

void Interface::AfficherEcranNoir() const{
    size_t ecranNoir;
    for (ecranNoir = 0; ecranNoir < 30; ecranNoir++)
    {
        std::cout << std::endl;
    }
    
}

unsigned int Interface::DemanderScoreTotal() const
{
    unsigned int scoreTotal=0;
    std::cout << "Combien de points a marquer ? " << std::endl;
    std::cin >> scoreTotal;
    while (scoreTotal < 20 && scoreTotal>200) {
        if (scoreTotal < 20) {
            std::cout << "Score trop bas !" << std::endl;
            std::cout << "Entrer une nouvelle valeur :" << std::endl;
            std::cin >> scoreTotal;

        }
        if (scoreTotal > 200) {
            std::cout << "Score trop haut !" << std::endl;
            std::cout << "Entrer une nouvelle valeur :" << std::endl;
            std::cin >> scoreTotal;
        }
    }
    
    return scoreTotal;
}

unsigned int Interface::DemanderJeux() const
{
    unsigned int choix=1;
    std::cout << "\n==========================================" << std::endl;
    std::cout << "             JEUX DISPONIBLES               " << std::endl;
    std::cout << "==========================================\n" << std::endl;
    std::cout << "1: " << "Dame de Pique" << std::endl;
    std::cin >> choix;
    while (choix < 1 && choix>1) {
        std::cout << "Rentrer un numero de jeu valide : " << std::endl;
        std::cin >> choix;

    }
    return choix;
}
