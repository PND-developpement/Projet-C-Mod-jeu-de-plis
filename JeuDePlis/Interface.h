#ifndef _INTERFACE_H__
#define _INTERFACE_H__

#include <memory>
#include <vector>
#include <string>
#include "Carte.h"
#include "MainJoueur.h"

class Interface {
private:
    //Codes pour les couleurs dansla console
    const std::string COULEUR_ROUGE = "\033[31m";
    const std::string COULEUR_BLANCHE = "\033[97m";
    const std::string RESET_COULEUR = "\033[0m";
public:
    Interface() = default;
    ~Interface() = default;

    // Affiche les cartes que le joueur a en main
    //void AfficherMainJoueur(const MainJoueur& mainDuJoueur) const;
    void AfficherMainDuJoueur(const MainJoueur& mainJoueur) const;

    // Demande à l'humain de jouer et renvoie l'index
    int DemanderCarte(const MainJoueur& mainDuJoueur) const;

    // Affiche les cartes actuellement posées au centre de la table
    void AfficherTable(const std::vector<std::shared_ptr<CarteInterface>>& cartes) const;

    // Affiche un message générique par ex "Début du tour 3"
    void AfficherMessage(const std::string& message) const;

    // Annonce qui a remporté le pli
    void AfficherGagnantPli(const std::string& nomGagnant) const;

    // Affiche le tableau des scores à la fin d'une manche
    void AfficherScores(const std::vector<std::string>& nomsJoueurs, const std::vector<int>& scores) const;

    // - - - - - - -  - -
    // Faire méthode écran noir
};

#endif