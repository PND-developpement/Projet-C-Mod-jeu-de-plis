#ifndef _C_PARTIE_DAME_DE_PIQUE_H__
#define _C_PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "JeuDeCarte.h"
#include <memory>

class PartieDameDePique : public Partie
{
private:
    //la partie possède et gère son propre paquet de cartes
    std::unique_ptr<JeuDeCarte> pLeJeu;

public:
    PartieDameDePique();
    ~PartieDameDePique() = default;

    void InitialiserLaPartie();
};

#endif
