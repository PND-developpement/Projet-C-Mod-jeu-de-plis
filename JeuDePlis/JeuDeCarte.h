#ifndef _JEU_DE_CARTES_H__
#define _JEU_DE_CARTES_H__

#include <vector>
#include <string>
#include <memory>

#include "EnsembleDeCartes.h"
#include "Carte.h"

class JeuDeCartes
{
private:
    std::unique_ptr<EnsembleDeCartes> pEnsembleCartes;

    JeuDeCartes();

public:
    ~JeuDeCartes() = default;

    // On utilise vFigures (Pique, Coeur, Carreau et Trefle) et vValeurs (As, 10, etc)
    static std::unique_ptr<JeuDeCartes> CreerJeuSurMesure(
        const std::vector<std::string>& vFigures,
        const std::vector<std::string>& vValeurs,
        unsigned int uiNbJokers = 0);

    EnsembleDeCartes* ObtenirEnsemble() const;
};

#endif