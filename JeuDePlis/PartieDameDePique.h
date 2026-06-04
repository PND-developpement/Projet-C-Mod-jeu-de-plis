#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "JeuDeCartes.h"
#include <memory>
#include <vector>
#include <string>

class PartieDameDePique : public Partie
{
private:
    std::unique_ptr<JeuDeCartes> pLeJeu;
    std::vector<std::string> vNomsJoueurs;

public:
    PartieDameDePique();
    ~PartieDameDePique() = default;

    void AfficherRegles() const;
    void InitialiserLaPartie();
    void DistribuerCartes();
    void LancerPartie();
};

#endif