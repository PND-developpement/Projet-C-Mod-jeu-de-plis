#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "JeuDeCarte.h"
#include <memory>
#include <vector>
#include <string>


class PartieDameDePique : public Partie
{
private:
    std::unique_ptr<JeuDeCartes> pLeJeu;
    std::vector<std::string> vNomsJoueurs;

    //la partie possède et gère son propre paquet de cartes
    std::unique_ptr<JeuDeCartes> pLeJeu;

public:
    PartieDameDePique();
    ~PartieDameDePique() = default;

    void AfficherRegles() const;
    void InitaliserPartie();
    void DistribuerCartes();
    void LancerPartie();
};

#endif
