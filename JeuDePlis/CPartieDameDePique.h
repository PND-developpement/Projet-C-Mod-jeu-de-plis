#ifndef _C_PARTIE_DAME_DE_PIQUE_H__
#define _C_PARTIE_DAME_DE_PIQUE_H__

#include "CPartie.h"
#include "CJeuDeCartes.h"
#include <memory>

class CPartieDameDePique : public CPartie
{
private:
    //la partie possède et gère son propre paquet de cartes
    std::unique_ptr<CJeuDeCartes> pLeJeu;

public:
    CPartieDameDePique();
    ~CPartieDameDePique() = default;

    void InitialiserLaPartie();
};

#endif#pragma once
