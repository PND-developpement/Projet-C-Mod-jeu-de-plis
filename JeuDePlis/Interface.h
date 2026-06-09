#ifndef _INTERFACE_H__
#define _INTERFACE_H__

#include <memory>
#include <vector>
#include <string>
#include "Carte.h"
#include "MainJoueur.h"

class Interface {
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
};

#endif