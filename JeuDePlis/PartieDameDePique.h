#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"

class PartieDameDePique : public Partie{
public:
    PartieDameDePique();
    ~PartieDameDePique() = default;

    void AfficherRegles() const;
    void InitaliserPartie();
    void DistribuerCartes();
    void LancerPartie();
};

#endif
