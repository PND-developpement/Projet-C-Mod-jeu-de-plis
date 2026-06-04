#include "PartieDameDePique.h"
#include <iostream>

PartieDameDePique::PartieDameDePique() : CPartie()
{
    pLeJeu = nullptr;
}

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
}