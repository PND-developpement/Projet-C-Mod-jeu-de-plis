#include "PartieDameDePique.h"
#include <iostream>

<<<<<<< HEAD
PartieDameDePique::PartieDameDePique() : Partie()
=======
PartieDameDePique::PartieDameDePique() : CPartie()
>>>>>>> d9376c345bdeba0df2ef8ff52b9078a5bf11f28c
{
    pLeJeu = nullptr;
}

<<<<<<< HEAD
void PartieDameDePique::AfficherRegles() const
{
    std::cout << "\n=================================================" << std::endl;
    std::cout << "           JEU DE LA DAME DE PIQUE          " << std::endl;
    std::cout << "=================================================\n" << std::endl;
    std::cout << "CONSIGNES DU JEU :" << std::endl;
    std::cout << "- Le jeu se joue a 4 joueurs avec 52 cartes." << std::endl;
    std::cout << "- Le but est de marquer le MOINS de points possible." << std::endl;
    std::cout << "- Chaque carte de Coeur vaut 1 point." << std::endl;
    std::cout << "- La terrible Dame de Pique vaut 13 points !!!" << std::endl;
    std::cout << "- Le joueur qui a le 2 de Trefle commence le premier pli.\n" << std::endl;
    std::cout << "Appuyez sur Entree pour commencer la partie..." << std::endl;
    std::cin.get();
}

void PartieDameDePique::InitialiserLaPartie()
{
    // Inscription des joueurs à la table
    vNomsJoueurs = { "Axel", "Victoire", "Chloé", "Lucie" };

    std::cout << "Joueurs inscrits : ";
    for (const auto& nom : vNomsJoueurs) {
        std::cout << nom << " ";
    }
    std::cout << "\n\n";

    // Utilisation du vocabulaire exact : "figures" (Pique, Coeur...) et "valeurs" (2, 3...)
    std::vector<std::string> figures = { "Pique", "Coeur", "Carreau", "Trefle" };
    std::vector<std::string> valeurs = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi", "As" };

    // L'usine se charge de déduire la couleur physique (Rouge/Noir) toute seule
    pLeJeu = JeuDeCartes::CreerJeuSurMesure(figures, valeurs, 0);
}

void PartieDameDePique::DistribuerCartes()
{
    if (pLeJeu == nullptr) {
        std::cerr << "Erreur : Impossible de distribuer, le jeu n'est pas initialise." << std::endl;
        return;
    }

    std::cout << "Melange des cartes en cours..." << std::endl;
    // pLeJeu->ObtenirEnsemble()->Melanger();

    std::cout << "Distribution de 13 cartes a chaque joueur..." << std::endl;
}

void PartieDameDePique::LancerPartie()
{
    AfficherRegles();
    InitialiserLaPartie();
    DistribuerCartes();

    std::cout << "\nLa partie commence !" << std::endl;
=======
void PartieDameDePique::InitialiserLaPartie()
{
    // regles specifiques de la Dame de Pique (52 cartes)
    std::vector<std::string> couleurs = { "Pique", "Coeur", "Carreau", "Trefle" };
    std::vector<std::string> valeurs = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi", "As" };

    //generation du paquet grace a CJeuDeCartes
    pLeJeu = JeuDeCarte::CreerJeuSurMesure(couleurs, valeurs, 0);

    if (pLeJeu != nullptr)
    {
        std::cout << "La partie de Dame de Pique est initialisee (52 cartes prêtes)." << std::endl;
    }
    else
    {
        std::cerr << "Echec de l'initialisation du jeu." << std::endl;
    }

    //(A implémenter PLUS TARD)!!!!! : Melange et distribution aux joueurs via pLeJeu->ObtenirEnsemble()
>>>>>>> d9376c345bdeba0df2ef8ff52b9078a5bf11f28c
}