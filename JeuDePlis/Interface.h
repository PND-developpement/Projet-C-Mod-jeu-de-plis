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

    // Renvoie l'index de la carte choisie
    int DemanderCarte(const MainJoueur& mainDuJoueur) const;

    void AfficherTable(const std::vector<std::shared_ptr<Carte>>& cartesAuMilieu) const;
    void AfficherMessage(const std::string& message) const;
};

#endif